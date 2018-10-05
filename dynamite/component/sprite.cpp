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

	glEnable(GL_TEXTURE_2D);

	GLuint texture;
	glGenTextures(1, &texture);
	this->texture = texture;
}

GLint Sprite::GetTexture() { return this->texture; }


Component* Sprite::Copy() {
	Component* component = new Sprite();
	return component;
}


const char* Sprite::OnSave() {
	std::string tempString;
	tempString.append(this->GetSurfacePath());
	return tempString.c_str();
}

void Sprite::OnLoad(const char* data) {
	
}