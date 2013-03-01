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
#include "avion.h"

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

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

void afficher_avion(unsigned int xbase, unsigned int ybase)
{
  unsigned char y,x;
 
  for(x=0; x<15; x++)
    for(y=0; y<20; y++)
      LCD_SetPixel(ybase+y,xbase+AVION_X_LENGTH,SPACE_avion[x][y]);
}

void decaler_avion(JOYSTICK_POS pos)
{
  unsigned char y,x;
 
  switch(pos)
    {
      case J_LEFT:
        // Effacement pixel plus utilisé
        if(avion_xbase>=4)
        {
          for(x=avion_xbase+AVION_X_LENGTH; x>avion_xbase+AVION_X_LENGTH-AVION_SPEED; x--)
            for(y=avion_ybase; y<avion_ybase+AVION_Y_LENGTH; y++)
                LCD_SetPixel(y,x,background_color);
          
          avion_xbase-=AVION_SPEED;
          for(x=0; x<15; x++)
            for(y=0; y<20; y++)
              LCD_SetPixel(avion_ybase+y,avion_xbase+x,SPACE_avion[y][x]);
        }
        break;
        
      case J_RIGHT:
        // Effacement pixel plus utilisé
        if(avion_xbase+AVION_X_LENGTH <= 126)
        {
          for(x=avion_xbase; x<avion_xbase+AVION_SPEED; x++)
            for(y=avion_ybase; y<avion_ybase+AVION_Y_LENGTH; y++)
                LCD_SetPixel(y,x,background_color);
          
          avion_xbase+=AVION_SPEED;
          for(x=0; x<15; x++)
            for(y=0; y<20; y++)
              LCD_SetPixel(avion_ybase+y,avion_xbase+x,SPACE_avion[y][x]);
        }
        break;
    }
  
  
  for(x=0; x<15; x++)
    for(y=0; y<20; y++)
      LCD_SetPixel(avion_ybase+y,x+avion_xbase,SPACE_avion[x][y]);
  
}




