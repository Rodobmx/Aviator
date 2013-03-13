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
extern uint8_t sprite_meteore[METEORE_Y_LENGTH*METEORE_X_LENGTH];
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


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
  meteore[i].x = (rand()%(132-15));
  meteore[i].y = -METEORE_Y_LENGTH;
}
                                         
void avanceMeteore()
{
  int i;
  for(i=0; i<NB_METEORE_MAX; i++)
  {
    if(meteore[i].state == EXIST)
    {
      if(meteore[i].y < (131-METEORE_Y_LENGTH))
      {
        meteore[i].y += PAS_AVANCE;
      } else {
        detruireMeteore(i);
      }
    }
  }
}
  

void detruireMeteore(unsigned int i)
{
  
      meteore[i].state = DESTRUCTION_1;//NULL;
      LCD_DrawRect(meteore[i].y, meteore[i].x,meteore[i].y+METEORE_Y_LENGTH,meteore[i].x+METEORE_X_LENGTH,1, BLUE);
}

void afficher_meteore()
{
  //unsigned char y,x;
  unsigned int i=0;
  
  for(i=0; i<NB_METEORE_MAX; i++)
  {
    if(meteore[i].state == EXIST)
    {
      LCD_BlitRawBuffer(meteore[i].y, meteore[i].x, METEORE_Y_LENGTH,METEORE_X_LENGTH,sprite_meteore);
    } else if(meteore[i].state == DESTRUCTION_1)
    {
      meteore[i].state == DESTRUCTION_2;
      LCD_BlitRawBuffer(meteore[i].y, meteore[i].x, EXPLOSION_LENGTH,EXPLOSION_LENGTH,SPACE_EXPLOSION);
    } else if(meteore[i].state == DESTRUCTION_2)
    {
      meteore[i].state == EFFACEMENT;
      LCD_BlitRawBuffer(meteore[i].y, meteore[i].x, EXPLOSION_LENGTH,EXPLOSION_LENGTH,SPACE_EXPLOSION);
    } else if(meteore[i].state == DESTRUCTION_2)
    {
      meteore[i].state == NULL;
      LCD_DrawRect(meteore[i].y, meteore[i].x,meteore[i].y+EXPLOSION_LENGTH,meteore[i].x+EXPLOSION_LENGTH,1, BLUE);
    }
  }
}

void initMeteor()
{
  unsigned int i;
  
  for(i=0;i<NB_METEORE_MAX;i++)
    meteore[i].state = NULL;
}


/*==================================================================================================
                                         END OF FILE
==================================================================================================*/
