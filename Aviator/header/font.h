//  *********************************************************************************
//
//  Font tables for Nokia 6610 LCD Display Driver  (S1D15G00 Controller)
//
//  FONT6x8 -  SMALL font (mostly 5x7)
//  FONT8x8 -  MEDIUM font (8x8 characters, a bit thicker)
//   FONT8x16 -  LARGE font  (8x16 characters, thicker)
//
//  Note: ASCII characters 0x00 through 0x1F are not included in these fonts.
//
//  Author:  Jim Parise, James P Lynch  August 30, 2007
//  *********************************************************************************
const unsigned char FONT6x8[97][8] = {
    {0x06,0x08,0x08,0x00,0x00,0x00,0x00,0x00}, //  columns, rows, num_bytes_per_char
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, //  space 0x20
    {0x20,0x20,0x20,0x20,0x20,0x00,0x20,0x00}, //  !
    {0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x00}, //  "
    {0x50,0x50,0xF8,0x50,0xF8,0x50,0x50,0x00}, //  #
    {0x20,0x78,0xA0,0x70,0x28,0xF0,0x20,0x00}, //  $
    {0xC0,0xC8,0x10,0x20,0x40,0x98,0x18,0x00}, //  %
    {0x40,0xA0,0xA0,0x40,0xA8,0x90,0x68,0x00}, //  &
    {0x30,0x30,0x20,0x40,0x00,0x00,0x00,0x00}, //  '
    {0x10,0x20,0x40,0x40,0x40,0x20,0x10,0x00}, //  (
    {0x40,0x20,0x10,0x10,0x10,0x20,0x40,0x00}, //  )
    {0x00,0x20,0xA8,0x70,0x70,0xA8,0x20,0x00}, //  *
    {0x00,0x20,0x20,0xF8,0x20,0x20,0x00,0x00}, //  +
    {0x00,0x00,0x00,0x00,0x30,0x30,0x20,0x40}, //  ,
    {0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00}, //  -
    {0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00}, //  .
    {0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00}, //  / (forward slash)
    {0x70,0x88,0x88,0xA8,0x88,0x88,0x70,0x00}, //  0  0x30
    {0x20,0x60,0x20,0x20,0x20,0x20,0x70,0x00}, //  1
    {0x70,0x88,0x08,0x70,0x80,0x80,0xF8,0x00}, //  2
    {0xF8,0x08,0x10,0x30,0x08,0x88,0x70,0x00}, //  3
    {0x10,0x30,0x50,0x90,0xF8,0x10,0x10,0x00}, //  4
    {0xF8,0x80,0xF0,0x08,0x08,0x88,0x70,0x00}, //  5
    {0x38,0x40,0x80,0xF0,0x88,0x88,0x70,0x00}, //  6
    {0xF8,0x08,0x08,0x10,0x20,0x40,0x80,0x00}, //  7
    {0x70,0x88,0x88,0x70,0x88,0x88,0x70,0x00}, //  8
    {0x70,0x88,0x88,0x78,0x08,0x10,0xE0,0x00}, //  9
    {0x00,0x00,0x20,0x00,0x20,0x00,0x00,0x00}, //  :
    {0x00,0x00,0x20,0x00,0x20,0x20,0x40,0x00}, //  ;
    {0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x00}, //  <
    {0x00,0x00,0xF8,0x00,0xF8,0x00,0x00,0x00}, //  =
    {0x40,0x20,0x10,0x08,0x10,0x20,0x40,0x00}, //  >
    {0x70,0x88,0x08,0x30,0x20,0x00,0x20,0x00}, //  ?
    {0x70,0x88,0xA8,0xB8,0xB0,0x80,0x78,0x00}, //  @  0x40
    {0x20,0x50,0x88,0x88,0xF8,0x88,0x88,0x00}, //  A
    {0xF0,0x88,0x88,0xF0,0x88,0x88,0xF0,0x00}, //  B
    {0x70,0x88,0x80,0x80,0x80,0x88,0x70,0x00}, //  C
    {0xF0,0x88,0x88,0x88,0x88,0x88,0xF0,0x00}, //  D
    {0xF8,0x80,0x80,0xF0,0x80,0x80,0xF8,0x00}, //  E
    {0xF8,0x80,0x80,0xF0,0x80,0x80,0x80,0x00}, //  F
    {0x78,0x88,0x80,0x80,0x98,0x88,0x78,0x00}, //  G
    {0x88,0x88,0x88,0xF8,0x88,0x88,0x88,0x00}, //  H
    {0x70,0x20,0x20,0x20,0x20,0x20,0x70,0x00}, //  I
    {0x38,0x10,0x10,0x10,0x10,0x90,0x60,0x00}, //  J
    {0x88,0x90,0xA0,0xC0,0xA0,0x90,0x88,0x00}, //  K
    {0x80,0x80,0x80,0x80,0x80,0x80,0xF8,0x00}, //  L
    {0x88,0xD8,0xA8,0xA8,0xA8,0x88,0x88,0x00}, //  M
    {0x88,0x88,0xC8,0xA8,0x98,0x88,0x88,0x00}, //  N
    {0x70,0x88,0x88,0x88,0x88,0x88,0x70,0x00}, //  O
    {0xF0,0x88,0x88,0xF0,0x80,0x80,0x80,0x00}, //  P  0x50
    {0x70,0x88,0x88,0x88,0xA8,0x90,0x68,0x00}, //  Q
    {0xF0,0x88,0x88,0xF0,0xA0,0x90,0x88,0x00}, //  R
    {0x70,0x88,0x80,0x70,0x08,0x88,0x70,0x00}, //  S
    {0xF8,0xA8,0x20,0x20,0x20,0x20,0x20,0x00}, //  T
    {0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00}, //  U
    {0x88,0x88,0x88,0x88,0x88,0x50,0x20,0x00}, //  V
    {0x88,0x88,0x88,0xA8,0xA8,0xA8,0x50,0x00}, //  W
    {0x88,0x88,0x50,0x20,0x50,0x88,0x88,0x00}, //  X
    {0x88,0x88,0x50,0x20,0x20,0x20,0x20,0x00}, //  Y
    {0xF8,0x08,0x10,0x70,0x40,0x80,0xF8,0x00}, //  Z
    {0x78,0x40,0x40,0x40,0x40,0x40,0x78,0x00}, //  [
    {0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00}, //  \  (back slash)
    {0x78,0x08,0x08,0x08,0x08,0x08,0x78,0x00}, //  ]
    {0x20,0x50,0x88,0x00,0x00,0x00,0x00,0x00}, //  ^
    {0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00}, //  _
    {0x60,0x60,0x20,0x10,0x00,0x00,0x00,0x00}, //  `  0x60
    {0x00,0x00,0x60,0x10,0x70,0x90,0x78,0x00}, //  a
    {0x80,0x80,0xB0,0xC8,0x88,0xC8,0xB0,0x00}, //  b
    {0x00,0x00,0x70,0x88,0x80,0x88,0x70,0x00}, //  c
    {0x08,0x08,0x68,0x98,0x88,0x98,0x68,0x00}, //  d
    {0x00,0x00,0x70,0x88,0xF8,0x80,0x70,0x00}, //  e
    {0x10,0x28,0x20,0x70,0x20,0x20,0x20,0x00}, //  f
    {0x00,0x00,0x70,0x98,0x98,0x68,0x08,0x70}, //  g
    {0x80,0x80,0xB0,0xC8,0x88,0x88,0x88,0x00}, //  h
    {0x20,0x00,0x60,0x20,0x20,0x20,0x70,0x00}, //  i
    {0x10,0x00,0x10,0x10,0x10,0x90,0x60,0x00}, //  j
    {0x80,0x80,0x90,0xA0,0xC0,0xA0,0x90,0x00}, //  k
    {0x60,0x20,0x20,0x20,0x20,0x20,0x70,0x00}, //  l
    {0x00,0x00,0xD0,0xA8,0xA8,0xA8,0xA8,0x00}, //  m
    {0x00,0x00,0xB0,0xC8,0x88,0x88,0x88,0x00}, //  n
    {0x00,0x00,0x70,0x88,0x88,0x88,0x70,0x00}, //  o
    {0x00,0x00,0xB0,0xC8,0xC8,0xB0,0x80,0x80}, //  p  0x70
    {0x00,0x00,0x68,0x98,0x98,0x68,0x08,0x08}, //  q
    {0x00,0x00,0xB0,0xC8,0x80,0x80,0x80,0x00}, //  r
    {0x00,0x00,0x78,0x80,0x70,0x08,0xF0,0x00}, //  s
    {0x20,0x20,0xF8,0x20,0x20,0x28,0x10,0x00}, //  t
    {0x00,0x00,0x88,0x88,0x88,0x98,0x68,0x00}, //  u
    {0x00,0x00,0x88,0x88,0x88,0x50,0x20,0x00}, //  v
    {0x00,0x00,0x88,0x88,0xA8,0xA8,0x50,0x00}, //  w
    {0x00,0x00,0x88,0x50,0x20,0x50,0x88,0x00}, //  x
    {0x00,0x00,0x88,0x88,0x78,0x08,0x88,0x70}, //  y
    {0x00,0x00,0xF8,0x10,0x20,0x40,0xF8,0x00}, //  z
    {0x10,0x20,0x20,0x40,0x20,0x20,0x10,0x00}, //  {
    {0x20,0x20,0x20,0x00,0x20,0x20,0x20,0x00}, //  |
    {0x40,0x20,0x20,0x10,0x20,0x20,0x40,0x00}, //  }
    {0x40,0xA8,0x10,0x00,0x00,0x00,0x00,0x00}, //  ~
    {0x70,0xD8,0xD8,0x70,0x00,0x00,0x00,0x00}
}; //  DEL
const unsigned char FONT8x8[97][8] = {
    {0x08,0x08,0x08,0x00,0x00,0x00,0x00,0x00}, //  columns, rows, num_bytes_per_char
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, //  space 0x20
    {0x30,0x78,0x78,0x30,0x30,0x00,0x30,0x00}, //  !
    {0x6C,0x6C,0x6C,0x00,0x00,0x00,0x00,0x00}, //  "
    {0x6C,0x6C,0xFE,0x6C,0xFE,0x6C,0x6C,0x00}, //  #
    {0x18,0x3E,0x60,0x3C,0x06,0x7C,0x18,0x00}, //  $
    {0x00,0x63,0x66,0x0C,0x18,0x33,0x63,0x00}, //  %
    {0x1C,0x36,0x1C,0x3B,0x6E,0x66,0x3B,0x00}, //  &
    {0x30,0x30,0x60,0x00,0x00,0x00,0x00,0x00}, //  '
    {0x0C,0x18,0x30,0x30,0x30,0x18,0x0C,0x00}, //  (
    {0x30,0x18,0x0C,0x0C,0x0C,0x18,0x30,0x00}, //  )
    {0x00,0x66,0x3C,0xFF,0x3C,0x66,0x00,0x00}, //  *
    {0x00,0x30,0x30,0xFC,0x30,0x30,0x00,0x00}, //  +
    {0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x30}, //  ,
    {0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00}, //  -
    {0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00}, //  .
    {0x03,0x06,0x0C,0x18,0x30,0x60,0x40,0x00}, //  / (forward slash)
    {0x3E,0x63,0x63,0x6B,0x63,0x63,0x3E,0x00}, //  0  0x30
    {0x18,0x38,0x58,0x18,0x18,0x18,0x7E,0x00}, //  1
    {0x3C,0x66,0x06,0x1C,0x30,0x66,0x7E,0x00}, //  2
    {0x3C,0x66,0x06,0x1C,0x06,0x66,0x3C,0x00}, //  3
    {0x0E,0x1E,0x36,0x66,0x7F,0x06,0x0F,0x00}, //  4
    {0x7E,0x60,0x7C,0x06,0x06,0x66,0x3C,0x00}, //  5
    {0x1C,0x30,0x60,0x7C,0x66,0x66,0x3C,0x00}, //  6
    {0x7E,0x66,0x06,0x0C,0x18,0x18,0x18,0x00}, //  7
    {0x3C,0x66,0x66,0x3C,0x66,0x66,0x3C,0x00}, //  8
    {0x3C,0x66,0x66,0x3E,0x06,0x0C,0x38,0x00}, //  9
    {0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x00}, //  :
    {0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x30}, //  ;
    {0x0C,0x18,0x30,0x60,0x30,0x18,0x0C,0x00}, //  <
    {0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00}, //  =
    {0x30,0x18,0x0C,0x06,0x0C,0x18,0x30,0x00}, //  >
    {0x3C,0x66,0x06,0x0C,0x18,0x00,0x18,0x00}, //  ?
    {0x3E,0x63,0x6F,0x69,0x6F,0x60,0x3E,0x00}, //  @  0x40
    {0x18,0x3C,0x66,0x66,0x7E,0x66,0x66,0x00}, //  A
    {0x7E,0x33,0x33,0x3E,0x33,0x33,0x7E,0x00}, //  B
    {0x1E,0x33,0x60,0x60,0x60,0x33,0x1E,0x00}, //  C
    {0x7C,0x36,0x33,0x33,0x33,0x36,0x7C,0x00}, //  D
    {0x7F,0x31,0x34,0x3C,0x34,0x31,0x7F,0x00}, //  E
    {0x7F,0x31,0x34,0x3C,0x34,0x30,0x78,0x00}, //  F
    {0x1E,0x33,0x60,0x60,0x67,0x33,0x1F,0x00}, //  G
    {0x66,0x66,0x66,0x7E,0x66,0x66,0x66,0x00}, //  H
    {0x3C,0x18,0x18,0x18,0x18,0x18,0x3C,0x00}, //  I
    {0x0F,0x06,0x06,0x06,0x66,0x66,0x3C,0x00}, //  J
    {0x73,0x33,0x36,0x3C,0x36,0x33,0x73,0x00}, //  K
    {0x78,0x30,0x30,0x30,0x31,0x33,0x7F,0x00}, //  L
    {0x63,0x77,0x7F,0x7F,0x6B,0x63,0x63,0x00}, //  M
    {0x63,0x73,0x7B,0x6F,0x67,0x63,0x63,0x00}, //  N
    {0x3E,0x63,0x63,0x63,0x63,0x63,0x3E,0x00}, //  O
    {0x7E,0x33,0x33,0x3E,0x30,0x30,0x78,0x00}, //  P  0x50
    {0x3C,0x66,0x66,0x66,0x6E,0x3C,0x0E,0x00}, //  Q
    {0x7E,0x33,0x33,0x3E,0x36,0x33,0x73,0x00}, //  R
    {0x3C,0x66,0x30,0x18,0x0C,0x66,0x3C,0x00}, //  S
    {0x7E,0x5A,0x18,0x18,0x18,0x18,0x3C,0x00}, //  T
    {0x66,0x66,0x66,0x66,0x66,0x66,0x7E,0x00}, //  U
    {0x66,0x66,0x66,0x66,0x66,0x3C,0x18,0x00}, //  V
    {0x63,0x63,0x63,0x6B,0x7F,0x77,0x63,0x00}, //  W
    {0x63,0x63,0x36,0x1C,0x1C,0x36,0x63,0x00}, //  X
    {0x66,0x66,0x66,0x3C,0x18,0x18,0x3C,0x00}, //  Y
    {0x7F,0x63,0x46,0x0C,0x19,0x33,0x7F,0x00}, //  Z
    {0x3C,0x30,0x30,0x30,0x30,0x30,0x3C,0x00}, //  [
    {0x60,0x30,0x18,0x0C,0x06,0x03,0x01,0x00}, //  \  (back slash)
    {0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00}, //  ]
    {0x08,0x1C,0x36,0x63,0x00,0x00,0x00,0x00}, //  ^
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF}, //  _
    {0x18,0x18,0x0C,0x00,0x00,0x00,0x00,0x00}, //  `  0x60
    {0x00,0x00,0x3C,0x06,0x3E,0x66,0x3B,0x00}, //  a
    {0x70,0x30,0x3E,0x33,0x33,0x33,0x6E,0x00}, //  b
    {0x00,0x00,0x3C,0x66,0x60,0x66,0x3C,0x00}, //  c
    {0x0E,0x06,0x3E,0x66,0x66,0x66,0x3B,0x00}, //  d
    {0x00,0x00,0x3C,0x66,0x7E,0x60,0x3C,0x00}, //  e
    {0x1C,0x36,0x30,0x78,0x30,0x30,0x78,0x00}, //  f
    {0x00,0x00,0x3B,0x66,0x66,0x3E,0x06,0x7C}, //  g
    {0x70,0x30,0x36,0x3B,0x33,0x33,0x73,0x00}, //  h
    {0x18,0x00,0x38,0x18,0x18,0x18,0x3C,0x00}, //  i
    {0x06,0x00,0x06,0x06,0x06,0x66,0x66,0x3C}, //  j
    {0x70,0x30,0x33,0x36,0x3C,0x36,0x73,0x00}, //  k
    {0x38,0x18,0x18,0x18,0x18,0x18,0x3C,0x00}, //  l
    {0x00,0x00,0x66,0x7F,0x7F,0x6B,0x63,0x00}, //  m
    {0x00,0x00,0x7C,0x66,0x66,0x66,0x66,0x00}, //  n
    {0x00,0x00,0x3C,0x66,0x66,0x66,0x3C,0x00}, //  o
    {0x00,0x00,0x6E,0x33,0x33,0x3E,0x30,0x78}, //  p  0x70
    {0x00,0x00,0x3B,0x66,0x66,0x3E,0x06,0x0F}, //  q
    {0x00,0x00,0x6E,0x3B,0x33,0x30,0x78,0x00}, //  r
    {0x00,0x00,0x3E,0x60,0x3C,0x06,0x7C,0x00}, //  s
    {0x08,0x18,0x3E,0x18,0x18,0x1A,0x0C,0x00}, //  t
    {0x00,0x00,0x66,0x66,0x66,0x66,0x3B,0x00}, //  u
    {0x00,0x00,0x66,0x66,0x66,0x3C,0x18,0x00}, //  v
    {0x00,0x00,0x63,0x6B,0x7F,0x7F,0x36,0x00}, //  w
    {0x00,0x00,0x63,0x36,0x1C,0x36,0x63,0x00}, //  x
    {0x00,0x00,0x66,0x66,0x66,0x3E,0x06,0x7C}, //  y
    {0x00,0x00,0x7E,0x4C,0x18,0x32,0x7E,0x00}, //  z
    {0x0E,0x18,0x18,0x70,0x18,0x18,0x0E,0x00}, //  {
    {0x0C,0x0C,0x0C,0x00,0x0C,0x0C,0x0C,0x00}, //  |
    {0x70,0x18,0x18,0x0E,0x18,0x18,0x70,0x00}, //  }
    {0x3B,0x6E,0x00,0x00,0x00,0x00,0x00,0x00}, //  ~
    {0x1C,0x36,0x36,0x1C,0x00,0x00,0x00,0x00}
}; //  DEL

const unsigned char FONT8x16[97][16] = {
    {0x08,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, //  columns, rows, num_bytes_per_char
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, //  space 0x20
    {0x00,0x00,0x18,0x3C,0x3C,0x3C,0x18,0x18,0x18,0x00,0x18,0x18,0x00,0x00,0x00,0x00}, //  !
    {0x00,0x63,0x63,0x63,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, //  "
    {0x00,0x00,0x00,0x36,0x36,0x7F,0x36,0x36,0x36,0x7F,0x36,0x36,0x00,0x00,0x00,0x00}, //  #
    {0x0C,0x0C,0x3E,0x63,0x61,0x60,0x3E,0x03,0x03,0x43,0x63,0x3E,0x0C,0x0C,0x00,0x00}, //  $
    {0x00,0x00,0x00,0x00,0x00,0x61,0x63,0x06,0x0C,0x18,0x33,0x63,0x00,0x00,0x00,0x00}, //  %
    {0x00,0x00,0x00,0x1C,0x36,0x36,0x1C,0x3B,0x6E,0x66,0x66,0x3B,0x00,0x00,0x00,0x00}, //  &
    {0x00,0x30,0x30,0x30,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, //  '
    {0x00,0x00,0x0C,0x18,0x18,0x30,0x30,0x30,0x30,0x18,0x18,0x0C,0x00,0x00,0x00,0x00}, //  (
    {0x00,0x00,0x18,0x0C,0x0C,0x06,0x06,0x06,0x06,0x0C,0x0C,0x18,0x00,0x00,0x00,0x00}, //  )
    {0x00,0x00,0x00,0x00,0x42,0x66,0x3C,0xFF,0x3C,0x66,0x42,0x00,0x00,0x00,0x00,0x00}, //  *
    {0x00,0x00,0x00,0x00,0x18,0x18,0x18,0xFF,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x00}, //  +
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x30,0x00,0x00}, //  ,
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, //  -
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00}, //  .
    {0x00,0x00,0x01,0x03,0x07,0x0E,0x1C,0x38,0x70,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00}, //  / (forward slash)
    {0x00,0x00,0x3E,0x63,0x63,0x63,0x6B,0x6B,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00}, //  0  0x30
    {0x00,0x00,0x0C,0x1C,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3F,0x00,0x00,0x00,0x00}, //  1
    {0x00,0x00,0x3E,0x63,0x03,0x06,0x0C,0x18,0x30,0x61,0x63,0x7F,0x00,0x00,0x00,0x00}, //  2
    {0x00,0x00,0x3E,0x63,0x03,0x03,0x1E,0x03,0x03,0x03,0x63,0x3E,0x00,0x00,0x00,0x00}, //  3
    {0x00,0x00,0x06,0x0E,0x1E,0x36,0x66,0x66,0x7F,0x06,0x06,0x0F,0x00,0x00,0x00,0x00}, //  4
    {0x00,0x00,0x7F,0x60,0x60,0x60,0x7E,0x03,0x03,0x63,0x73,0x3E,0x00,0x00,0x00,0x00}, //  5
    {0x00,0x00,0x1C,0x30,0x60,0x60,0x7E,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00}, //  6
    {0x00,0x00,0x7F,0x63,0x03,0x06,0x06,0x0C,0x0C,0x18,0x18,0x18,0x00,0x00,0x00,0x00}, //  7
    {0x00,0x00,0x3E,0x63,0x63,0x63,0x3E,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00}, //  8
    {0x00,0x00,0x3E,0x63,0x63,0x63,0x63,0x3F,0x03,0x03,0x06,0x3C,0x00,0x00,0x00,0x00}, //  9
    {0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00}, //  :
    {0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x18,0x30,0x00,0x00}, //  ;
    {0x00,0x00,0x00,0x06,0x0C,0x18,0x30,0x60,0x30,0x18,0x0C,0x06,0x00,0x00,0x00,0x00}, //  <
    {0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00}, //  =
    {0x00,0x00,0x00,0x60,0x30,0x18,0x0C,0x06,0x0C,0x18,0x30,0x60,0x00,0x00,0x00,0x00}, //  >
    {0x00,0x00,0x3E,0x63,0x63,0x06,0x0C,0x0C,0x0C,0x00,0x0C,0x0C,0x00,0x00,0x00,0x00}, //  ?
    {0x00,0x00,0x3E,0x63,0x63,0x6F,0x6B,0x6B,0x6E,0x60,0x60,0x3E,0x00,0x00,0x00,0x00}, //  @  0x40
    {0x00,0x00,0x08,0x1C,0x36,0x63,0x63,0x63,0x7F,0x63,0x63,0x63,0x00,0x00,0x00,0x00}, //  A
    {0x00,0x00,0x7E,0x33,0x33,0x33,0x3E,0x33,0x33,0x33,0x33,0x7E,0x00,0x00,0x00,0x00}, //  B
    {0x00,0x00,0x1E,0x33,0x61,0x60,0x60,0x60,0x60,0x61,0x33,0x1E,0x00,0x00,0x00,0x00}, //  C
    {0x00,0x00,0x7C,0x36,0x33,0x33,0x33,0x33,0x33,0x33,0x36,0x7C,0x00,0x00,0x00,0x00}, //  D
    {0x00,0x00,0x7F,0x33,0x31,0x34,0x3C,0x34,0x30,0x31,0x33,0x7F,0x00,0x00,0x00,0x00}, //  E
    {0x00,0x00,0x7F,0x33,0x31,0x34,0x3C,0x34,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00}, //  F
    {0x00,0x00,0x1E,0x33,0x61,0x60,0x60,0x6F,0x63,0x63,0x37,0x1D,0x00,0x00,0x00,0x00}, //  G
    {0x00,0x00,0x63,0x63,0x63,0x63,0x7F,0x63,0x63,0x63,0x63,0x63,0x00,0x00,0x00,0x00}, //  H
    {0x00,0x00,0x3C,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00}, //  I
    {0x00,0x00,0x0F,0x06,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x3C,0x00,0x00,0x00,0x00}, //  J
    {0x00,0x00,0x73,0x33,0x36,0x36,0x3C,0x36,0x36,0x33,0x33,0x73,0x00,0x00,0x00,0x00}, //  K
    {0x00,0x00,0x78,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x33,0x7F,0x00,0x00,0x00,0x00}, //  L
    {0x00,0x00,0x63,0x77,0x7F,0x6B,0x63,0x63,0x63,0x63,0x63,0x63,0x00,0x00,0x00,0x00}, //  M
    {0x00,0x00,0x63,0x63,0x73,0x7B,0x7F,0x6F,0x67,0x63,0x63,0x63,0x00,0x00,0x00,0x00}, //  N
    {0x00,0x00,0x1C,0x36,0x63,0x63,0x63,0x63,0x63,0x63,0x36,0x1C,0x00,0x00,0x00,0x00}, //  O
    {0x00,0x00,0x7E,0x33,0x33,0x33,0x3E,0x30,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00}, //  P  0x50
    {0x00,0x00,0x3E,0x63,0x63,0x63,0x63,0x63,0x63,0x6B,0x6F,0x3E,0x06,0x07,0x00,0x00}, //  Q
    {0x00,0x00,0x7E,0x33,0x33,0x33,0x3E,0x36,0x36,0x33,0x33,0x73,0x00,0x00,0x00,0x00}, //  R
    {0x00,0x00,0x3E,0x63,0x63,0x30,0x1C,0x06,0x03,0x63,0x63,0x3E,0x00,0x00,0x00,0x00}, //  S
    {0x00,0x00,0xFF,0xDB,0x99,0x18,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00}, //  T
    {0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00}, //  U
    {0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x36,0x1C,0x08,0x00,0x00,0x00,0x00}, //  V
    {0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x6B,0x6B,0x7F,0x36,0x36,0x00,0x00,0x00,0x00}, //  W
    {0x00,0x00,0xC3,0xC3,0x66,0x3C,0x18,0x18,0x3C,0x66,0xC3,0xC3,0x00,0x00,0x00,0x00}, //  X
    {0x00,0x00,0xC3,0xC3,0xC3,0x66,0x3C,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00}, //  Y
    {0x00,0x00,0x7F,0x63,0x43,0x06,0x0C,0x18,0x30,0x61,0x63,0x7F,0x00,0x00,0x00,0x00}, //  Z
    {0x00,0x00,0x3C,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x3C,0x00,0x00,0x00,0x00}, //  [
    {0x00,0x00,0x80,0xC0,0xE0,0x70,0x38,0x1C,0x0E,0x07,0x03,0x01,0x00,0x00,0x00,0x00}, //  \  (back slash)
    {0x00,0x00,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00,0x00,0x00,0x00}, //  ]
    {0x08,0x1C,0x36,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, //  ^
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00}, //  _
    {0x18,0x18,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, //  `  0x60
    {0x00,0x00,0x00,0x00,0x00,0x3C,0x46,0x06,0x3E,0x66,0x66,0x3B,0x00,0x00,0x00,0x00}, //  a
    {0x00,0x00,0x70,0x30,0x30,0x3C,0x36,0x33,0x33,0x33,0x33,0x6E,0x00,0x00,0x00,0x00}, //  b
    {0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x60,0x60,0x60,0x63,0x3E,0x00,0x00,0x00,0x00}, //  c
    {0x00,0x00,0x0E,0x06,0x06,0x1E,0x36,0x66,0x66,0x66,0x66,0x3B,0x00,0x00,0x00,0x00}, //  d
    {0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x63,0x7E,0x60,0x63,0x3E,0x00,0x00,0x00,0x00}, //  e
    {0x00,0x00,0x1C,0x36,0x32,0x30,0x7C,0x30,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00}, //  f
    {0x00,0x00,0x00,0x00,0x00,0x3B,0x66,0x66,0x66,0x66,0x3E,0x06,0x66,0x3C,0x00,0x00}, //  g
    {0x00,0x00,0x70,0x30,0x30,0x36,0x3B,0x33,0x33,0x33,0x33,0x73,0x00,0x00,0x00,0x00}, //  h
    {0x00,0x00,0x0C,0x0C,0x00,0x1C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00,0x00,0x00,0x00}, //  i
    {0x00,0x00,0x06,0x06,0x00,0x0E,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x3C,0x00,0x00}, //  j
    {0x00,0x00,0x70,0x30,0x30,0x33,0x33,0x36,0x3C,0x36,0x33,0x73,0x00,0x00,0x00,0x00}, //  k
    {0x00,0x00,0x1C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00,0x00,0x00,0x00}, //  l
    {0x00,0x00,0x00,0x00,0x00,0x6E,0x7F,0x6B,0x6B,0x6B,0x6B,0x6B,0x00,0x00,0x00,0x00}, //  m
    {0x00,0x00,0x00,0x00,0x00,0x6E,0x33,0x33,0x33,0x33,0x33,0x33,0x00,0x00,0x00,0x00}, //  n
    {0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00}, //  o
    {0x00,0x00,0x00,0x00,0x00,0x6E,0x33,0x33,0x33,0x33,0x3E,0x30,0x30,0x78,0x00,0x00}, //  p  0x70
    {0x00,0x00,0x00,0x00,0x00,0x3B,0x66,0x66,0x66,0x66,0x3E,0x06,0x06,0x0F,0x00,0x00}, //  q
    {0x00,0x00,0x00,0x00,0x00,0x6E,0x3B,0x33,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00}, //  r
    {0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x38,0x0E,0x03,0x63,0x3E,0x00,0x00,0x00,0x00}, //  s
    {0x00,0x00,0x08,0x18,0x18,0x7E,0x18,0x18,0x18,0x18,0x1B,0x0E,0x00,0x00,0x00,0x00}, //  t
    {0x00,0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x3B,0x00,0x00,0x00,0x00}, //  u
    {0x00,0x00,0x00,0x00,0x00,0x63,0x63,0x36,0x36,0x1C,0x1C,0x08,0x00,0x00,0x00,0x00}, //  v
    {0x00,0x00,0x00,0x00,0x00,0x63,0x63,0x63,0x6B,0x6B,0x7F,0x36,0x00,0x00,0x00,0x00}, //  w
    {0x00,0x00,0x00,0x00,0x00,0x63,0x36,0x1C,0x1C,0x1C,0x36,0x63,0x00,0x00,0x00,0x00}, //  x
    {0x00,0x00,0x00,0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x3F,0x03,0x06,0x3C,0x00,0x00}, //  y
    {0x00,0x00,0x00,0x00,0x00,0x7F,0x66,0x0C,0x18,0x30,0x63,0x7F,0x00,0x00,0x00,0x00}, //  z
    {0x00,0x00,0x0E,0x18,0x18,0x18,0x70,0x18,0x18,0x18,0x18,0x0E,0x00,0x00,0x00,0x00}, //  {
    {0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00}, //  |
    {0x00,0x00,0x70,0x18,0x18,0x18,0x0E,0x18,0x18,0x18,0x18,0x70,0x00,0x00,0x00,0x00}, //  }
    {0x00,0x00,0x3B,0x6E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, //  ~
    {0x00,0x70,0xD8,0xD8,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
}; //  DEL
