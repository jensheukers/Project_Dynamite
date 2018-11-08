/**
*	Filename: texture.cpp
*
*	Description: Source file for Texture class.
*
*	Version: 8/11/2018
*
*	© 2018, Jens Heukers
*/

#include "texture.h"
#include "renderer.h"

void Texture::BGR2RGB() {
	int bufferSize = (this->textureData->width * this->textureData->height) * this->textureData->bytesPerPixel;

	for (int i = 0; i < bufferSize; i += this->textureData->bytesPerPixel) {
		int b = this->textureData->imageData[i];
		int g = this->textureData->imageData[i + 1];
		int r = this->textureData->imageData[i + 2];

		this->textureData->imageData[i] = r;
		this->textureData->imageData[i + 1] = g;
		this->textureData->imageData[i + 2] = b;
	}
}

void Texture::UploadToGPU() {
	if (_glTexture) {
		glDeleteTextures(1, &this->_glTexture); // Delete the texture if already uploaded before
	}

	glGenTextures(1, &this->_glTexture); // Generate OpenGL Ready Textures

										 // Map the surface to the texture in video memory
	glBindTexture(GL_TEXTURE_2D, this->_glTexture);

	if (textureData->type == GL_RGB) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureData->width, textureData->height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData->imageData);
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureData->width, textureData->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData->imageData);
	}

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

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

	textureData->bytesPerPixel = targa.bytesPerPixel;

	textureData->imageData = (GLubyte*)malloc(targa.imageSize); //Allocate memory

	if (textureData->imageData == NULL) { // Check if imageData was allocated correctly
		std::cout << "DYNAMITE: ~Texture~ textureData was not allocated correctly : " << filepath << std::endl; //Print error
		return false; // If Not, Return False
	}

	if (fread(textureData->imageData, 1, targa.imageSize, fTGA) != targa.imageSize) { 	// Attempt To Read All The Image Data
		std::cout << "DYNAMITE: ~Texture~ cant read image data : " << filepath << std::endl; //Print error
		return false; //If we cant read the data return false
	}

	this->BGR2RGB(); //Convert from BGR to RGB
	this->UploadToGPU();

	std::cout << "DYNAMITE: ~Texture~ created succesfully! Texture bits per pixel = " << textureData->bpp << std::endl;

	fclose(fTGA);                   // Close The File
	return true;                    // Return Success
}

GLuint Texture::GetGLTexture() {
	return this->_glTexture;
}

int Texture::GetPixelData(int x, int y, int offset) {
	if (offset > ((int)this->textureData->bytesPerPixel - 1)) {
		offset = (this->textureData->bytesPerPixel - 1);
	}

	if (offset < 0) {
		offset = 0;
	}

	int height = (y * this->textureData->width) * this->textureData->bytesPerPixel;
	int width = x * this->textureData->bytesPerPixel;

	return this->textureData->imageData[(width + height) + offset];
}

void Texture::SetColor(ColorRGB color) {
	int bufferSize = (this->textureData->height * this->textureData->width) * this->textureData->bytesPerPixel; // Get the buffer size
	for (int i = 0; i < bufferSize; i += this->textureData->bytesPerPixel) { // For every pixel
		if (this->textureData->imageData[i] == 0 && this->textureData->imageData[i + 1] == 0 && this->textureData->imageData[i + 2] == 0) { // If a pixel has no color
			continue; //Continue
		}

		this->textureData->imageData[i] = color.r; // Set Red
		this->textureData->imageData[i + 1] = color.g; // Set Green
		this->textureData->imageData[i + 2] = color.b; // Set Blue
	}

	this->UploadToGPU(); //Re-Upload the texture
}