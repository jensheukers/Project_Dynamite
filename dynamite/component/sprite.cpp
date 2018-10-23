/**
*	Filename: sprite.cpp
*
*	Description: Main Source for Sprite Component.
*
*	� 2018, Jens Heukers
*/

#include "sprite.h"

Texture* Sprite::GetTexture() {
	if (this->texture == nullptr) {
		return nullptr;
	}

	return this->texture;
}

void Sprite::SetTexture(std::string path) {
	this->texture = ResourceManager::Instance()->GetTexture(path.c_str());

	this->texturePath = path.c_str();
}

const char* Sprite::GetSurfacePath() {
	return this->texturePath;
}

void Sprite::GenerateConvertedTexture() {
	if (this->texture == nullptr) {
		return;
	}

	GLuint texture;
	glGenTextures(0, &texture);
	this->convertedTexture = texture;
}

GLuint Sprite::GetConvertedTexture() { return this->convertedTexture; }

Component* Sprite::Copy() {
	Component* component = new Sprite();
	return component;
}


void Sprite::OnLoad(const char* data) {
	
}