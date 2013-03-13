/*==================================================================================================
Revision History:
                            Modification       Rev.
Author                       Date D/M/Y       Number    Description of Changes
-------------------------   ------------    ----------  -------------------------------------------
N.LEMOINE
R.SAVOURET                                    				Initial version of the file.

==================================================================================================*/

#ifndef _METEORE_H_
#define	_METEORE_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "sprites.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define NB_METEORE_MAX 10
#define PAS_AVANCE 1

/*==================================================================================================
                                             ENUMS
==================================================================================================*/
typedef enum _E_STATE {
  NULL,                         // Inexistant                   0    0
  EXIST,                        // Existe, tombe                 1   |
  DESTRUCTION_1,                // Stade de destruction 1         2  |
  DESTRUCTION_2,                // Stade de destruction 2          3 |
  EFFACEMENT                    // Stade d'éffacement               4
} E_STATE;
/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
  * Structure météore
**/
typedef struct _S_METEORE {
  unsigned int x; // X reste dans les bornes
  int y;          // apparition progressive par le haut
  E_STATE state; // 0 : null, 1 : créé, 2 : en destruction ...
} S_METEORE;
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern unsigned int background_color;
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
/**
  * Fonction initialisant le module météore
**/
void initMeteor(void);

/**
  * Fonction permettant d'ajouter une météore sur x aléatoire
**/
void addMeteore(void);

/**
  * Fonction permettant de calculer l'avancée de tous les météores
**/
void avanceMeteore(void);

/**
  * Fonction permettant de détruire le météore d'index i
**/
void detruireMeteore(unsigned int i);

/**
  * Fonction permettant d'afficher les météore
**/
void afficher_meteore(void);



#endif	/* _METEORE_H_ */
