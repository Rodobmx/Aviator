// SPACE INVADER
// Version 0.0.0
// LEMOINE NICOLAS
// SAVOURET RODOLPHE

#include "space_invader.h"


unsigned int background_color = BLUE;

unsigned int avion_xbase=60;
unsigned int avion_ybase=111;
//extern unsigned int SPACE_avion[15][20];

unsigned int SPACE_avion[AVION_Y_LENGTH][AVION_X_LENGTH]=
{	RED,RED,RED,RED,RED,RED,RED,RED,RED,RED,RED,RED,RED,RED,RED, // ->>>>> y
	BLUE,BLUE,BLUE,BLUE,BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,BLUE,BLUE,BLUE,BLUE,
	BLUE,BLUE,BLUE,BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,BLUE,BLUE,BLUE,
	BLUE,BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,BLUE,
	BLUE,BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,BLUE,
	BLUE,BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,BLUE,
	BLUE,BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,BLUE,
	BLUE,BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,BLUE,
	BLUE,BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,BLUE,
	BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,
	BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,
	BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,
	BLUE,BLUE,BLUE,BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,BLUE,BLUE,BLUE,
	BLUE,BLUE,BLUE,BLUE,BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,BLUE,BLUE,BLUE,
	BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,BLUE,
	BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,YELLOW,YELLOW,YELLOW,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,
	BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,YELLOW,YELLOW,YELLOW,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,
	BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,YELLOW,YELLOW,YELLOW,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,
	BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,YELLOW,YELLOW,YELLOW,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,
	BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,YELLOW,YELLOW,YELLOW,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE};

void init_SPACE_INVADER()
{
    LCD_Init();
    LCD_Fill(BLUE);
    initTimer();
	initJoystick();
    
}

void afficher_avion(unsigned int xbase, unsigned int ybase)
{
  unsigned char y,x;
 
  for(x=0; x<15; x++)
    for(y=0; y<20; y++)
      LCD_SetPixel(ybase+y,xbase+AVION_X_LENGTH,SPACE_avion[x][y]);
}

void decaler_avion(JOYSTICK_POS pos)
{
  unsigned char y,x;
 
  switch(pos)
    {
      case J_LEFT:
        // Effacement pixel plus utilisé
        if(avion_xbase>=4)
        {
          for(x=avion_xbase+AVION_X_LENGTH; x>avion_xbase+AVION_X_LENGTH-AVION_SPEED; x--)
            for(y=avion_ybase; y<avion_ybase+AVION_Y_LENGTH; y++)
                LCD_SetPixel(y,x,background_color);
          
          avion_xbase-=AVION_SPEED;
          for(x=0; x<15; x++)
            for(y=0; y<20; y++)
              LCD_SetPixel(avion_ybase+y,avion_xbase+x,SPACE_avion[y][x]);
        }
        break;
        
      case J_RIGHT:
        // Effacement pixel plus utilisé
        if(avion_xbase+AVION_X_LENGTH <= 126)
        {
          for(x=avion_xbase; x<avion_xbase+AVION_SPEED; x++)
            for(y=avion_ybase; y<avion_ybase+AVION_Y_LENGTH; y++)
                LCD_SetPixel(y,x,background_color);
          
          avion_xbase+=AVION_SPEED;
          for(x=0; x<15; x++)
            for(y=0; y<20; y++)
              LCD_SetPixel(avion_ybase+y,avion_xbase+x,SPACE_avion[y][x]);
        }
        break;
    }
  
  
  for(x=0; x<15; x++)
    for(y=0; y<20; y++)
      LCD_SetPixel(avion_ybase+y,x+avion_xbase,SPACE_avion[x][y]);
  
}





// Timer A0 interrupt
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void) // Fonction d'interruption sur le timer
{ 
    JOYSTICK_POS pos;  
    pos = GetJoystickPosition();
    decaler_avion(pos);
    
}

// Initialisation du timer
void initTimer()
{   
  CCR0 = 32768/5 -1;
  CCTL1 = OUTMOD_7; // CCR1 reset/set
 //CCR1 = CCR0; // CCR1 PWM duty cycle
  TACTL = TASSEL_2 + MC_1;                  // ACLK, upmode
  TA0CCTL0 = CCIE;
  __bis_SR_register(GIE);
}