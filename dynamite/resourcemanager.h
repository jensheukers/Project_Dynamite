/**
*	Filename: resourcemanager.h
*
*	Description: Main Header for ResourceManager.
*	Version: 0.2
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
	Renderer* renderer;
	std::map<std::string, SDL_Surface*> surfaces;
public:
	/**
	* Constructor
	*/
	ResourceManager(Renderer* renderer);

	/**
	* Returns Surface if found, otherwise creates a new entry then returns
	*/
	SDL_Surface* GetSurface(std::string path);
};