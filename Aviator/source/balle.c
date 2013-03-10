
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
#include "..\header\balle.h"
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

S_BALLE balles[BALLES_MAX];

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

void addBalle(unsigned char x, unsigned char y)
{
   unsigned char i=0;
   
   while(balles[i].etat != NULL)
   {
     i++;
     if(i == BALLES_MAX)  //max de missiles atteint
       return;
   }
   
   balles[i].etat = EXIST;
   balles[i].x = x;
   balles[i].y = y;  
}


void avanceBalles(void)
{
  unsigned char i;
  
  for(i=0;i<BALLES_MAX;i++)
  {
    //pas de test sur l'existance du missile
    //gain de temps
    balles[i].y--;
    
    if(balles[i].y < BORD_ECRAN)
    {
      balles[i].etat = NULL;
    }
  }  
}

void detruireBalle(unsigned char x)
{
  unsigned char i;
  
  for(i=0;i<BALLES_MAX;i++)
  {
    if(balles[i].x = x)
    {
      balles[i].etat = NULL;
    }
  }
}


void afficherBalles()
{
    unsigned char i;
    for(i=0;i<BALLES_MAX;i++)
    {
      if(balles[i].etat == EXIST)
      {
        LCD_BlitRawBuffer(balles[i].x, balles[i].y,1,BALLES_Y_LENGTH,SPACE_BALLE);
      }
    }
}


/*==================================================================================================
                                         END OF FILE
==================================================================================================*/
