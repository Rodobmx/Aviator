// Fichier récupéré en grosse partie sur les projet test du site olimex


/*==================================================================================================
                                        INCLUDE FILES
==================================================================================================*/
#include <msp430xG46x.h>
#include "..\header\driver_joystick.h"
/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
void InitADC12(void) {


  /* ADC12 Control Register 0 */
  // ADC12 sample-and-hold time -> 256 x ADC12CLKs,
  // Referance = 2.5V, Select ADC12MEM0
  ADC12CTL0 = SHT03;

  // Sample-and-hold source select -> ADC12SC bit, no clock divider,
  // clock -> ADC12OSC - internal osillator ~5MHz, Single-channel and single-conversion
  // ADC12CTL1 = SHP;

  // Sample-and-hold source select -> ADC12SC bit, no clock divider,
  // clock -> MCLK - external osillator ~2MHz, Single-channel and single-conversion
  // ADC12CTL1 = ADC12SSEL1+SHP;
  ADC12CTL1 = ADC12SSEL1;

  // Conversion Memory Control Registers
  // Select reference -> VR+ = AVCC+ and VR– = AVSS
  ADC12MCTL0 = 0x0;


  // A0,A3 as analog input
  P6SEL   |= (BIT0|BIT1|BIT2);    // P6.0, P6.1 and P6.2 -> ADC10 function
  P6DIR   &= ~(BIT0|BIT1|BIT2);   // P6.0, P6.1 and P6.2 -> input direction

}

/****************************************************************************/
/*  Get value form ADC12 chanel A7                                          */
/*  Function : GetADC12_A7                                                  */
/*      Parameters                                                          */
/*          Input   :  Nothing                                              */
/*          Output  :  maesured value                                       */
/****************************************************************************/
unsigned int GetADC12_A7(void) {

    // measured value
  unsigned int val  = 0;

  // clear
  ADC12MCTL0 = 0;

  // ADC12 on
  ADC12CTL0 |= ADC12ON;

  // Input channel select -> A7
  ADC12MCTL0 |= INCH_7;

  // Enable and start conversion
  ADC12CTL0 |= (ADC12SC + ENC);
  // ADC12CTL0 |= ENC;
  // ADC12CTL0 |= ADC12SC;
  ADC12CTL0 &= ~ADC12SC;

  // wait end of conversion
  // while(!(ADC12IFG&0x1));
  while (ADC12CTL1 & ADC12BUSY);


  // Clear interrupt flag
  ADC12IFG = 0;

  // get ADC value
  val = ADC12MEM0;

  // Disable and stop conversion
  ADC12CTL0 &= ~(ADC12SC + ENC);

  // ADC12 off
  // ADC12CTL0 &= ~ADC12ON;

  // return value
  return val;
}


/****************************************************************************/
/*  Init Joystick Button                                                    */
/*  Function : InitJoystick                                                 */
/*      Parameters                                                          */
/*          Input   :  Nothing                                              */
/*          Output  :  Nothing                                              */
/****************************************************************************/
void InitJoystick(void) {

  // Init ADC interface
  InitADC12();

  // A7 as analog input
  P6SEL   |= BIT7;   // P6.7 ADC10 function
  P6DIR   = 0x0;     // P6.7 input direction

  // P2.6 as input
  P2SEL   &= ~BIT6;   // P2.6 as GPIO
  P2DIR   &= ~BIT6;   // P2.6 as input

}

/****************************************************************************/
/*  Init Joystick Button                                                    */
/*  Function : InitJoystick                                                 */
/*      Parameters                                                          */
/*          Input   :  Nothing                                              */
/*          Output  :  Joystick Position                                    */
/****************************************************************************/
JOYSTICK_POS GetJoystickPosition(void) {

  char jresult;
  int  adcresult;
  char nsample;

  adcresult = 0;
  jresult = 0;

  for(nsample=0; nsample<8; nsample++) {
    adcresult += GetADC12_A7();
  }

  adcresult /= (nsample+1);

//  if((adcresult>2080)&&(adcresult<2140))  jresult += J_LEFT;
//  if((adcresult>1300)&&(adcresult<1340))  jresult += J_RIGHT;
//  if((adcresult>2300)&&(adcresult<2360))  jresult += J_UP;
//  if((adcresult>700)&&(adcresult<740))    jresult += J_DOWN;

  if((adcresult>1800)&&(adcresult<2000))  jresult += J_LEFT;
  if((adcresult>1100)&&(adcresult<1300))  jresult += J_RIGHT;
  if((adcresult>2000)&&(adcresult<2200))  jresult += J_UP;
  if((adcresult>550)&&(adcresult<750))    jresult += J_DOWN;


  if(((P2IN&BIT6)==BIT6)&&(adcresult<100)) jresult += J_CENTER;

  return (JOYSTICK_POS)jresult;
}
/*==================================================================================================
                                         END OF FILE
==================================================================================================*/

