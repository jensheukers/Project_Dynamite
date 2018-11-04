/**
*	Filename: font.cpp
*
*	Description: Source file for Font class
*	Version: 3/11/2018
*
*	© 2018, Jens Heukers
*/
#include "font.h"

Font::Font() {

	//Set the char width/height to 32, assuming that a char in the font image is 32 pixels by 32 pixels.
	_charWidth = 32;
	_charHeight = 32;

	//Definitly better ways to do this, so will look into in the future. For now it wil work!

	//Alfabet
	_characters['A'] = 0; 	_characters['a'] = 26;
	_characters['B'] = 1; 	_characters['b'] = 27;
	_characters['C'] = 2; 	_characters['c'] = 28;
	_characters['D'] = 3;	_characters['d'] = 29;
	_characters['E'] = 4;	_characters['e'] = 30;
	_characters['F'] = 5;	_characters['f'] = 31;
	_characters['G'] = 6;	_characters['g'] = 32;
	_characters['H'] = 7;	_characters['h'] = 33;
	_characters['I'] = 8;	_characters['i'] = 34;
	_characters['J'] = 9;	_characters['j'] = 35;
	_characters['K'] = 10;	_characters['k'] = 36;
	_characters['L'] = 11;	_characters['l'] = 37;
	_characters['M'] = 12;	_characters['m'] = 38;
	_characters['N'] = 13;	_characters['n'] = 39;
	_characters['O'] = 14;	_characters['o'] = 40;
	_characters['P'] = 15;	_characters['p'] = 41;
	_characters['Q'] = 16;	_characters['q'] = 42;
	_characters['R'] = 17;	_characters['r'] = 43;
	_characters['S'] = 18;	_characters['s'] = 44;
	_characters['T'] = 19;	_characters['t'] = 45;
	_characters['U'] = 20;	_characters['u'] = 46;
	_characters['V'] = 21;	_characters['v'] = 47;
	_characters['W'] = 22;	_characters['w'] = 48;
	_characters['X'] = 23;	_characters['x'] = 49;
	_characters['Y'] = 24;	_characters['y'] = 50;
	_characters['Z'] = 25;	_characters['z'] = 51;

	//Numbers			    Number subcharacters
	_characters['1'] = 52;	_characters['!'] = 62;
	_characters['2'] = 53;	_characters['@'] = 63;
	_characters['3'] = 54; 	_characters['#'] = 64;
	_characters['4'] = 55;	_characters['$'] = 65;
	_characters['5'] = 56;	_characters['%'] = 66;
	_characters['6'] = 57;	_characters['^'] = 67;
	_characters['7'] = 58;	_characters['&'] = 68;
	_characters['8'] = 59;	_characters['*'] = 69;
	_characters['9'] = 60;	_characters['('] = 70;
	_characters['0'] = 61;	_characters[')'] = 71;

	//Extra Characters
	_characters['`'] = 72;	_characters['['] = 78;	_characters[':'] = 84;  _characters['?'] = 90;
	_characters['~'] = 73;	_characters['{'] = 79;	_characters[','] = 85;
	_characters['-'] = 74;	_characters[']'] = 80;	_characters['<'] = 86;
	_characters['_'] = 75;	_characters['}'] = 81;	_characters['.'] = 87;
	_characters['='] = 76;	_characters['|'] = 82;	_characters['>'] = 88;
	_characters['+'] = 77;	_characters[';'] = 83;	_characters['/'] = 89;
}

std::vector<Vector2> Font::GetCharacterCoordinates(char character) {
	std::vector<Vector2> coordinates; //Initialize Vector2 vector

	int characterIndex = _characters[character]; //Get the index of the character in the image

	//Calculate and normalize the uv coordinates in the image
	Vector2 LU = Vector2((float)(characterIndex * _charWidth) / (float)this->textureData->width, 1); //Left Up
	Vector2 RU = Vector2(((float)(characterIndex * _charWidth) + 32) / (float)this->textureData->width, 1); // Right Up
	Vector2 RD = Vector2(((float)(characterIndex * _charWidth) + 32) / (float)this->textureData->width, 0); // Right Down
	Vector2 LD = Vector2((float)(characterIndex * _charWidth) / (float)this->textureData->width, 0); // Left Down

	//Push backs
	coordinates.push_back(LU);
	coordinates.push_back(RU);
	coordinates.push_back(RD);
	coordinates.push_back(LD);

	return coordinates; // Return the coordinates
}

void Font::SetColor(int b, int g, int r) {
	int pixels = this->textureData->width * this->textureData->height; // Calculate amount of pixels

	for (int i = 0; i <= pixels; i += 4) { //For every pixel
		this->textureData->imageData[i] = b; //Set Value
		this->textureData->imageData[i + 1] = g; //Set Value
		this->textureData->imageData[i + 2] = r; //Set Value
	}
}

Vector2 Font::GetCharSize()
{
	return Vector2(this->_charWidth, this->_charHeight);
}
