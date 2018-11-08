/**
*	Filename: text.h
*
*	Description: Header file for Text class.
*
*	Version: 8/11/2018
*
*	© 2018, Jens Heukers
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "font.h"
#include "uielement.h"

class Text : public UIElement {
private:
	std::vector<FontChar*> characters; ///@brief Vector containing all the characters of the string
	unsigned lenght; ///@brief The lenght of the text
	Font* font; ///@brief Pointer to font used
public:
	/**
	* Constructor
	*/
	Text(Font* font);

	/**
	* Set the text to parameter
	*/
	void SetText(std::string text);

	/**
	* Get the unicode of the given character
	*/
	unsigned GetUnicode(char character);

	/**
	* Returns the lenght of the text
	*/
	unsigned GetLenght();

	/**
	* Returns the character at index
	*/
	FontChar* GetCharacter(int index);

	/**
	* Returns the font
	*/
	Font* GetFont();
};