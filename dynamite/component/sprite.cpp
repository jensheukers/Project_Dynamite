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

SDL_Texture* Sprite::GetTexture() {
	if (this->texture == nullptr) {
		return nullptr;
	}

	return this->texture;
}

const char* Sprite::GetSourcePath() {
	return this->sourcePath;
}

void Sprite::SetSurface(SDL_Surface* surface) {
	this->surface = surface;
}

void Sprite::SetTexture(SDL_Texture* texture) {
	this->texture = texture;
}