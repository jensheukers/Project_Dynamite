/**
*	Filename: resourcemanager.cpp
*
*	Description: Main Source for ResourceManager.
*
*	© 2018, Jens Heukers
*/

#include "resourcemanager.h"

ResourceManager* ResourceManager::_instance;

ResourceManager* ResourceManager::Instance() {
	if (!_instance) {
		_instance = new ResourceManager();
	}
	return _instance;
}

Texture* ResourceManager::GetTexture(std::string path) {

	printf("DYNAMITE: ~ResourceManager~ Searching surface: %s\n",path.c_str());

	//Search if surface already exists
	if (textures[path] != NULL) {
		printf("DYNAMITE: ~ResourceManager~ Ok\n");
		return textures[path];
	}
	

	printf("DYNAMITE: ~ResourceManager~ Surface not found, Attempting to create surface : %s\n", path.c_str());

	//else create a new surface
	Texture* texture = new Texture();
	texture->LoadTGA((char*)path.c_str());

	if (texture == NULL) {
		printf("DYNAMITE: ~ResourceManager~ Surface could not be created error: %s\n", SDL_GetError());
	
		return nullptr;
	}
	else {
		printf("DYNAMITE: ~ResourceManager~ Ok\n");

		textures[path] = texture;

		return texture;
	}
	return nullptr;
}