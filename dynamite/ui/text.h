/**
*	Filename: text.h
*
*	Description: Header file for Text class
*	Version: 3/11/2018
*
*	© 2018, Jens Heukers
*/
#pragma once
#include <iostream>
#include <string>
#include "uielement.h"
#include "font.h"

class Text : public UIElement {
private:
	/// @brief the font used for the text
	Font* _font;

	/// @brief the string containing the text
	std::string _text;
public:
	/**
	* Constructor
	*/
	Text(std::string text, Vector2 position, Font* font);

	/**
	* Returns the font used
	*/
	Font* GetFont();

	/**
	* Sets the color of the text
	*/
	void SetColor(int b, int g, int r);

	/**
	* Sets the text to parameter
	*/
	void SetText(std::string text);

	/**
	* Get the text lenght
	*/
	int GetLenght();

	/**
	* Get a character at given index
	*/
	char GetChar(int index);
};