/**
*	Filename: font.h
*
*	Description: Header file for Font class.
*				 Basic Bitmap font loading and rendering.
*
*				 All fonts can be generated using Codehead's bitmap font generator (http://www.codehead.co.uk/cbfg/) 				
*				 Export as TGA32 & CSV
*
*	Version: 8/11/2018
*
*	© 2018, Jens Heukers
*/
#pragma once
#include "../texture.h"
#include "../renderer.h"

struct FontChar {
	int ascii; /// @brief The ascii value of the character 
	int width; /// @brief The width of the character in pixels
	int height; ///@brief The height of the character in pixels
	UVData uvData; /// @brief the UV data of the character
};

class Font : public Texture {
private:
	int* widths; /// @brief array of widths (amount of space between character for each character)
	int celWidth; ///@brief the width of the cel's
	int celHeight; ///@brief the Height of the cel's
	int startChar; ///@brief the ascii index of the first character of the font image
	std::string fontName; ///@brief the name of the font used

	std::vector<FontChar*> fontCharacters; ///@brief vector containing all font characters

	/**
	* Read the CSV File that is generated
	*/
	bool ReadCSVFile(std::string path);
public:

	/**
	* Constructor
	*/
	Font(std::string texturePath, std::string csvPath);

	/**
	* Get the character at given ASCII index
	*/
	FontChar* GetFontCharacter(int ascii);

	/**
	* Destructor
	*/
	~Font();
};