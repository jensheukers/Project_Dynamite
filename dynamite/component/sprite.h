/**
*	Filename: sprite.h
*
*	Description: Main header for Sprite Component, Texture has to be generated by the renderer
*	Version: 0.3
*
*	� 2018, Jens Heukers
*/


#pragma once
#include "component.h"
#include "SDL.h"

class Sprite : public Component {
private:
	SDL_Texture* texture;
	SDL_Surface* surface;
	const char* sourcePath;
public:
	/**
	* Default Constructor
	*/
	Sprite() { this->typeName = typeid(*this).name(); this->sourcePath = ""; };

	/**
	* Returns the surface if found, returns nullptr if failed
	*/
	SDL_Surface* GetSurface();

	/**
	* Returns the texture if found, returns nullptr if failed
	*/
	SDL_Texture* GetTexture();

	/**
	* Returns the source path
	*/
	const char* GetSourcePath();

	/**
	* Creates a new surface, by loading image bmp file
	*/
	void SetSurface(SDL_Surface* path);

	/**
	* Sets the texture to parameter given
	*/
	void SetTexture(SDL_Texture* texture);
};