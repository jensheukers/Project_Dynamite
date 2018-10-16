/**
*	Filename: sprite.cpp
*
*	Description: Main Source for Sprite Component.
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

void Sprite::SetSurface(const char* path) {
	this->surface = ResourceManager::Instance()->GetSurface(path);

	this->surfacePath = path;
}

const char* Sprite::GetSurfacePath() {
	return this->surfacePath;
}

void Sprite::GenerateTexture() {
	if (this->surface == nullptr) {
		return;
	}

	GLuint* texture;
	glGenTextures(0, texture);
	this->texture = texture;
}

GLuint* Sprite::GetTexture() { return this->texture; }


Component* Sprite::Copy() {
	Component* component = new Sprite();
	return component;
}


void Sprite::OnLoad(const char* data) {
	
}