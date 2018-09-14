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
	float scale;
public:
	/**
	* Default Constructor
	*/
	Sprite() { this->typeName = typeid(*this).name(); this->sourcePath = ""; this->scale = 1; };

	/**
	* Returns the surface if found, returns nullptr if failed
	*/
	SDL_Surface* GetSurface();

	/**
	* Returns the source path
	*/
	const char* GetSourcePath();

	/**
	* Creates a new surface, by loading image bmp file
	*/
	void SetSurface(SDL_Surface* path);

	/**
	* Sets the scale of the sprite
	*/
	void SetScale(float scale) {

		if (scale < 0) {
			this->scale = 0;
		}
		else {
			this->scale = scale;
		}
	}

	/**
	* Gets the scale of the sprite
	*/
	float GetScale() { return this->scale; };

	/**
	* Increases the scale by 0.01f
	*/
	void IncreaseScale() {
		SetScale(GetScale() + 0.01f);
	}

	/**
	* Decreases the scale by 0.01f
	*/
	void DecreaseScale() {
		SetScale(GetScale() - 0.01f);
	}
};