/**
*	Filename: texture.h
*
*	Description: Main Header for Texture class.
*
*   Version: 1/11/2018
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

typedef struct {
	/** Holds all the color values for the image*/
	GLubyte * imageData;

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

public:
	//Texture data
	TextureData * textureData;

	/**
	* Load a Targa File.
	*/
	bool LoadTGA(char* filepath);

	GLuint GetGLTexture();
};