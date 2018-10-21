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
#include "../texture.h"
#include "../core.h"
#include <GL/GL.h>

class Sprite : public Component {
private:
	const char* texturePath;
	Texture* texture;
	Vector2 scale;
	GLuint convertedTexture;
public:
	/**
	* Default Constructor
	*/
	Sprite() { this->typeName = typeid(*this).name(); this->scale = Vector2(1, 1); this->texture = nullptr; };

	/**
	* Returns the surface if found, returns nullptr if failed
	*/
	Texture* GetTexture();
	
	/**
	* Creates a new surface, by loading image bmp file
	*/
	void SetTexture(const char* path);

	const char* GetSurfacePath();

	/**
	* Generates the texture 
	*/
	void GenerateConvertedTexture();

	/**
	* Returns the texture if generated
	*/
	GLuint GetConvertedTexture();

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