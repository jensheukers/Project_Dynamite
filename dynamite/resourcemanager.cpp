/**
*	Filename: resourcemanager.cpp
*
*	Description: Main Source for ResourceManager.
*
*	© 2018, Jens Heukers
*/

#include "resourcemanager.h"
#include "texture.h"
#include "ui/font.h"

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


bool ResourceManager::AddFont(std::string tag,std::string bitmapPath, std::string csvFile) {
	Font* font = new Font(bitmapPath,csvFile); // Attempt to create the font

	if (!font) { // If failure
		std::cout << "DYNAMITE ~ResourceManager~ Failed to create font" << std::endl; // Print error
		return false; // Return
	}

	fonts[tag] = font; // add font to map
}

bool ResourceManager::HasFont(std::string tag) {
	if (fonts[tag]) { // If tag found
		return true; // return true
	}
	return false; // else return false
}

Font* ResourceManager::GetFont(std::string tag) {
	if (HasFont(tag)) { // If HasTag()
		return fonts[tag]; // return font
	}
	return nullptr; // else return nullptr
}