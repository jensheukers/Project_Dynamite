/**
*	Filename: resourcemanager.h
*
*	Description: Main Header for ResourceManager.
*
*	© 2018, Jens Heukers
*/


#pragma once
#include "renderer.h"
#include "texture.h"
#include <iostream>
#include <map>

class ResourceManager {
private:
	static ResourceManager* _instance;
	std::map<std::string, Texture*> textures;

	/**
	* Constructor private due to singleton
	*/
	ResourceManager() {};
public:

	/**
	* Get the ResourceManager Singleton Instance.
	*/
	static ResourceManager* Instance();

	/**
	* Returns Surface if found, otherwise creates a new entry then returns
	*/
	Texture* GetTexture(std::string path);
};