/*==================================================================================================
Revision History:
                            Modification       Rev.
Author                       Date D/M/Y       Number    Description of Changes
-------------------------   ------------    ----------  -------------------------------------------
N.LEMOINE
R.SAVOURET                                    				Initial version of the file.

==================================================================================================*/



/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "..\header\aviator.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define DELAY_NOUVEAU_METEOR 10

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/*
unsigned int background_color = BLUE;
*/
extern int avion_xbase;
extern int avion_ybase;

unsigned int score=0, vie;
unsigned char score_tab[5] = {'0'};
extern S_METEORE meteore[NB_METEORE_MAX];
extern S_BALLE balles[BALLES_MAX];
extern S_MISSILE missiles[MISSILES_MAX];

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
// Timer A0 interrupt
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void) // Fonction d'interruption sur le timer
{ 
    static int ticks_meteore=0;

    if(vie > 0)
    {
    //décalage du joueur
    JOYSTICK_POS pos;  
    pos = GetJoystickPosition();
    decaler_avion(pos);

    //calcul des positions
    avanceMeteore();
    avanceMissile();
    avanceBalles();

    ticks_meteore++;
    if (ticks_meteore >= DELAY_NOUVEAU_METEOR)
    {
      addMeteore();
      ticks_meteore = 0;
    }
    
    checkCollision();
    
    afficher_meteore();
    afficherMissile();
    afficherBalles();
    
    afficher_avion();
    //LCD_PutStr("SCORE :", 120, 10, 10, YELLOW, BLACK);
    }
    else
    {
      itoa(score_tab, score, 5,10);
      LCD_PutStr("GAME OVER !" , 20, 20, 2, YELLOW, BLACK);
      LCD_PutStr(score_tab,50,20, 2,YELLOW,BLACK);
      while((P1IN & BIT6) != 0);
      vie = 5;
      score = 0;
      LCD_Fill(BLUE);
    }
}

#pragma vector=PORT1_VECTOR
__interrupt void Port1(void)
{
  //bouton A
  if( (P1IFG | BIT6) == P1IFG)
  {
    addMissile(avion_xbase,avion_ybase);
  }
    
  //bouton B
  if( (P1IFG | BIT7) == P1IFG)
  {
    addBalle(avion_xbase+AVION_X_LENGTH-DECALLAGE_ARME-1,avion_ybase);
    addBalle(avion_xbase+DECALLAGE_ARME,avion_ybase);
  }
  //raz du flag
  P1IFG &= ~(BIT6+BIT7);
}

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


void init_aviator()
{
    LCD_Init();
    LCD_Fill(BLUE);
    
    initTimer();    
    initMeteor();
    vie = 5;
    score = 0;
}

// Initialisation du timer
void initTimer()
{   
  CCR0 = 50000;
 
  TACTL = ID_3 + TASSEL_2 + MC_1;                  // divider 8, ACLK, upmode
  TA0CCTL0 = CCIE;
  __bis_SR_register(GIE);
}

void checkCollision()
{
  unsigned int i,j;
  for(i = 0; i<NB_METEORE_MAX; i++)
  {
    // Collision avec l'avion
    if(meteore[i].y > (LCD_HEIGHT-AVION_Y_LENGTH)&&(meteore[i].state == EXIST))
      if((meteore[i].x > avion_xbase) && (meteore[i].x < (avion_xbase+AVION_X_LENGTH)))
      {
        detruireMeteore(i);
        vie--;
      }
    
    // Collision avec missile
    for(j=0; j<MISSILES_MAX; j++)
    {
      if(((missiles[j].x+MISSILE_X_LENGTH) >= meteore[i].x) && 
         (missiles[j].x <= (meteore[i].x+METEORE_X_LENGTH)) && 
         (missiles[j].etat == EXIST) &&
         (missiles[j].y < (meteore[i].y+METEORE_Y_LENGTH)))
      {
        detruireMeteore(i);
        detruireMissile(j);
        score += 10;
      }
    }
    
    // Collision avec balle
    for(j=0; j<BALLES_MAX; j++)
    {
      if(((balles[j].x+BALLES_X_LENGTH) >= meteore[i].x) && 
         (balles[j].x <= (meteore[i].x+METEORE_X_LENGTH)) &&
           (balles[j].etat == EXIST)&&
         (balles[j].y < (meteore[i].y+METEORE_Y_LENGTH)))
      {
        detruireMeteore(i);
        detruireBalle(j);
        score += 20;
      }
    }
    
  }
}


void itoa(char* dest, int val, int digits, int base)
{ 
  const char digitMap[] = "0123456789abcdef";
  if(val < 0) return;
  if(base == 00 || base > 16) return;
  
  do
  {
    dest[--digits] = digitMap[val%base];
    val/= base;
  }while(val > 0);  
  
  
  
  
}
  