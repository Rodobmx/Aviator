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
#include "..\header\meteore.h"
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <io430x16x.h>

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
S_METEORE meteore[NB_METEORE_MAX];
extern unsigned int sprite_meteore[METEORE_Y_LENGTH][METEORE_X_LENGTH];
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static int rand(void);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/



/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
// ajouter timer
void addMeteore()
{
  int i = 0;
  while(meteore[i].state != NULL)
  {
    i++;
    if(i>NB_METEORE_MAX-1)
      return; // Nb max de m�t�ores atteint
  }
  
  meteore[i].state = EXIST;
  meteore[i].x = rand(); // a remplacer par 
  meteore[i].y = -METEORE_Y_LENGTH;
}
                                         
void avanceMeteore()
{
  int i = 0;
  for(i=0; i<NB_METEORE_MAX; i++)
  {
    if(meteore[i].state == EXIST)
    {
      if(meteore[i].y < 132)
      {
        meteore[i].y++;
      } else {
        detruireMeteore(i);
      }
    }
  }
}
  
void detruireMeteore(unsigned int i)
{
  meteore[i].state = NULL;
}

void afficher_meteore()
{
  unsigned char y,x;
  unsigned int i=0;
  
  for(i=0; i<NB_METEORE_MAX; i++)
  {
    if(meteore[i].state == EXIST)
    {
#ifdef SQUARE_METEORE
      for(x=0; x<METEORE_X_LENGTH; x++)
      {
        for(y=0; y<METEORE_Y_LENGTH; y++)
        {
          if(y==0)
          {
            LCD_SetPixel(meteore[i].y+y,meteore[i].x+x,background_color);
          } else {
            LCD_SetPixel(meteore[i].y+y,meteore[i].x+x,sprite_meteore[x][y]);
          }
        }
      }
#else
      for(x=0; x<METEORE_X_LENGTH; x++)
      {
        if(meteore[i].x+x < 132)
        { 
          if(meteore[i].y>0)
            LCD_SetPixel((meteore[i].y-1),meteore[i].x+x,background_color);
          if((meteore[i].y<132-1) || (meteore[i].y>0))
            LCD_SetPixel(meteore[i].y+(METEORE_Y_LENGTH-1),meteore[i].x+x,sprite_meteore[x][y]);
        }
      }

#endif
    }
  }
}

static int rand(void)
{
     int rand = TACCR0;
     rand = rand % 127;
     
     if(rand < METEORE_Y_LENGTH)
     {
       rand = METEORE_Y_LENGTH;
     }
     
     return rand;
}

/*==================================================================================================
                                         END OF FILE
==================================================================================================*/
