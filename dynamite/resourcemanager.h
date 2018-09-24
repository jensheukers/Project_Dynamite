/**
*	Filename: resourcemanager.h
*
*	Description: Main Header for ResourceManager.
*
*	© 2018, Jens Heukers
*/


#pragma once
#include "SDL.h"
#include "renderer.h"
#include <iostream>
#include <map>
class ResourceManager {
private:
	static ResourceManager* _instance;
	std::map<std::string, SDL_Surface*> surfaces;

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
	SDL_Surface* GetSurface(std::string path);
};