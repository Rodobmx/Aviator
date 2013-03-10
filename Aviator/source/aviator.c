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

unsigned int score=0;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
// Timer A0 interrupt
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void) // Fonction d'interruption sur le timer
{ 
    static int ticks_meteore=0;

    //décalage du joueur
    JOYSTICK_POS pos;  
    pos = GetJoystickPosition();
    decaler_avion(pos);

    
    //calcul des positions
    avanceMeteore();
    avanceMissile();

    ticks_meteore++;
    if (ticks_meteore >= DELAY_NOUVEAU_METEOR)
    {
      addMeteore();
      ticks_meteore = 0;
    }
    
    afficher_meteore();
    afficherMissile();
}

#pragma vector=PORT1_VECTOR
__interrupt void Port1(void)
{
  //bouton A
  if( (P1IFG | BIT6) == P1IFG)
  {
    addMissile(avion_xbase,avion_ybase);
    //addMissile(130,20);
  }
    
  //bouton B
  if( (P1IFG | BIT7) == P1IFG)
  {
    addBalle(130,20);
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
    //init_armement();
    initMeteor();
    
    //addMeteore();
    //afficher_meteore();
}

// Initialisation du timer
void initTimer()
{   
  //CCR0 = 32;//32768;
  //CCR1 = 32;//32768;
  CCR0 = 50000;
  //CCR1 = 1000;
  //CCTL1 = OUTMOD_7; // CCR1 reset/set
 //CCR1 = CCR0; // CCR1 PWM duty cycle
  TACTL = ID_3 + TASSEL_2 + MC_1;                  // ACLK, upmode
  TA0CCTL0 = CCIE;
  __bis_SR_register(GIE);
}
