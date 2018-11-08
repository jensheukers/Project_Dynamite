/**
*	Filename: text.cpp
*
*	Description: Source file for Text class.
*
*	Version: 8/11/2018
*
*	© 2018, Jens Heukers
*/
#include "text.h"

Text::Text(Font* font) {
	this->font = font; // Set the font
	this->lenght = 0; // Set Lenght
}

void Text::SetText(std::string text) {
	if (!this->font) { // Check if we actually have a loaded font
		std::cout << "DYNAMITE ~Text~ No font loaded cannot apply text" << std::endl; // If not print error
		return; // return;
	}

	std::vector<FontChar*> characters; // Initialze new array of characters
	unsigned lenght = (unsigned)text.length(); // Get the lenght of the text
	char* string = (char*)text.c_str(); // Convert the text to a char pointer

	for (unsigned i = 0; i < lenght; i++) { // For every letter
		characters.push_back(font->GetFontCharacter(GetUnicode(string[i]))); // Get the correct character from the font
	}

	this->characters = characters; // Set the characters Vector
	this->lenght = lenght;
}

unsigned Text::GetUnicode(char character) {
	return (unsigned int)character; // Return the unicode of the character
}

unsigned Text::GetLenght() {
	return this->lenght; // Return lenght
}

FontChar* Text::GetCharacter(int index) {
	return characters[index]; // Return the character pointer at index
}

Font* Text::GetFont() {
	return this->font; // Return the font
}