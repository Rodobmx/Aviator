
/*==================================================================================================
Revision History:
                            Modification       Rev.
Author                       Date D/M/Y       Number    Description of Changes
-------------------------   ------------    ----------  -------------------------------------------
N.LEMOINE
R.SAVOURET       				        	     -           Initial version of the file.

==================================================================================================*/


/*==================================================================================================
                                        INCLUDE FILES
==================================================================================================*/
#include "..\header\arme.h"

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
ARME armes[2];

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/



/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

void init_armement()
{  
  //definition du missile
  armes[0].periode = 100;
  armes[0].sprite = SPACE_MISSILE; 
  
  //definition
  armes[1].periode = 20;
  armes[1].sprite = SPACE_BALLE;
  /*
  for(i=0;i<((METEORE_Y_LENGTH-1)*(METEORE_X_LENGTH-1));i++)
  {
    sprite_meteore[i] = RED;
  }
  */
}


/*==================================================================================================
                                         END OF FILE
==================================================================================================*/
