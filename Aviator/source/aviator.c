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
#include "..\header\aviator.h"

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

#define DELAY_NOUVEAU_METEOR            10              // Iteration min du timer pour generation d'un meteore
#define VITESSE_JEUX_BASE               50000           // valeur du compteur sur TIMERA
#define MULTIPLICATEUR_DIFFICULTE       100             // Facteur de multiplication de la difficulté (acceleration de la vitesse du jeux)
#define DIFFICULTE_MAX                  200             // MULTIPLICATEUR_DIFFICULTE * DIFFICULTE_MAX < VITESSE_JEUX_BASE
#define SCORE_LENGTH                    7               // +1 pour caractere fin de ligne
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
uint32_t score=0;
unsigned int vie=5; 
unsigned int Difficulte=1;              // 
char score_tab[SCORE_LENGTH+1] = {'0','0','0','0','0','0','0',0};
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
extern unsigned int avion_xbase;
extern unsigned int avion_ybase;

extern S_METEORE meteore[NB_METEORE_MAX];
extern S_BALLE balles[BALLES_MAX];
extern S_MISSILE missiles[MISSILES_MAX];

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/



/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

// Timer A0 interrupt
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void) // Fonction d'interruption sur le timer
{ 
  static int ticks_meteore=0;

  if(vie > 0)
  {
    //décalage du joueur
    JOYSTICK_POS pos;  
    pos = GetJoystickPosition();
    decaler_avion(pos);

    //calcul des positions
    avanceMeteore();
    avanceMissile();
    avanceBalles();

    ticks_meteore++;
    if (ticks_meteore >= DELAY_NOUVEAU_METEOR)
    {
      addMeteore();
      ticks_meteore = 0;
    }
    
    checkCollision();
    
    afficher_meteore();
    afficherMissile();
    afficherBalles();
    
    afficher_avion();
    
    // ajustement de la difficulte
    CCR0 = VITESSE_JEUX_BASE - (Difficulte*MULTIPLICATEUR_DIFFICULTE);
  }
  else // plus de vie
  {
    itoa(score_tab, score, (SCORE_LENGTH+1),10); // base 10
    LCD_PutStr("GAME OVER !" , 20, 20, 2, YELLOW, BLACK); // position 20*20
    LCD_PutStr(score_tab,50,20, 2,YELLOW,BLACK);          // position 50*50
    while((P1IN & BIT6) != 0);
    init_aviator();
  }
}

#pragma vector=PORT1_VECTOR
__interrupt void Port1(void)
{
  //bouton A
  if(P1IFG & BIT6)
  {
    addMissile(avion_xbase,avion_ybase);
  }
    
  //bouton B
  if(P1IFG & BIT7)
  {
    addBalle(avion_xbase+AVION_X_LENGTH-DECALLAGE_ARME-1,avion_ybase);
    addBalle(avion_xbase+DECALLAGE_ARME,avion_ybase);
  }
  //raz du flag
  P1IFG &= ~(BIT6+BIT7);
}


void init_aviator()
{
    // Réinitialisation de l'écran
    LCD_Init();
    LCD_Fill(BLUE);
    
    // Réinitialisation générale
    initTimer();    
    initMeteor();
    
    // Réinitialisation des variables de jeu
    vie = 5;
    score = 0;
    Difficulte = 1;
}

void initTimer()
{   
  CCR0 = VITESSE_JEUX_BASE;
 
  TACTL = ID_3 + TASSEL_2 + MC_1;                  // divider 8, ACLK, upmode
  TA0CCTL0 = CCIE;
  __bis_SR_register(GIE);
}

void checkCollision()
/**
  * Détéction des collision, fonctionnement : 
  *     - dépassement sur l'axe y (haut - bas)
  *     - dépassement sur l'axe x (gauche - droite)
**/
{
  unsigned int i,j;
  for(i = 0; i<NB_METEORE_MAX; i++)
  {
    // Collision avec l'avion
    if((meteore[i].y+METEORE_Y_LENGTH) > (LCD_HEIGHT-AVION_Y_LENGTH)            // dépassement sur y
       &&(meteore[i].state == EXIST))
      if(((meteore[i].x+METEORE_X_LENGTH) > avion_xbase)                        // limite de collision sur x droit
          && (meteore[i].x < (avion_xbase+AVION_X_LENGTH)))                     // limite de collision sur x gauche
      {
        detruireMeteore(i);
        vie--;
      }
    
    // Collision avec missile
    for(j=0; j<MISSILES_MAX; j++)
    {
      if(((missiles[j].x+MISSILE_X_LENGTH) >= meteore[i].x) &&                  // limite de collision sur x droit
         (missiles[j].x <= (meteore[i].x+METEORE_X_LENGTH)) &&                  // limite de collision sur x gauche
         (missiles[j].etat == EXIST) &&                                         
         (missiles[j].y < (meteore[i].y+METEORE_Y_LENGTH)))                     // dépassement sur y
      {        
        detruireMeteore(i);
        detruireMissile(j);
        score += 2*Difficulte;
        if(Difficulte < DIFFICULTE_MAX)
          Difficulte++;
      }
    }
    
    // Collision avec balle
    for(j=0; j<BALLES_MAX; j++)
    {
      if(((balles[j].x+BALLES_X_LENGTH) >= meteore[i].x) &&                     // limite de collision sur x droit
         (balles[j].x <= (meteore[i].x+METEORE_X_LENGTH)) &&                    // limite de collision sur x gauche
           (balles[j].etat == EXIST)&&
         (balles[j].y < (meteore[i].y+METEORE_Y_LENGTH)))                       // dépassement sur y
      {
        detruireMeteore(i);
        detruireBalle(j);
        score += 1*Difficulte;
        if(Difficulte < (uint32_t)DIFFICULTE_MAX)
          Difficulte++;
      }
    }
    
  }
}


void itoa(char* dest, uint32_t val, int digits, int base)
{ 
  const char digitMap[] = "0123456789abcdef";
  //if(val < (uint32_t)0) return; // inutile val est unsigned
  if(base == 00 || base > 16) return;
  dest[--digits] = '\0';
  do
  {
    dest[--digits] = digitMap[(uint32_t)(val%(uint32_t)base)];                  // Met la valeur ascii correspondante dans le tab de destination
    val/= (uint32_t)base;
  }while(val > 0);  
  
}
  