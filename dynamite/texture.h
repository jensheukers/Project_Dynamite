/**
*	Filename: texture.h
*
*	Description: Main Header for Texture class.
*
*   Version: 7/11/2018
*
*	© 2018, Jens Heukers
*/

#pragma once
#include <Windows.h>
#include <stdio.h>
#include "../external/glew/include/GL/glew.h"
#include "math/vector2.h"
#include <GL/GL.h>
#include <iostream>
#include <vector>

struct ColorRGB; ///@brief forward declaration

typedef struct {
	/** Holds all the color values for the image*/
	GLubyte * imageData;

	/** Holds the number of bytes per pixel*/
	GLuint bytesPerPixel;

	/** Holds the number of bits per pixel*/
	GLuint bpp;

	/** The width of the entire image*/
	GLuint width;

	/** The height of the entire image*/
	GLuint height;

	/** Texture ID for use with glBindTexture() method*/
	GLuint texId;

	/** Data stored in *ImageData (GL_RGB OR GL_RGBA)*/
	GLuint type;
} TextureData;

typedef struct {
	/** File header to determine file type*/
	GLubyte header[12];
} TGAHeader;

typedef struct {
	/** Holds the first 6 usefull bytes of the file*/
	GLubyte header[6];

	/** Number of bytes per pixel*/
	GLuint bytesPerPixel;

	/** Amount of memory needed to hold the image*/
	GLuint imageSize;

	/** The type (GL_RGB OR GL_RGBA)*/
	GLuint type;

	/** The width of the image*/
	GLuint width;

	/** The height of the image*/
	GLuint height;

	/** Number of bits per pixel*/
	GLuint bpp;
} TGA;

class Texture {
private:
	// Header
	TGAHeader header;

	// file data.
	TGA targa;

	// The pointer to the converted OpenGL texture in memory
	GLuint _glTexture;

	/**
	* Converts BGR to RGB
	*/
	void BGR2RGB();

	/**
	* Uploads the texture to the GPU, and sets the _glTexture pointer
	*/
	void UploadToGPU();

public:
	//Texture data
	TextureData * textureData;

	/**
	* Load a Targa File.
	*/
	bool LoadTGA(char* filepath);

	/**
	* Returns the OpenGL Ready Texture
	*/
	GLuint GetGLTexture();

	/**
	* Returns the channel value of pixel + offset
	*/
	int GetPixelData(int x, int y, int offset);

	/**
	* Set the color of the font
	*/
	void SetColor(ColorRGB color);
};