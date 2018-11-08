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

			switch (i) { // Switch the current line
				case 2:
					this->celWidth = std::stoi(segments[1]); // Set cel width
					break;	

				case 3:
					this->celHeight = std::stoi(segments[1]); // Set cel height
					break;

				case 4:
					this->startChar = std::stoi(segments[1]); // Set the starting integer
					break;

				case 5:
					this->fontName = segments[1]; // Set the font name
					break;
			}


			if (i > 7 && ii <= 255) {
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

	if (!this->ReadCSVFile(csvPath)) { //Can we read the csv file?
		std::cout << "DYNAMITE: ~Font~ Cannot read CSV File" << std::endl; // If not print error
		return; // Return
	}

	//Amount of chars on one horizontal (or vertical) line
	//Only have to check for cellHeight as we previously checked if the dimensions were equal
	int amountCharsOnLine = this->textureData->height / this->celHeight;


	//We have read the csvFile and the TGA File, we can now continue on to set all the uv data ect.
	for (int y = 0; y < amountCharsOnLine + 1; y++) {
		for (int x = 0; x < amountCharsOnLine + 1; x++) {
			if (this->startChar + (x + (y * amountCharsOnLine)) <= 251) {
				FontChar* fontChar = new FontChar();
				fontChar->ascii = this->startChar + (x + (y * amountCharsOnLine));
				fontChar->width = widths[fontChar->ascii];
				fontChar->height = this->celHeight;

				//Handle UV data
				float _calculatedX = (float)(x * this->celHeight) / this->textureData->width;
				float _calculatedY = (float)(y * this->celHeight) / this->textureData->width;
				float _calculatedWidth = (float)widths[fontChar->ascii] / this->textureData->width;
				float _calculatedHeight = (float)this->celHeight / this->textureData->height;

				fontChar->uvData = UVData(
					Vector2(_calculatedX, _calculatedY + _calculatedHeight), // LU
					Vector2(_calculatedX + _calculatedWidth, _calculatedY + _calculatedHeight), // RU
					Vector2(_calculatedX + _calculatedWidth, _calculatedY), // RD
					Vector2(_calculatedX, _calculatedY) // LD
				);

				fontCharacters.push_back(fontChar);
			}
		}
	}
}

FontChar* Font::GetFontCharacter(int ascii) {
	return fontCharacters[ascii];
}