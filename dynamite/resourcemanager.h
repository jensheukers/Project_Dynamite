/**
*	Filename: resourcemanager.h
*
*	Description: Main Header for ResourceManager.
*	Version: 0.1
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
	std::map<const char*, SDL_Surface*> surfaces;
	std::map<const char*, SDL_Texture*> textures;
public:
	/**
	* Constructor
	*/
	ResourceManager(Renderer* renderer);

	/**
	* Returns Surface if found, otherwise creates a new entry then returns
	*/
	SDL_Surface* GetSurface(const char* path);

	/**
	* Returns Texture if found, otherwise creates a new entry then returns NOTE: Also generates Surface if surface doesnt exist
	*/
	SDL_Texture* GetTexture(const char* path);
};