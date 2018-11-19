/**
*	Filename: text.cpp
*
*	Description: Source file for Text class.
*
*	Version: 19/11/2018
*
*	© 2018, Jens Heukers
*/
#include "text.h"

Text::Text(Font* font) {
	this->font = font; // Set the font
	this->lenght = 0; // Set Lenght
	this->pixelLenght = 0; // Set Pixel Lenght
	this->height = 0;
}

void Text::SetText(std::string text) {
	if (!this->font) { // Check if we actually have a loaded font
		std::cout << "DYNAMITE ~Text~ No font loaded cannot apply text" << std::endl; // If not print error
		return; // return;
	}

	std::vector<FontChar*> characters; // Initialze new array of characters
	unsigned lenght = (unsigned)text.length(); // Get the lenght of the text
	unsigned _pixelLenght = 0; // Set the pixel lenght to 0
	char* string = (char*)text.c_str(); // Convert the text to a char pointer

	for (unsigned i = 0; i < lenght; i++) { // For every letter
		FontChar* character = font->GetFontCharacter(GetUnicode(string[i])); // Get the correct character from the font
		if ((unsigned)character->height > this->height) { // If the height of the current character is higher than the last height
			this->height = character->height; // Set height
		}

		_pixelLenght += character->width; // Add the font width to the pixel Lenght
		characters.push_back(character); // Push back the character 
	}

	this->characters = characters; // Set the characters Vector
	this->lenght = lenght; // Set lenght to lenght
	this->pixelLenght = _pixelLenght; // Set the pixel Lenght
}

void Text::Append(std::string text) {
	if (!this->font) { // Check if we actually have a loaded font
		std::cout << "DYNAMITE ~Text~ No font loaded cannot apply text" << std::endl; // If not print error
		return; // return;
	}

	unsigned lenght = (unsigned)text.length(); // Get the lenght of the text
	char* string = (char*)text.c_str(); // Convert the text to a char pointer

	for (unsigned i = 0; i < lenght; i++) { // For every letter
		FontChar* character = font->GetFontCharacter(GetUnicode(string[i])); // Get the correct character from the font
		if ((unsigned)character->height > this->height) { // If the height of the current character is higher than the last height
			this->height = character->height; // Set height
		}

		this->pixelLenght += character->width; // Add the font width to the pixel Lenght
		characters.push_back(character); // Push back the character 
	}

	this->lenght += lenght; // Add to lenght
}

void Text::RemoveLast() {
	this->characters.erase(this->characters.begin() + (this->characters.size() - 1)); // Erase the last character
	this->lenght -= 1; // Set Lenght
}

unsigned Text::GetUnicode(char character) {
	return (unsigned int)character; // Return the unicode of the character
}

unsigned Text::GetLenght() {
	return this->lenght; // Return lenght
}

unsigned Text::GetPixelLenght() {
	return this->pixelLenght; // Return pixelLenght
}

unsigned Text::GetHeight() {
	return this->height;
}

FontChar* Text::GetCharacter(int index) {
	return characters[index]; // Return the character pointer at index
}

Font* Text::GetFont() {
	return this->font; // Return the font
}

Text::~Text() {
	for (int i = 0; i < this->characters.size(); i++) {
		this->characters.erase(this->characters.begin() + i);
	}
}