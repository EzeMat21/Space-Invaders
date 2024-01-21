/*
 * figuras.h
 *
 *  Created on: Jan 1, 2024
 *      Author: ezema
 */

#ifndef INC_FIGURAS_H_
#define INC_FIGURAS_H_


//---------------------------------------------------FIGURA PANTALLA DE INICIO ---------------------------------------------------------------

static const unsigned char SpaceInvaders[]= {

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x3e, 0x3f, 0x07, 0x03, 0xe1, 0xfc, 0x00, 0x00, 0x7f, 0x3f, 0x8f, 0x87, 0xe3, 0xf8, 0x00,
	0x00, 0x73, 0x39, 0xcf, 0x8e, 0x73, 0x80, 0x00, 0x00, 0x31, 0x1d, 0xcf, 0x8e, 0x63, 0x80, 0x00,
	0x00, 0x3f, 0x1d, 0xcf, 0x8e, 0x03, 0xe0, 0x00, 0x00, 0x1f, 0x9d, 0xdd, 0xce, 0x07, 0xc0, 0x00,
	0x00, 0x01, 0xdf, 0x9f, 0xce, 0xe7, 0x00, 0x00, 0x00, 0x1d, 0xce, 0x1f, 0xce, 0xe7, 0x00, 0x00,
	0x00, 0x0f, 0xce, 0x18, 0xcf, 0xc7, 0xc0, 0x00, 0x00, 0x07, 0x8e, 0x18, 0xe7, 0x8f, 0xc0, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0e, 0xe6, 0xe7, 0x38, 0xfc, 0xf9, 0xf9, 0xf0, 0x06, 0x73, 0x77, 0x7c, 0xdd, 0xc1, 0xfb, 0xf0,
	0x07, 0x7f, 0x3e, 0x7c, 0xcd, 0xe3, 0xf3, 0xc0, 0x03, 0x3f, 0xbe, 0x6c, 0xdd, 0xf3, 0xe3, 0xe0,
	0x03, 0xbf, 0x9e, 0x7e, 0xdd, 0xc3, 0x66, 0xc0, 0x01, 0xdb, 0x8e, 0xe6, 0xfd, 0xf7, 0xe7, 0xc0,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


//---------------------------------------------------FIGURAS PARA EL JUEGO---------------------------------------------------------------------

static const unsigned char InvaderMiddleGfx[]=	//SSD1306_DrawBitmap(0,0,InvaderMiddleGfx,16,8,1);
{
  0b00100000,0b10000000,
  0b00010001,0b00000000,
  0b00111111,0b10000000,
  0b01101110,0b11000000,
  0b11111111,0b11100000,
  0b10111111,0b10100000,
  0b10100000,0b10100000,
  0b00011011,0b00000000
};

static const unsigned char InvaderBottomGfx[] = {	//SSD1306_DrawBitmap(0,0,InvaderBottomGfx,16,8,1);
  0b00001111,0b00000000,
  0b01111111,0b11100000,
  0b11111111,0b11110000,
  0b11100110,0b01110000,
  0b11111111,0b11110000,
  0b00111001,0b11000000,
  0b01100110,0b01100000,
  0b00110000,0b11000000
};


static const unsigned char InvaderTopGfx[]= {	//SSD1306_DrawBitmap(0,0,InvaderMiddleGfx,8,8,1);
  0b00011000,
  0b00111100,
  0b01111110,
  0b11011011,
  0b11111111,
  0b00100100,
  0b01011010,
  0b10100101
};


static const unsigned char InvaderTopGfx2[]= {
		0b00011000,
		0b00111100,
		0b01111110,
		0b11011011,
		0b11111111,
		0b01011010,
		0b10000001,
		0b01000010
};


static const unsigned char InvaderMiddleGfx2[] = {
		0b00100000,0b10000000,
		0b00010001,0b00000000,
		0b10111111,0b10100000,
		0b11111111,0b11100000,
		0b00111111,0b10000000,
		0b00100000,0b10000000,
		0b01000000,0b01000000
};


static const unsigned char InvaderBottomGfx2[] = {
		0b00001111,0b00000000,
		0b01111111,0b11100000,
		0b11111111,0b11110000,
		0b11100110,0b01110000,
		0b11111111,0b11110000,
		0b00111001,0b11000000,
		0b01000110,0b00100000,
		0b10000000,0b00010000
};


static const unsigned char nave[8] = {
  0b00011000,
  0b00011000,
  0b01011010,
  0b01011010,
  0b01111110,
  0b11111111,
  0b01100110,
  0b00100100
};


static const unsigned char nave_explotada[8] = {

		0b10000001,
		0b00001000,
		0b01001000,
		0b00001010,
		0b00101110,
		0b10011111,
		0b01100110,
		0b00100100

};

static const unsigned char explosion[] ={
		0b10010001,0b00100000,
		0b01001010,0b01000000,
		0b00100100,0b10000000,
		0b11110001,0b11100000,
		0b00100100,0b10000000,
		0b01001010,0b01000000,
		0b10010001,0b00100000,
		0b00000000,0b00000000
};


static const unsigned char AlienBombGfx[] = {
  0b10000000,
  0b01000000,
  0b10000000,
  0b01000000

};

static const unsigned char BaseGfx [] = {
		0b00011111,0b11111000,
		0b01111111,0b11111110,
		0b11111111,0b11111111,
		0b11111111,0b11111111,
		0b11111111,0b11111111,
		0b11111000,0b00011111,
		0b11100000,0b00000111,
		0b11100000,0b00000111
};

static const unsigned char game_over_figura[] = {

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x3c, 0x1c, 0x1c, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0e, 0x00, 0xe7, 0x1f, 0x7c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38,
	0x01, 0xc3, 0x9f, 0xfc, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xf9, 0xc3, 0x9c,
	0x9c, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x39, 0xff, 0x9c, 0x9c, 0xe0, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x39, 0xc3, 0x9c, 0x1c, 0xe0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x0f, 0xf9, 0xc3, 0x9c, 0x1c, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0xf9, 0xc1, 0x88, 0x1c, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xe1, 0xc3, 0x9f, 0xfc, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x38, 0x39, 0xc3, 0x9c, 0x00, 0xe1, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x39,
	0xc3, 0x9c, 0x00, 0xe1, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x39, 0xe7, 0x9f, 0xf0,
	0xe3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0xff, 0x1c, 0x00, 0xfe, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x3c, 0x1c, 0x00, 0xef, 0x80, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x1f, 0xf0, 0x18, 0x1f, 0xfc, 0xe7, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


#endif /* INC_FIGURAS_H_ */
