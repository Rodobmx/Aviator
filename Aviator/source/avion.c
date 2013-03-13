// SPACE INVADER
/*==================================================================================================
Revision History:
                            Modification       Rev.
Author                       Date D/M/Y       Number    Description of Changes
-------------------------   ------------    ----------  -------------------------------------------
N.LEMOINE
R.SAVOURET                                    				Initial version of the file.

==================================================================================================*/

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "..\header\avion.h"
#include "..\header\meteore.h"

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
unsigned int background_color = BLUE;   // Couleur de fond d'écran

unsigned int avion_xbase=60;            // Position du pixel haut gauche sur x de l'avion
unsigned int avion_ybase=111;           // Position du pixel haut gauche sur y de l'avion

extern const uint8_t SPACE_avion[];     // Sprite avion
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

void afficher_avion()
{
  LCD_BlitRawBuffer(avion_ybase, avion_xbase,AVION_Y_LENGTH,AVION_X_LENGTH,SPACE_avion);
}

void decaler_avion(JOYSTICK_POS pos)
{ 
  switch(pos)
    {
      case J_LEFT:
        // Effacement pixel plus utilisé
        if(avion_xbase>=4)                      // Limite du bord de gauche
        {
          avion_xbase-=AVION_SPEED;
        }
        break;
        
      case J_RIGHT:
        // Effacement pixel plus utilisé
        if(avion_xbase+AVION_X_LENGTH <= 126)   // limite du bord de droite
        {         
          avion_xbase+=AVION_SPEED;
        }
        break;
        
      case J_CENTER:
        break;
      default:
        break;
    }
}




