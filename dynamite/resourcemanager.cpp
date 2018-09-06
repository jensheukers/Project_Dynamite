/**
*	Filename: resourcemanager.cpp
*
*	Description: Main Source for ResourceManager.
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/

#include "resourcemanager.h"

ResourceManager::ResourceManager(Renderer* renderer) {
	this->renderer = renderer;
}

SDL_Surface* ResourceManager::GetSurface(const char* path) {
	//Search if surface already exists
	if (surfaces[path] != NULL) {
		return surfaces[path];
	}
	
	//else create a new surface
	SDL_Surface* surface = SDL_LoadBMP(path);

	if (surface == NULL) {
		printf("DYNAMITE: Surface could not be created error: %s\n", SDL_GetError());
		return nullptr;
	}

	printf("DYNAMITE: Surface created!\n");

	surfaces[path] = surface;

	return surface;
}

SDL_Texture* ResourceManager::GetTexture(const char* path) {
	if (textures[path] != NULL) {
		return textures[path];
	}

	SDL_Texture* texture = renderer->CreateTextureFromSurface(GetSurface(path));

	textures[path] = texture;
	return texture;
}