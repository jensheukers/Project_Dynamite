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

Texture* ResourceManager::GetTexture(std::string path, bool allocate) {

	//printf("DYNAMITE: ~ResourceManager~ Searching texture: %s\n",path.c_str());

	//Search if surface already exists
	if (textures[path] != NULL && !allocate) {
		//printf("DYNAMITE: ~ResourceManager~ Ok\n");
		return textures[path];
	}
	
	if (!allocate) {
		printf("DYNAMITE: ~ResourceManager~ Texture not found, Attempting to create texture : %s\n", path.c_str());
	}
	else {
		printf("DYNAMITE: ~ResourceManager~ Attempting to create texture : %s\n", path.c_str());
	}

	//else create a new surface
	Texture* texture = new Texture();
	texture->LoadTGA((char*)path.c_str());

	if (texture == NULL) {
		printf("DYNAMITE: ~ResourceManager~ texture could not be created error... \n");
	
		return nullptr;
	}
	else {
		printf("DYNAMITE: ~ResourceManager~ Ok\n");

		textures[path] = texture;

		return texture;
	}
	return nullptr;
}