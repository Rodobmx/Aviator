/*==================================================================================================
Revision History:
                            Modification       Rev.
Author                       Date D/M/Y       Number    Description of Changes
-------------------------   ------------    ----------  -------------------------------------------
N.LEMOINE
R.SAVOURET                                    				Initial version of the file.

==================================================================================================*/

#ifndef _BALLE_H_
#define	_BALLE_H_

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

#define BALLES_MAX 50           // Nombre de balle max en jeux

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
  * Structure balle, position et etat
**/ 
typedef struct S_BALLE{
    
    unsigned int x,y;
    E_STATE etat;
  
}S_BALLE;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

extern const uint8_t SPACE_BALLE[];   // sprite balle

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

/**
  * Fontion addBalle
  *¨Permet de tirer des balles depuis l'avion (type mitrailleuse)
  * Créer une balle dans un tableau de S_BALLE
  * Paramêtre : x,y : position de création de la balle
**/
void addBalle(unsigned char x,unsigned char y);

/**
  * Fonction avanceBalles
  * Permet de calculer l'avancée de toutes les balles
**/
void avanceBalles(void);

/**
  * Fonction detruireBalle
  * Permet de détruire une balle
  * Paramêtre : indice i de la balle
**/
void detruireBalle(unsigned char i); 

/**
  * Fonction afficherBalles
  * Permet d'afficher les balles à l'écran
**/
void afficherBalles(void);


#endif	/* _BALLE_H_ */
