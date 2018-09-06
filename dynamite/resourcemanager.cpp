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

SDL_Surface* ResourceManager::GetSurface(std::string path) {

	//Search if surface already exists
	if (surfaces[path] != NULL) {
		printf("DYNAMITE: ~ResourceManager~ Surface Found!\n");
		return surfaces[path];
	}
	

	printf("DYNAMITE: ~ResourceManager~ Surface not found, Attempting to create surface : %s\n", path.c_str());
	//else create a new surface
	SDL_Surface* surface = SDL_LoadBMP(path.c_str());

	if (surface == NULL) {
		printf("DYNAMITE: ~ResourceManager~ Surface could not be created error: %s\n", SDL_GetError());
		return nullptr;
	}
	else {
		printf("DYNAMITE: ~ResourceManager~ Surface created!\n");

		surfaces[path] = surface;

		return surface;
	}
	return nullptr;
}

SDL_Texture* ResourceManager::GetTexture(std::string path) {
	if (textures[path] != NULL) {
		printf("DYNAMITE: ~ResourceManager~ Texture Found!\n");
		return textures[path];
	}
	else {
		SDL_Texture* texture = renderer->CreateTextureFromSurface(GetSurface(path));

		textures[path] = texture;
		return texture;
	}
	return nullptr;
}