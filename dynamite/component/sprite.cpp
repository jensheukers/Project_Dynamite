/**
*	Filename: sprite.cpp
*
*	Description: Main Source for Sprite Component.
*	Version: 0.3
*
*	© 2018, Jens Heukers
*/

#include "sprite.h"

SDL_Surface* Sprite::GetSurface() {
	if (this->surface == nullptr) {
		return nullptr;
	}

	return this->surface;
}

void Sprite::SetSurface(SDL_Surface* surface) {
	this->surface = surface;
}

void Sprite::GenerateTexture() {
	if (this->surface == nullptr) {
		return;
	}

	glEnable(GL_TEXTURE_2D);

	GLuint texture;
	glGenTextures(1, &texture);
	this->texture = texture;
}

GLint Sprite::GetTexture() { return this->texture; }