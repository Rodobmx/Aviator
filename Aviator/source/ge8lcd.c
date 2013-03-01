#include "ge8lcd.h"

#ifdef __MSPGCC__
#include "msp430.h"
#define _EINT __eint
#else // IAR workbench assumed
#include <msp430xG46x.h>
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "font.h"

/** LCD Characteristics */
// note: the LCD is 132 row and 132 columns, the first and last one are not seen
static const uint8_t lcd_width = 132;
static const uint8_t lcd_height = 132;
static const uint8_t lcd_bits_per_pixel = 12;
// For 12 bits colors : 132*132*12/8
static const uint16_t lcd_byte_size = 26136;

/** Globals */
unsigned int Lcd_row=2, Lcd_col=2; ///< For Printf()

#define LCD_MEDIUM_CHAR_WIDTH     (8)
#define LCD_MEDIUM_CHAR_HEIGHT    (8)

/** Commands for the LCD controller
*/
enum {
    LCDCMD_DISON	=	0xAF, ///< Display on
    LCDCMD_DISOFF	=	0xAE, ///< Display off
    LCDCMD_DISNOR	=	0xA6, ///< Normal display
    LCDCMD_DISINV	=	0xA7, ///< Inverse display
    LCDCMD_COMSCN	=	0xBB, ///< Common scan direction
    LCDCMD_DISCTL	=	0xCA, ///< Display control
    LCDCMD_SLPIN	=	0x95, ///< Sleep in
    LCDCMD_SLPOUT	=	0x94, ///< Sleep out
    LCDCMD_PASET	=	0x75, ///< Page address set
    LCDCMD_CASET	=	0x15, ///< Column address set
    LCDCMD_DATCTL	=	0xBC, ///< Data scan direction, etc.
    LCDCMD_RGBSET8	=	0xCE, ///< 256-color position set
    LCDCMD_RAMWR	=	0x5C, ///< Writing to memory
    LCDCMD_RAMRD	=	0x5D, ///< Reading from memory
    LCDCMD_PTLIN	=	0xA8, ///< Partial display in
    LCDCMD_PTLOUT	=	0xA9, ///< Partial display out
    LCDCMD_RMWIN	=	0xE0, ///< Read and modify write
    LCDCMD_RMWOUT	=	0xEE, ///< End
    LCDCMD_ASCSET	=	0xAA, ///< Area scroll set
    LCDCMD_SCSTART	=	0xAB, ///< Scroll start set
    LCDCMD_OSCON	=	0xD1, ///< Internal oscillation on
    LCDCMD_PWRCTR	=	0x20, ///< Power control
    LCDCMD_VOLCTR	=	0x81, ///< Electronic volume control
    LCDCMD_VOLUP	=	0xD6, ///< Increment electronic control by 1
    LCDCMD_VOLDOWN	=	0xD7, ///< Decrement electronic control by 1
    LCDCMD_TMPGRD	=	0x82, ///< Temperature gradient set
    LCDCMD_EPCTIN	=	0xCD, ///< Control EEPROM
    LCDCMD_EPCOUT	=	0xCC, ///< Cancel EEPROM control
    LCDCMD_EPMWR	=	0xFC, ///< Write into EEPROM
    LCDCMD_EPMRD	=	0xFD, ///< Read from EEPROM
    LCDCMD_EPSRRD1	=	0x7C, ///< Read register 1
    LCDCMD_EPSRRD2	=	0x7D, ///< Read register 2
    LCDCMD_NOP		=	0x25  ///< NOP instruction
} lcdcmd_e;

/*********************** static functions *************************************/
static void DelayS (unsigned long a)
{
    while (--a!=0) {
        ;
    }
}

static inline void cs_low(void)
{
    P4OUT &= ~0x04;
}

static void SPI_Send( uint8_t isCommand, uint8_t payload )
{
    P4SEL &= ~0x28; // P4.3 and P4.5 as GPIO

    // Depending on 'command' or 'data', the first bit (out of 9) is different.
    // This bit is set by this software trick; the remaining bits are send by
    // the SPI peripheral.
    if ( isCommand != 0 ) {
        // an spi 'command' is sent to the LCD
        P4OUT |= 0x20;  // P4.5  -> HIGH
        P4OUT &= ~0x08; // P4.3  -> LOW
    } else {
        // an spi 'data' is sent to the LCD
        P4OUT |= 0x28;  // P4.3 and P4.5  -> HIGH
    }

    P4DIR |= 0x28;  // P4.3 and P4.5 -> OUTPUT

    cs_low();

    P4OUT &= ~0x20; // P4.5 -> LOW
    P4OUT |= 0x20;  // P4.5 -> HIGH

    P4SEL |= 0x28;  // P4.3 and P4.5 SPI option select

    // Write byte
    TXBUF1 = payload;

    // wait for SPI TX buffer empty (all bits sent)
    // TODO : move to begin of function ?
    while ((U1TCTL & TXEPT) == 0) {
        ;
    }
}

static void SPI_Init(void)
{
    // Enable USART0 SPI mode
    U1ME |= USPIE1;

    /* USART Control Register */
    // 8-bit, SPI Master
    UCTL1 = CHAR+SYNC+MM;

    /* USART Transmit Control Register */
    // Select SMCLK and 3-pin SPI select, Clock Polarity
    U1TCTL = SSEL0+SSEL1+STC+CKPL;

    /* USART Baud Rate Control Register 0 and 1 */
    /* USART Modulation Control Register */
    // Set BaudRate - no divider
    UBR01   = 0x04;
    UBR11   = 0x00;
    UMCTL1  = 0x00;

    // Setup P4 for SPI1 operation
    P4SEL |= 0x28;		// P4.3 and P4.5 SPI option select

    P4SEL &= ~0x04;		// P4.2 as GPIO
    P4OUT |= 0x04;		// CS high
    P4DIR |= 0x04;		// P4.2 output direction
}


/*************************** Exported functions *******************************/
void LCD_Init(void)
{
    // Reset Pin
    P7SEL &= ~(1<<4);	// P7.4 as GPIO
    P7OUT &= ~(1<<4); 	// reset LCD
    P7DIR |= (1<<4);	// P7.4 output direction

    // Backlight
    P7SEL &= ~(1<<6);	// P7.6 as GPIO
    P7OUT |= (1<<6);	// Turn off light
    P7DIR |= (1<<6); 	// P7.6 output direction

    SPI_Init();

    DelayS(50000);

    P7OUT &= ~(1<<6);	// Turn on light
    P7OUT |= (1<<4); 	// reset high

    DelayS(50000);
    DelayS(50000);
    DelayS(50000);

    LCD_DefaultSettings();
}

void LCD_Backlight(const uint8_t state)
{
    if(state == 0) {
        P7OUT |= (1<<6);    //Turn off light
    } else {
        P7OUT &= ~(1<<6);   //Turn on light
    }
}

void LCD_DefaultSettings(void)
{
    // Display control
    SPI_Send(true,LCDCMD_DISCTL);

    SPI_Send(false,0x00); // default
    SPI_Send(false,0x20); // (32 + 1) * 4 = 132 lines (of which 130 are visible)
    SPI_Send(false,0x0a); // default

    // COM scan
    SPI_Send(true,LCDCMD_COMSCN);
    SPI_Send(false,0x01);  // Scan 1-80

    // Internal oscilator ON
    SPI_Send(true,LCDCMD_OSCON);

    // Sleep out
    SPI_Send(true,LCDCMD_SLPOUT);

    // Voltage control
    SPI_Send(true,LCDCMD_VOLCTR);
    SPI_Send(false,0x25); // middle value of V1
    SPI_Send(false,0x03); // middle value of resistance value

    // Temperature gradient
    SPI_Send(true,LCDCMD_TMPGRD);
    SPI_Send(false,0x00); // default

    // Power control
    SPI_Send(true,LCDCMD_PWRCTR);
    SPI_Send(false,0x0f);// ref voltage regulator on, circuit voltage follower on, boost on

    // Normal display
    //SPI_Send(true,LCDCMD_DISNOR);

    // Inverse display
    SPI_Send(true,LCDCMD_DISINV);

    // Partial area off
    SPI_Send(true,LCDCMD_PTLOUT);

    // Data control
    SPI_Send(true,LCDCMD_DATCTL);
    SPI_Send(false,0x01); // has been changed : orginal was all inversions off, column direction
    SPI_Send(false,0x00); // RGB sequence
    SPI_Send(false,0x02); // 4k color

    // Page Address set
    SPI_Send(true,LCDCMD_PASET);
    SPI_Send(false,0);
    SPI_Send(false,131);

    // Page Column set
    SPI_Send(true,LCDCMD_CASET);
    SPI_Send(false,0);
    SPI_Send(false,131);

    // wait ~100ms
    DelayS(10000);

    // Display On
    SPI_Send(true,LCDCMD_DISON);
}

static void LCD_SetXYXY(const uint8_t x0, const uint8_t  y0, const uint8_t x1, const uint8_t y1)
{
    // Row address set  (command 0x2B)
    SPI_Send(true,LCDCMD_PASET);
    SPI_Send(false,x0);
    SPI_Send(false,x1);
    // Column address set  (command 0x2A)
    SPI_Send(true,LCDCMD_CASET);
    SPI_Send(false,y0);
    SPI_Send(false,y1);
}

void LCD_Fill(const uint16_t color)
{
    // Red, Green
    const uint8_t colorA = ( (color >> 4) & 0xFF );
    // Blue, Red
    const uint8_t colorB = ( ((color<<4)&0xF0) | ((color>>8)&0x0F) );
    // Green, Blue
    const uint8_t colorC = (color & 0xFF);

    LCD_SetXYXY(0,0,lcd_width-1,lcd_height-1);

    // WRITE MEMORY
    SPI_Send(true,LCDCMD_RAMWR);

    // write to memory (8712*3 == lcd_width*lcd_height*12/8)
    for(uint16_t j=0; j<8712; ++j) {
        SPI_Send(false,colorA);
        SPI_Send(false,colorB);
        SPI_Send(false,colorC);
    }
    SPI_Send(true,LCDCMD_NOP);
}

void LCD_SetPixel(const uint8_t  x, const uint8_t  y, const uint16_t color)
{
    LCD_SetXYXY(x, y, x+1, y+1);
    // Red, Green
    const uint8_t colorA = ( (color >> 4) & 0xFF );
    // Blue, Red
    const uint8_t colorB = ( ((color<<4)&0xF0) | ((color>>8)&0x0F) );
    // Green, Blue
    const uint8_t colorC = (color & 0xFF);
    
    SPI_Send(true,LCDCMD_RAMWR);
    SPI_Send(false,colorA);
    SPI_Send(false,colorB);
    SPI_Send(false,colorC);
    SPI_Send(true,LCDCMD_NOP);
}

/*******************************************************************************
//    LCDSetLine.c
//
//  Draws a line in the specified color from (x0,y0) to (x1,y1)
//
//  Inputs:  x     =   row address (0 .. 131)
//   y     =   column address  (0 .. 131)
//   color =  12-bit color value  rrrrggggbbbb
//  rrrr = 1111 full red
//     :
//    0000 red is off
//
//  gggg = 1111 full green
//     :
//    0000 green is off
//
//  bbbb = 1111 full blue
//     :
//    0000 blue is off
//
//  Returns:   nothing
//
//  Note: good write-up on this algorithm in Wikipedia (search for Bresenham's line algorithm)
//       see lcd.h for some sample color settings
//
//  Authors:  Dr. Leonard McMillan, Associate Professor UNC
//  Jack Bresenham IBM, Winthrop University (Father of this algorithm, 1962)
//
//  Note: taken verbatim from Professor McMillan's presentation:
//       http://www.cs.unc.edu/~mcmillan/comp136/Lecture6/Lines.html
//
//  ***************************************************************************/
void LCD_DrawLine(uint8_t x0, uint8_t y0, const uint8_t x1, const uint8_t y1, const uint16_t color)
{
    int dy = y1 - y0;
    int dx = x1 - x0;
    int stepx, stepy;

    if (dy < 0) {
        dy = -dy;
        stepy = -1;
    } else {
        stepy = 1;
    }
    if (dx < 0) {
        dx = -dx;
        stepx = -1;
    } else {
        stepx = 1;
    }

    dy <<= 1; // dy is now 2*dy
    dx <<= 1; // dx is now 2*dx

    LCD_SetPixel(x0, y0, color);

    if (dx > dy) {
        int fraction = dy - (dx >> 1); // same as 2*dy - dx
        while (x0 != x1) {
            if (fraction >= 0) {
                y0 += stepy;
                fraction -= dx; // same as fraction -= 2*dx
            }
            x0 += stepx;
            fraction += dy; // same as fraction -= 2*dy
            LCD_SetPixel(x0, y0, color);
        }
    } else {
        int fraction = dx - (dy >> 1);
        while (y0 != y1) {
            if (fraction >= 0) {
                x0 += stepx;
                fraction -= dy;
            }
            y0 += stepy;
            fraction += dx;
            LCD_SetPixel(x0, y0, color);
        }
    }
}

//  *****************************************************************************************
//    LCDSetRect.c
//
//  Draws a rectangle in the specified color from (x1,y1) to (x2,y2)
//  Rectangle can be filled with a color if desired
//
//  Inputs:  x     =   row address (0 .. 131)
//   y     =   column address  (0 .. 131)
//   fill  =   0=no fill, 1-fill entire rectangle
//   color =   12-bit color value for lines rrrrggggbbbb
//  rrrr = 1111 full red
//     :
//    0000 red is off
//
//  gggg = 1111 full green
//     :
//    0000 green is off
//
//  bbbb = 1111 full blue
//     :
//    0000 blue is off
//
//    Returns:   nothing
//
// Notes:
//
//  The best way to fill a rectangle is to take advantage of the "wrap-around" featute
//  built into the Epson S1D15G00 controller. By defining a drawing box, the memory can
//  be simply filled by successive memory writes until all pixels have been illuminated.
//
//  1.  Given the coordinates of two opposing corners (x0, y0) (x1, y1)
//     calculate the minimums and maximums of the coordinates
//
//  xmin = (x0 <= x1) ? x0 : x1;
//  xmax = (x0 > x1) ? x0 : x1;
//  ymin = (y0 <= y1) ? y0 : y1;
//  ymax = (y0 > y1) ? y0 : y1;
//
//  2. Now set up the drawing box to be the desired rectangle
//
//  SPI_Send(true,LCDCMD_PASET); // set the row boundaries
//   SPI_Send(false,xmin);
//   SPI_Send(false,xmax);
//  SPI_Send(true,LCDCMD_CASET); // set the column boundaries
//   SPI_Send(false,ymin);
//   SPI_Send(false,ymax);
//
//  3. Calculate the number of pixels to be written divided by 2
//
//  NumPixels = ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 1)
//
//  You may notice that I added one pixel to the formula.
//  This covers the case where the number of pixels is odd and we
//  would lose one pixel due to rounding error. In the case of
//  odd pixels, the number of pixels is exact.
//  in the case of even pixels, we have one more pixel than
//  needed, but it cannot be displayed because it is outside
//  the drawing box.
//
//  We divide by 2 because two pixels are represented by three bytes.
//  So we work through the rectangle two pixels at a time.
//
//  4.  Now a simple memory write loop will fill the rectangle
//
//  for (i = 0; i < ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 1); i++) {
//   SPI_Send(false,(color >> 4) & 0xFF);
//  SPI_Send(false,((color & 0xF) << 4) | ((color >> 8) & 0xF));
//   SPI_Send(false,color & 0xFF);
//   }
//
//
//  In the case of an unfilled rectangle, drawing four lines with the Bresenham line
//  drawing algorithm is reasonably efficient.
//
//
//   Author:  James P Lynch      August 30, 2007
//  *****************************************************************************************
void LCD_DrawRect(const uint8_t x0, const uint8_t y0, const uint8_t x1, const uint8_t y1, const uint8_t fill, const uint16_t color)
{

    int xmin, xmax, ymin, ymax;
    int i;

    // check if the rectangle is to be filled
    if (fill != 0) {

        // best way to create a filled rectangle is to define a drawing box
        // and loop two pixels at a time

        // calculate the min and max for x and y directions
        xmin = (x0 <= x1) ? x0 : x1;
        xmax = (x0 > x1) ? x0 : x1;
        ymin = (y0 <= y1) ? y0 : y1;
        ymax = (y0 > y1) ? y0 : y1;

        // specify the controller drawing box according to those limits
        /*
                // Row address set  (command 0x2B)
                SPI_Send(true,LCDCMD_PASET);
                SPI_Send(false,xmin);
                SPI_Send(false,xmax);

                // Column address set  (command 0x2A)
                SPI_Send(true,LCDCMD_CASET);
                SPI_Send(false,ymin);
                SPI_Send(false,ymax);
        */
        LCD_SetXYXY(xmin,ymin,xmax,ymax);

        // WRITE MEMORY
        SPI_Send(true,LCDCMD_RAMWR);

        // loop on total number of pixels / 2
        for (i = 0; i < ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 130); i++) {

            // use the color value to output three data bytes covering two pixels
            SPI_Send(false,(color >> 4) & 0xFF);
            SPI_Send(false,((color & 0xF) << 4) | ((color >> 8) & 0xF));
            SPI_Send(false,color & 0xFF);
        }
    } else {

        // best way to draw un unfilled rectangle is to draw four lines
        LCD_DrawLine(x0, y0, x1, y0, color);
        LCD_DrawLine(x0, y1, x1, y1, color);
        LCD_DrawLine(x0, y0, x0, y1, color);
        LCD_DrawLine(x1, y0, x1, y1, color);
    }
}


void LCD_write(unsigned char *buff)
{
    // along al the string we need to send
    while(*buff !=0) {
        if (*buff =='\n') {                                    // if char is a return
            Lcd_col = 1;
            Lcd_row+=LCD_MEDIUM_CHAR_HEIGHT;                   // jump to next line
            if(Lcd_row > (lcd_height-1) - LCD_MEDIUM_CHAR_HEIGHT) {
                ;    //or go back
            }
        } else {
            LCD_PutChar(*buff, Lcd_row, Lcd_col, 1, BLACK, WHITE); // plot char from current lcd cursor pos
            Lcd_col+=LCD_MEDIUM_CHAR_WIDTH;
            if (Lcd_col > (lcd_width-1) -  LCD_MEDIUM_CHAR_WIDTH) {
                Lcd_col = 1;                                       // if end of line
                Lcd_row+=LCD_MEDIUM_CHAR_HEIGHT;                   // jump to next line
                if(Lcd_row > lcd_height - LCD_MEDIUM_CHAR_HEIGHT) { //or go back
                    Lcd_row = 1;    // to top of screen
                }
            }
        }
        buff++;
    }
}


void LCD_Printf (const char *fmt, ...)
{
    va_list valist;
    char buf[256];

    va_start(valist, fmt);
    vsnprintf(buf, sizeof(buf), fmt, valist);
    va_end(valist);
    LCD_write ((unsigned char *)buf);
}



//  *****************************************************************************
//    LCDPutChar.c
//
//     Draws an ASCII character at the specified (x,y) address and color
//
//    Inputs:  c       =   character to be displayed
//   x       =   row address (0 .. 131)
//   y       =   column address  (0 .. 131)
//   size    =   font pitch (SMALL, MEDIUM, LARGE)
//           fcolor   =   12-bit foreground color value rrrrggggbbbb
//           bcolor  =   12-bit background color value rrrrggggbbbb
//
//    Returns:   nothing
//
//  Notes:  Here's an example to display "E" at address (20,20)
//
//  LCDPutChar('E', 20, 20, MEDIUM, WHITE, BLACK);
//
//       (27,20)       (27,27)
//  |             |
//  |             |
//      ^ V             V
//      :  _ # # # # # # #   0x7F
//      :  _ _ # # _ _ _ #   0x31
//      :  _ _ # # _ # _ _   0x34
//      x  _ _ # # # # _ _   0x3C
//      :  _ _ # # _ # _ _   0x34
//      :  _ _ # # _ _ _ #   0x31
//      :  _ # # # # # # #   0x7F
//      :  _ _ _ _ _ _ _ _   0x00
//  ^             ^
//  |             |
//  |             |
//      (20,20)       (20,27)
//
//         ------y----------->
// //
//  The most efficient way to display a character is to make use of the "wrap-around" feature
//  of the Epson S1D16G00 LCD controller chip.
//
//  Assume that we position the character at (20, 20)  that's a  (row, col) specification.
//  With the row and column address set commands, you can specify an 8x8 box for the SMALL and MEDIUM
//  characters or a 16x8 box for the LARGE characters.
//
//  SPI_Send(true,LCDCMD_PASET); // set the row drawing limits
//   SPI_Send(false,20);  //
//   SPI_Send(false,27); // limit rows to (20, 27)
//
//  SPI_Send(true,LCDCMD_CASET); // set the column drawing limits
//   SPI_Send(false,20);  //
//   SPI_Send(false,27); // limit columns to (20,27)
//
//  When the algorithm completes col 27, the column address wraps back to 20
//  At the same time, the row address increases by one (this is done by the controller)
//
//  We walk through each row, two pixels at a time. The purpose is to create three
//  data bytes representing these two pixels in the following format
//
//  Data for pixel 0:  RRRRGGGGBBBB
//  Data for Pixel 1:  RRRRGGGGBBBB
//
//  SPI_Send(true,LCDCMD_RAMWR); // start a memory write (96 data bytes to follow)
//
//  SPI_Send(false,RRRRGGGG); // first pixel, red and green data
//  SPI_Send(false,BBBBRRRR); // first pixel, blue data; second pixel, red data
//  SPI_Send(false,GGGGBBBB); // second pixel, green and blue data
//    :
//     and so on until all pixels displayed!
//    :
//  SPI_Send(true,NOP); // this will terminate the LCDCMD_RAMWR command
//
//
//   Author:  James P Lynch    August 30, 2007
//  *****************************************************************************
void LCD_PutChar(char c, int  x, int  y, int size, int fColor, int bColor)
{

    extern const unsigned char FONT6x8[97][8];
    extern const unsigned char FONT8x8[97][8];
    extern const unsigned char FONT8x16[97][16];

    int    i,j;
    unsigned int nCols;
    unsigned int nRows;
    unsigned int nBytes;
    unsigned char PixelRow;
    unsigned char Mask;
    unsigned int Word0;
    unsigned int Word1;
    unsigned char *pFont;
    unsigned char *pChar;
    unsigned char *FontTable[] = {(unsigned char *)FONT6x8, (unsigned char *)FONT8x8,
                                  (unsigned char *)FONT8x16
                                 };

// get pointer to the beginning of the selected font table
    pFont = (unsigned char *)FontTable[size];

// get the nColumns, nRows and nBytes
    nCols = *pFont;
    nRows = *(pFont + 1);
    nBytes = *(pFont + 2);
// get pointer to the last byte of the desired character
    pChar = pFont + (nBytes * (c - 0x1F)) + nBytes - 1;

    LCD_SetXYXY( x, y, x + nRows - 1, y + nCols - 1 );

// WRITE MEMORY
    SPI_Send(true,LCDCMD_RAMWR);

// loop on each row, working backwards from the bottom to the top
    for (i = nRows - 1; i >= 0; i--) {

// copy pixel row from font table and then decrement row
        PixelRow = *pChar--;

// loop on each pixel in the row (left to right)
// Note: we do two pixels each loop
        Mask = 0x80;
        for (j = 0; j < nCols; j += 2) {

// if pixel bit set, use foreground color; else use the background color
// now get the pixel color for two successive pixels
            if ((PixelRow & Mask) == 0) {
                Word0 = bColor;
            } else {
                Word0 = fColor;
            }
            Mask = Mask >> 1;
            if ((PixelRow & Mask) == 0) {
                Word1 = bColor;
            } else {
                Word1 = fColor;
            }
            Mask = Mask >> 1;

// use this information to output three data bytes
            SPI_Send(false,(Word0 >> 4) & 0xFF);
            SPI_Send(false,((Word0 & 0xF) << 4) | ((Word1 >> 8) & 0xF));
            SPI_Send(false,Word1 & 0xFF);
        }
    }
// terminate the Write Memory command
    SPI_Send(true,LCDCMD_NOP);
}

//  *************************************************************************************************
//    LCDPutStr.c
//
//     Draws a null-terminates character string at the specified (x,y) address, size and color
//
//    Inputs:  pString =   pointer to character string to be displayed
//   x       =   row address (0 .. 131)
//   y       =   column address  (0 .. 131)
//   Size    =   font pitch (0, 1, 2)
//           fColor   =   12-bit foreground color value    rrrrggggbbbb
//           bColor   =   12-bit background color value    rrrrggggbbbb
//
//
//    Returns:   nothing
//
//    Notes:  Here's an example to display "Hello World!" at address (20,20)
//
//       LCDPutChar("Hello World!", 20, 20, LARGE, WHITE, BLACK);
//
//
//   Author:  James P Lynch    August 30, 2007
//  *************************************************************************************************
void LCD_PutStr(char *pString, int  x, int  y, int Size, int fColor, int bColor)
{
    // loop until null-terminator is seen
    while (*pString != 0x00) {
        // draw the character
        LCD_PutChar(*pString++, x, y, Size, fColor, bColor);
        // advance the y position
        if (Size == 0) {
            y = y + 6;
        } else if (Size == 1) {
            y = y + 8;
        } else {
            y = y + 8;
        }

        // bail out if y exceeds 131
        if (y > 131) {
            break;
        }
    }
}

