/**
*	Filename: font.cpp
*
*	Description: Source file for Font class.
*
*	Version: 8/11/2018
*
*	© 2018, Jens Heukers
*/
#include "font.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

bool Font::ReadCSVFile(std::string csvPath) {
	std::string line;
	std::ifstream csvFile(csvPath);

	if (csvFile.is_open()) {

		int i = 0; //Current Line Index
		int ii = 0; //Current Width Index;
		while (getline(csvFile, line))
		{

			//Split the data at ','
			std::stringstream ss(line);
			std::string segment;
			std::vector<std::string> segments;
			while (std::getline(ss, segment, ',')) {
				segments.push_back(segment);
			}

			if (i == 2) {
				this->celWidth = std::stoi(segments[1]); // Set cel width
			}

			if (i == 3) {
				this->celHeight = std::stoi(segments[1]); // Set cel height
			}

			if (i == 4) {
				this->startChar = std::stoi(segments[1]); // Set the starting integer
			}
			
			if (i == 5) {
				this->fontName = segments[1]; // Set the font name
			}

			if (i > 7 && ii < 256) {
				widths[ii] = std::stoi(segments[1]); //Set the widths at index ii to value
				ii++; //Increment ii
			}
			i++; //Increment i
		}
	}
	else {
		return false;
	}

	return true; //Return success
}


Font::Font(std::string texturePath, std::string csvPath) {
	this->LoadTGA((char*)texturePath.c_str()); // Load the texture

	if (this->textureData->width != this->textureData->height) { // Check if texture dimensions are equal
		std::cout << "DYNAMITE: ~Font~ Cannot load Font, texture dimensions not the same or incorrect!" << std::endl; // If not print error
		return; // Return
	}

	widths = new int[255]; // Create instance of array of integers (to store the character widths)

	if (!this->ReadCSVFile(csvPath)) { //Can we read the csv file?
		std::cout << "DYNAMITE: ~Font~ Cannot read CSV File" << std::endl; // If not print error
		delete widths;
		return; // Return
	}

	if (this->celHeight != this->celWidth) { //Does the cel height match the cel Width?
		std::cout << "DYNAMITE: ~Font~ celHeight  does not equal celWidth!" << std::endl; // If not print error
		delete widths;
		return; // Return
	}

	//Amount of chars on one horizontal (or vertical) line
	//Only have to check for cellHeight as we previously checked if the dimensions were equal
	int amountCharsOnLine = this->textureData->height / this->celHeight;

	// Index to keep track where we are iterating
	int index = this->startChar;

	//We have read the csvFile and the TGA File, we can now continue on to set all the uv data ect.
	for (int y = amountCharsOnLine - 1; y > -1; y--) { //Iterate from up to down
		for (int x = 0; x < amountCharsOnLine; x++) { //Iterate from left to right
			FontChar* fontChar = new FontChar(); // Create a new font character instance
			fontChar->ascii = index; //Set font char ASCII index to index.
			fontChar->width = this->widths[fontChar->ascii]; // Get the width of the character
			fontChar->height = this->celHeight; //Set character height to cel height
			
			float _calculatedX = (float)(x * this->celWidth) / this->textureData->width; // Calculate the X position to "texture" space and normalize between 0-1
			float _calculatedY = (float)(y * this->celWidth) / this->textureData->height; // Calculate the Y position to "texture" space and normalize between 0-1
			float _calculatedWidth = (float)fontChar->width / this->textureData->width; // Calculate the Width to "texture" space and normalize between 0-1
			float _calculatedHeight = (float)fontChar->height / this->textureData->height; // Calculate the Height to "texture" space and normalize between 0-1

			//Set the UV Data
			fontChar->uvData = UVData(
				Vector2(_calculatedX, _calculatedY + _calculatedHeight), // _LeftUp
				Vector2(_calculatedX + _calculatedWidth, _calculatedY + _calculatedHeight), // _RightUp
				Vector2(_calculatedX + _calculatedWidth, _calculatedY), // _RightDown
				Vector2(_calculatedX, _calculatedY)  // _LeftDown
			);

			this->fontCharacters.push_back(fontChar); //Add the character to the fontCharacters Array
			index++; //Increment
		}
	}

	//Cleanup
	delete widths;
}

FontChar* Font::GetFontCharacter(int ascii) {
	for (int i = 0; i < fontCharacters.size(); i++) { //For every font Character
		if (fontCharacters[i]->ascii == ascii) { // if found
			return fontCharacters[i]; // return
		}
	}

	return nullptr;
}