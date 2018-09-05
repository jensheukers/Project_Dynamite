/**
*	Filename: core.h
*
*	Description: Core engine class, the 'heart' of the engine
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/
#pragma once

#include "../game/game.h"
#include "renderer.h"
#include "jhe_main.h"
#include "SDL.h"
#include "entity.h";

#undef main

class Core {
private:
	std::string mainDirPath;
	Game* game;
	Renderer* renderer;
	SDL_Window* window;
	SDL_Surface* screenSurface;
	bool running;
	Array<Entity*> entities;
public:

	/**
	* Constructor
	*/
	Core(char* arguments[]);

	/**
	* Returns the executable directory path
	*/
	std::string GetMainDirPath() { return this->mainDirPath; };

	/**
	* Handles events required to be updated each frame
	*/
	void HandleFrames();

	/**
	* Handles all the entities
	*/
	void HandleEntities();

	/**
	* Handles all the events
	*/
	void HandleEvents();

	/**
	* Returns true if engine is running, otherwise returns false
	*/
	bool IsRunning() { return this->running; };

	/**
	* Adds a new entity to the entitites Array
	*/
	void AddEntity(Entity* entity);

	/**
	* Removes entity from the entitites Array where index matches Array Index
	*/
	void RemoveEntity(int index);

	/**
	* Returns entity from the entitites Array where index matches Array Index
	*/
	Entity* GetEntity(int index);
};




