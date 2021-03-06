
#include "..\header\sprites.h"


// Sprite des diff�rents �l�ments
// Type de sprite actuel : Espace

const uint8_t SPACE_avion[] = 
{
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0xFF, 0x0F, 0xF0,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xFF, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x00, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xF0, 0x0F, 0x00,0x00, 0xFF, 0xF0,0x40, 0x04, 0x00,0xFF, 0x00, 0x0F,0xF0, 0x0F, 0x00,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xF0, 0x0F, 0x00,0x00, 0xFF, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x00, 0x0F,0xF0, 0x0F, 0x00,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xFF, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xFF, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xF0, 0x0F, 0x00,0x00, 0xFF, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x00, 0x0F,0xF0, 0x0F, 0x00,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xFF, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x00, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xFF, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x00, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xFF, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x00, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xFF, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x00, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0xFF, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0xFF, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0x00, 0xFF, 0xF0,0xF8, 0x0F, 0x80,0xFF, 0x0F, 0xF0,0xF8, 0x0F, 0x80,0xFF, 0x00, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xFF, 0x0F, 0x00,0xF8, 0x0F, 0x80,0xFF, 0x0F, 0xF0,0xF8, 0x0F, 0x80,0xF0, 0x0F, 0xF0,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xFF, 0x0F, 0x00,0xF8, 0x0F, 0x80,0xFF, 0x0F, 0xF0,0xF8, 0x0F, 0x80,0xF0, 0x0F, 0xF0,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xF0, 0x0F, 0x84,0xF0, 0x0F, 0x84,0xF0, 0x0F, 0x00,0xF8, 0x4F, 0x00,0xF8, 0x4F, 0x00,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xF0, 0x0F, 0x84,0xF0, 0x0F, 0x84,0xF0, 0x0F, 0x00,0xF8, 0x4F, 0x00,0xF8, 0x4F, 0x00,0x00, 0xF0, 0x0F

};

const uint8_t sprite_meteore[] = 
{
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xFF, 0xF0,0x00, 0xFF, 0xF0,0xFF, 0x00, 0x0F,0xFF, 0x00, 0x0F,
0x00, 0xFF, 0xF0,0xF8, 0x0F, 0xF0,0xFF, 0x0F, 0x80,0xFF, 0x00, 0x0F,
0x00, 0xFF, 0xF0,0xF8, 0x4F, 0xF0,0xFF, 0x0F, 0x84,0xFF, 0x00, 0x0F,
0x00, 0xFF, 0xF0,0xF8, 0x4F, 0xF0,0xFF, 0x0F, 0x84,0xFF, 0x00, 0x0F,
0x00, 0xF8, 0x00,0x80, 0x08, 0x00,0x00, 0x08, 0x00,0x80, 0x00, 0x0F,
0x80, 0x08, 0x00,0x80, 0x08, 0x00,0x80, 0x08, 0x00,0x80, 0x00, 0x0F,
0x80, 0x08, 0x00,0x00, 0x00, 0x0F,0x00, 0x08, 0x00,0x80, 0x00, 0x0F,
0x00, 0xF8, 0x00,0x00, 0xF0, 0x0F,0x80, 0x08, 0x00,0x80, 0x08, 0x00,
0x00, 0xF8, 0x00,0x80, 0x00, 0x00,0x80, 0x00, 0x00,0x80, 0x08, 0x00,
0x00, 0xF8, 0x00,0x00, 0x00, 0x00,0x00, 0x08, 0x00,0x80, 0x08, 0x00,
0x80, 0x08, 0x00,0x80, 0x08, 0x00,0x00, 0xF0, 0x0F,0x80, 0x08, 0x00,
0x80, 0x08, 0x00,0x00, 0x08, 0x00,0x00, 0xF0, 0x0F,0x80, 0x00, 0x0F,
0x00, 0xF8, 0x00,0x00, 0x08, 0x00,0x00, 0x08, 0x00,0x80, 0x00, 0x0F,
0x00, 0xF0, 0x0F,0x80, 0x08, 0x00,0x80, 0x08, 0x00,0x00, 0xF0, 0x0F

};

const uint8_t SPACE_MISSILE[] = 
{
0x00, 0xF0, 0x0F,0x00, 0xFF, 0x00,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xFF, 0x00,0xF0, 0x0F, 0x00,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xF0, 0x0F, 0x00,0xF0, 0x00, 0x0F,0x00, 0xFF, 0x00,0xF0, 0x0F, 0x00,0xF0, 0x0F, 0x00,0xF0, 0x0F, 0x00,
0x00, 0xF0, 0x0F,0xF0, 0x0F, 0x00,0xF0, 0x00, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xFF, 0x00,0xF0, 0x0F, 0x00,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xF0, 0x0F, 0x00,0xF0, 0x00, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xFF, 0x00,0xF0, 0x0F, 0x00,0x00, 0xF0, 0x0F,
0x00, 0xFF, 0x00,0xFF, 0x0F, 0x00,0xFF, 0x0F, 0x00,0x00, 0xF0, 0x0F,0xF0, 0x0F, 0xF0,0xF0, 0x0F, 0xF0,0xF0, 0x00, 0x0F,
0x00, 0xFF, 0x00,0xFF, 0x0F, 0x00,0xFF, 0x0F, 0x00,0x00, 0xF0, 0x0F,0xF0, 0x0F, 0xF0,0xFF, 0x0F, 0xF0,0xF0, 0x00, 0x0F,
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F

};

const uint8_t SPACE_BALLE[]=
{	
	0xFF    ,0x0F  , 0xF0 , 0xFF, 0x0F , 0XF0, 0x00, 0xF0 ,0x0F //YELLOW,YELLOW,YELLOW,YELLOW,BLUE,BLUE
};

const uint8_t SPACE_EXPLOSION[] = 
{
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0xF0, 0x0F, 0x00,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xF0, 0x0F, 0xF0,0xF0, 0x0F, 0x00,0xFF, 0x0F, 0x00,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xFF, 0x0F, 0x00,0xFF, 0x0F, 0xF0,0xF0, 0x0F, 0xF0,0x00, 0xF0, 0x0F,
0x00, 0xFF, 0x00,0xF0, 0x0F, 0xF0,0xF0, 0x0F, 0x00,0xFF, 0x0F, 0x00,0xF0, 0x00, 0x0F,
0x00, 0xFF, 0x00,0xF0, 0x0F, 0xF0,0xF0, 0x0F, 0x00,0xFF, 0x0F, 0x00,0xF0, 0x00, 0x0F,
0x00, 0xF0, 0x0F,0xFF, 0x0F, 0x00,0xFF, 0x0F, 0xF0,0xF0, 0x0F, 0xF0,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0xF0, 0x0F, 0xF0,0xF0, 0x0F, 0x00,0xFF, 0x0F, 0x00,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0xF0, 0x0F, 0x00,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,
0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F,0x00, 0xF0, 0x0F

};