#ifdef __MSPGCC__
#include "msp430.h"
#define _EINT __eint
#else // IAR workbench assumed
#include <msp430xG46x.h>
#endif

#include <stdint.h>
#include "header/aviator.h"
#include "header/driver_boutons.h"

void Delay (unsigned long a)
{
    while (--a!=0) {
        ;
    }
}

void init_board()
{
  // Stop watchdog timer
    WDTCTL = WDTPW + WDTHOLD;

    // External oscilator 8MHz
    FLL_CTL0 = XCAP0PF;
    // Stop DCO
    _BIS_SR(SCG1);
    FLL_CTL1 &= ~XT2OFF;
    // Wait for xtal to stabilize
    do {
        IFG1 &= ~OFIFG;  // Clear OSCFault flag
        for (int i = 5; i > 0; i--) {
            ;    // Time for flag to set
        }
    } while ((IFG1 & OFIFG));
    FLL_CTL1 = SELM1 + SELS + FLL_DIV_1;

    Delay(50000);

    // Ports P1.6, P1.7 as input
    P1DIR   &= ~((1<<6)|(1<<7));

    // Clear all interrupts flag
    P1IFG = 0x0;
    P2IFG = 0x0;

    // Center Button as input
    // gpio
    P2SEL &= ~BIT6;
    // input
    P2DIR &= ~BIT6;
    
    InitJoystick();
    InitBoutons();
}

int main( void )
{
    init_board();
    init_aviator();
    
    // Boucle infinie, le jeux est sur timer
    while(1);
}


