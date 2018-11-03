/**
*	Filename: font.h
*
*	Description: Header file for Font class
*	Version: 3/11/2018
*
*	© 2018, Jens Heukers
*/

#pragma once
#include <iostream>
#include <map>
#include "../texture.h"
#include "../math/vector2.h"

class Font : public Texture {
private:
	/// @brief map containing all characters with their respected indexes
	std::map<char, int> _characters;

	/// @brief the width of the characters
	int _charWidth;

public:

	/**
	* Constructor
	*/
	Font();

	/**
	* Returns a Vector containing UV Coordinates of given character
	*/
	std::vector<Vector2> GetCharacterCoordinates(char character);

	/**
	* Set the font color to parameters
	*/
	void SetColor(int b, int g, int r);
};