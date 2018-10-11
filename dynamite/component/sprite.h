/**
*	Filename: sprite.h
*
*	Description: Main header for Sprite Component, Texture has to be generated by the renderer
*
*	� 2018, Jens Heukers
*/


#pragma once
#include "component.h"
#include "../math/vector2.h"
#include "../resourcemanager.h"
#include "../core.h"
#include "SDL.h"
#include "SDL_opengl.h"

class Sprite : public Component {
private:
	const char* surfacePath;
	SDL_Surface* surface;
	Vector2 scale;
	GLint texture;
public:
	/**
	* Default Constructor
	*/
	Sprite() { this->typeName = typeid(*this).name(); this->scale = Vector2(1, 1); this->surface = nullptr; };

	/**
	* Returns the surface if found, returns nullptr if failed
	*/
	SDL_Surface* GetSurface();
	
	/**
	* Creates a new surface, by loading image bmp file
	*/
	void SetSurface(const char* path);

	const char* GetSurfacePath();

	/**
	* Generates the texture 
	*/
	void GenerateTexture();

	/**
	* Returns the texture if generated
	*/
	GLint GetTexture();

	/**
	* Sets the scale of the sprite
	*/
	void SetScale(Vector2 scale) {

		if (scale.GetX() < 0) {
			scale = Vector2(0,scale.GetY());
		}

		if (scale.GetY() < 0) {
			scale = Vector2(scale.GetX(), 0);
		}

		this->scale = scale;
	}

	/**
	* Gets the scale of the sprite
	*/
	Vector2 GetScale() { return this->scale; };

	/**
	* Increases the scale by 0.01f
	*/
	void IncreaseScale() {
		SetScale(Vector2(GetScale().GetX() + 0.01f, GetScale().GetY() + 0.01f));
	}

	/**
	* Decreases the scale by 0.01f
	*/
	void DecreaseScale() {
		SetScale(Vector2(GetScale().GetX() - 0.01f, GetScale().GetY() - 0.01f));
	}

	Component* Copy();
	void OnLoad(const char* data);

};