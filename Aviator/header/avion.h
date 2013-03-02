/*==================================================================================================
Revision History:
                            Modification       Rev.
Author                       Date D/M/Y       Number    Description of Changes
-------------------------   ------------    ----------  -------------------------------------------
N.LEMOINE
R.SAVOURET                                    				Initial version of the file.

==================================================================================================*/

#ifndef _AVION_H_
#define	_AVION_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "msp430.h"
#include <msp430xG46x.h>
#include "sprites.h"
#include "driver_joystick.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/



#define AVION_SPEED 4

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
void afficher_avion(unsigned int x, unsigned int y);
void decaler_avion(JOYSTICK_POS pos);



#endif	/* _AVION_H_ */