/*==================================================================================================
Revision History:
                            Modification       Rev.
Author                       Date D/M/Y       Number    Description of Changes
-------------------------   ------------    ----------  -------------------------------------------
N.LEMOINE
R.SAVOURET                                    				Initial version of the file.

==================================================================================================*/

#ifndef _SPACE_SPRITES_H_
#define	_SPACE_SPRITES_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "ge8lcd.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/



/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
//unsigned int SPACE_meteor[15][15]={MAGENTA};
unsigned int SPACE_avion[15][20]=
{	BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	, // ->>>>> y
	BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,
	BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,
	BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,
	BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,RED	,BLUE	,BLUE	,
	BLUE	,BLUE	,RED	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,RED	,BLUE	,BLUE	,
	BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,
	BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,
	BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,
	BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,
	BLUE	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,BLUE	,
	BLUE	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,BLUE	,
	BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,
	BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,
	BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,
	BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,
	BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,
	BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,
	BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,
	BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,YELLOW	,YELLOW	,YELLOW	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE	,BLUE};
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
void InitADC12(void);
unsigned int GetADC12_A7(void);
void InitJoystick(void);
JOYSTICK_POS GetJoystickPosition(void);


#endif	/* _SPACE_SPRITES_H_ */
