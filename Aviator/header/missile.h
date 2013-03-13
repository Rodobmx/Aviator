/*==================================================================================================
Revision History:
                            Modification       Rev.
Author                       Date D/M/Y       Number    Description of Changes
-------------------------   ------------    ----------  -------------------------------------------
N.LEMOINE
R.SAVOURET                                    				Initial version of the file.

==================================================================================================*/

#ifndef _MISSILE_H_
#define	_MISSILE_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/

#include "meteore.h"
#include "sprites.h"
#include "aviator.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define MISSILES_MAX 20


/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*
typedef enum ETAT {
  ,
  EXIST,
  DESTRUCTION
} ETAT;
*/
typedef struct S_MISSILE{
    
    unsigned int x,y;
    E_STATE etat;
  
}S_MISSILE;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

extern const uint8_t SPACE_MISSILE[];

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

/**
  * Fontion addMissile
  *¨Permet de tirer des missile depuis l'avion
  * Paramêtre : x,y : position de création du missile
**/
void addMissile(unsigned char x,unsigned char y);

/**
  * Fonction avanceMissile
  * Permet de calculer l'avancée de tous les missiles
**/
void avanceMissile(void);

/**
  * Fonction detruireMissile
  * Permet de détruire un missile
  * Paramêtre : indice i du missile
**/
void detruireMissile(unsigned char x);

/**
  * Fonction afficherBalles
  * Permet d'afficher les missiles à l'écran
**/
void afficherMissile(void);

#endif	/* _MISSILE_H_ */
