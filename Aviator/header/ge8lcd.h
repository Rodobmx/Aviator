#ifndef _GE8LCD_H_
#define _GE8LCD_H_

/*******************************************************************************
*	ge8lcd - A library to control the color LCD screen
*       on a Olimex MSP430-4619LCD board (ge8 version)
*
* According to www.sparkfun.com/tutorial/Nokia%206100%20LCD%20Display%20Driver.pdf
* this LCD has an Epson S1D15G00 driver.
*
* The LCD is a Nokia module connected to USART1 (SPI mode)
* The backlight state is controlled by the P7.6 GPIO
*******************************************************************************/

#include <stdint.h>

// 12-bit color definitions
#define WHITE   0xFFF
#define BLACK   0x000
#define RED     0xF00
#define GREEN   0x0F0
#define BLUE    0x00F
#define CYAN    0x0FF
#define MAGENTA 0xF0F
#define YELLOW  0xFF0
#define BROWN   0xB22
#define ORANGE  0xFA0
#define PINK    0xF6A

#define LCD_WIDTH (132)
#define LCD_HEIGHT (132)

/** Perform initialisation of the ge8 LCD and the SPI bus.
	Must be called before any other functions of this library.
*/
void LCD_Init(void);

/** Set the backlight state
	\param state set to 0 to switch OFF, anything else to switch ON
*/
void LCD_Backlight(const uint8_t state);

/** Set the default value for various LCD settings.
	Called by LCD_Init(). Can be called to reset settings.
*/
void LCD_DefaultSettings(void);

/** Fill the whole display with a given color
    \param color Color (12 bits 0xRGB)
*/
void LCD_Fill(const uint16_t color);

/** Set the color of a pixel
    \param x Coordinate
    \param y Coordinate
    \param color Color (12 bits 0xRGB)
*/
void LCD_SetPixel(const uint8_t  x, const uint8_t  y, const uint16_t color);

/** Draw a line
    \param x0 Starting point coordinate
    \param y0 Starting point coordinate
    \param x1 Ending point coordinate
    \param y1 Ending point coordinate
    \param color Color (12 bits 0xRGB)
*/
void LCD_DrawLine(uint8_t x0, uint8_t y0, const uint8_t x1, const uint8_t y1, const uint16_t color);

/** Draw a rectangle, filled or hollow
    \param x0 Starting point coordinate
    \param y0 Starting point coordinate
    \param x1 Ending point coordinate
    \param y1 Ending point coordinate
    \param fill 0 for hollow rectangle, 1 for filled rectangle
    \param color Color (12 bits 0xRGB)
*/
void LCD_DrawRect(const uint8_t x0, const uint8_t y0, const uint8_t x1, const uint8_t y1, const uint8_t fill, const uint16_t color);

/** Blit (print) an image on screen.
    This function will fill a rectangular area on screen with a user's defined color image.
    The image content is given through a pointer and must be in the following format :
    |byte| content |
    | 0  | 0xR0G1  | Red and Green channel (4bits each) for pixel 0
    | 1  | 0xB0R1  | Blue channel for pixel 0 (4bits) and Red for pixel 1
    | 2  | 0xG1B1  | Green and Blue for pixel 1
    | 3  | 0xR2G2  | Red and Green for pixel 2
    | 4  | 0xB2R3  | Blue for pixel 2, Red for pixel 3
    ...

    The rectangular area where the image is displayed is given in parameters. The given
    buffer must contain enough bytes to fill the complete area.
    \param row Starting row (from top of LCD)
    \param col Starting column (from left of LCD)
    \param size_x Number of rows in the buffer
    \param size_y Number of columns in the buffer
    \param buffer Byte array containing the color information to fill the area
    */
void LCD_BlitRawBuffer( const uint8_t row, const uint8_t col, const uint8_t size_row, const uint8_t size_col, const uint8_t * const buffer );

/** Print a single character on screen
    \param c Char to print
    \param x Coordinate
    \param y Coordinate
    \param size 0=small, 1=medium, 2=big font
    \param fColor Foreground color (12 bits 0xRGB)
    \param bColor Background color (12 bits 0xRGB)
*/
void LCD_PutChar(char c, int  x, int  y, int size, int fColor, int bColor);

/** Print a string on screen
    \param pString Pointer to the string to print
    \param x Coordinate
    \param y Coordinate
    \param size 0=small, 1=medium, 2=big font
    \param fColor Foreground color (12 bits 0xRGB)
    \param bColor Background color (12 bits 0xRGB)
*/
void LCD_PutStr(char *pString, int  x, int  y, int Size, int fColor, int bColor);

/** Print a formated string on screen
    Usage similar as stdio/printf()
*/
void LCD_Printf (const char *fmt, ...);


#endif // ! defined _GE8LCD_H_
