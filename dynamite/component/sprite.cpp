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

const char* Sprite::GetSourcePath() {
	return this->sourcePath;
}

void Sprite::SetSurface(SDL_Surface* surface) {
	this->surface = surface;
}