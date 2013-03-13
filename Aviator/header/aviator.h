/*==================================================================================================
Revision History:
                            Modification       Rev.
Author                       Date D/M/Y       Number    Description of Changes
-------------------------   ------------    ----------  -------------------------------------------
N.LEMOINE
R.SAVOURET                                    				Initial version of the file.

==================================================================================================*/

#ifndef _AVIATOR_H_
#define	_AVIATOR_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "msp430.h"
#include <msp430xG46x.h>
#include "driver_joystick.h"
#include "avion.h"
#include "meteore.h"
#include "missile.h"
#include "balle.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/*
#define AVION_X_LENGTH 15
#define AVION_Y_LENGTH 20
*/
#define BORD_ECRAN 2

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
/**
  * Fonction principale du jeux
  * Sur timer variable en fonction de la difficulté
  * Fonctionnement : Calcul puis Affichage
**/
__interrupt void Timer_A (void);

/**
  * Fonction d'initialisation du jeux,
  * initialise le timer A et les variables du jeu
**/
void init_aviator();


/**
  * Fonction d'initialisation du timer
**/
void initTimer();


/**
  * Fonction permettant de détécter des collision entre les éléments
**/
void checkCollision();


/** * Annexe *
  * Fonction permettant la conversion d'entier en ascii
**/
void itoa(char* dest, uint32_t val, int digits, int base);

#endif	/* _AVIATOR_H_ */
