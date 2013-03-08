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

unsigned int avion_xbase=60;
unsigned int avion_ybase=111;
*/

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
    
    if (ticks_meteore == DELAY_NOUVEAU_METEOR)
    {
      addMeteore();
      ticks_meteore = 0;
    }
    
    afficher_meteore();
}


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

void init_aviator()
{
    LCD_Init();
    LCD_Fill(BLUE);
    initTimer();    
    init_armement();
    addMeteore();
    afficher_meteore();
}

// Initialisation du timer
void initTimer()
{   
  CCR0 = 32;//32768;
  CCR1 = 32;//32768;
  CCTL1 = OUTMOD_7; // CCR1 reset/set
 //CCR1 = CCR0; // CCR1 PWM duty cycle
  TACTL = TASSEL_2 + MC_1;                  // ACLK, upmode
  TA0CCTL0 = CCIE;
  __bis_SR_register(GIE);
}