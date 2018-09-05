/**
*	Filename: sprite.cpp
*
*	Description: Main Source for Sprite Component.
*	Version: 0.2
*
*	© 2018, Jens Heukers
*/

#include "sprite.h"

Sprite::Sprite(const char* path) {
	this->sourcePath = path;
}

SDL_Surface* Sprite::GetSurface() {
	if (this->surface == nullptr) {
		printf("DYNAMITE: Sprite surface has to be created first, returning nullptr");
		return nullptr;
	}

	return this->surface;
}

SDL_Texture* Sprite::GetTexture() {
	if (this->texture == nullptr) {
		printf("DYNAMITE: Texture has not been created, returning nullptr");
		return nullptr;
	}

	return this->texture;
}

const char* Sprite::GetSourcePath() {
	return this->sourcePath;
}

void Sprite::CreateSurface(const char* path) {
	this->surface = SDL_LoadBMP(path);

	if (this->surface == NULL) {
		printf("DYNAMITE: Surface could not be created error: %s", SDL_GetError());
		return;
	}

	printf("DYNAMITE: Surface created!");
}

void Sprite::SetTexture(SDL_Texture* texture) {
	this->texture = texture;
}