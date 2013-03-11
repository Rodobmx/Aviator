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
  NULL,
  EXIST,
  DESTRUCTION
} E_STATE;
/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct _S_METEORE {
  unsigned int x;
  int y;
  E_STATE state; // 0 : null, 1 : cr��, 2 : en destruction
} S_METEORE;
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
void initMeteor(void);
void addMeteore(void);
void avanceMeteore(void);
void detruireMeteore(unsigned int i);
void afficher_meteore(void);
extern unsigned int background_color;

#endif	/* _METEORE_H_ */
