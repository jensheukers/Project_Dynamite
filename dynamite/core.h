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

#include "jhe_main.h"
#include "SDL.h"

#undef main

class Core {
private:
	String* mainDirPath;
	Game* game;
	SDL_Window* window;
	SDL_Surface* screenSurface;
	bool running;
public:

	/**
	* Constructor
	*/
	Core(char* arguments[]);

	/**
	* Handles events required to be updated each frame
	*/
	void HandleFrames();

	/**
	* Handles all the events
	*/
	void HandleEvents();

	/**
	* Returns true if engine is running, otherwise returns false
	*/
	bool IsRunning() { return this->running; };
};




