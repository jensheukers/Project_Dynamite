#include "texture.h"

bool Texture::LoadTGA(char* filepath) {
	FILE* fTGA; //Declare file pointer
	fTGA = fopen(filepath, "rb"); //Open file for reading

	if (fTGA == NULL) { //If error was found..
		std::cout << "DYNAMITE: ~Texture~ Could not open: " << filepath << std::endl; //Print error
		return false; //Return false
	}

	if (fread(&header, sizeof(header), 1, fTGA) == 0) { //If failure to read file header
		std::cout << "DYNAMITE: ~Texture~ Error reading file header: " << filepath << std::endl; //Print error
		return false; //Return false
	}

	textureData = new TextureData();
	if (fread(targa.header, sizeof(targa.header), 1, fTGA) == 0) { //Attempt to read next 6 bytes
		std::cout << "DYNAMITE: ~Texture~ Error reading TGA: " << filepath << std::endl; //Print error
		return false; // Return false
	}

	textureData->width = targa.header[1] * 256 + targa.header[0]; //Calculate height
	textureData->height = targa.header[3] * 256 + targa.header[2]; //Calculate width
	textureData->bpp = targa.header[4];
	targa.width = textureData->width;
	targa.height = textureData->height;
	targa.bpp = textureData->bpp;

	if ((textureData->width <= 0) || (textureData->height <= 0) || ((textureData->bpp != 24) && (textureData->bpp != 32))) { 	// Make Sure All Information Is Valid
		std::cout << "DYNAMITE: ~Texture~ Targa data is invalid! : " << filepath << std::endl; //Print error
		return false;               // Return False
	}

	if (textureData->bpp == 32) { // if its a 32bpp image
		textureData->type = GL_RGBA; //Set type to RGBA
	}
	else { // else it must be 24bpp Image
		textureData->type = GL_RGB; //Set type to RGB
	}

	targa.bytesPerPixel = (targa.bpp / 8); // Calculate the BYTES per pixel
	targa.imageSize = (targa.bytesPerPixel * targa.width * targa.height); //Calculate the memory needed to store the image

	textureData->imageData = (GLubyte*)malloc(targa.imageSize); //Allocate memory

	if (textureData->imageData == NULL) { // Check if imageData was allocated correctly
		std::cout << "DYNAMITE: ~Texture~ textureData was not allocated correctly : " << filepath << std::endl; //Print error
		return false; // If Not, Return False
	}

	if (fread(textureData->imageData, 1, targa.imageSize, fTGA) != targa.imageSize) { 	// Attempt To Read All The Image Data
		std::cout << "DYNAMITE: ~Texture~ cant read image data : " << filepath << std::endl; //Print error
		return false; //If we cant read the data return false
	}

	fclose(fTGA);                   // Close The File
	return true;                    // Return Success
}