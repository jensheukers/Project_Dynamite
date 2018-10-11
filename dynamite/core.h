/**
*	Filename: core.h
*
*	Description: Core engine class, the 'heart' of the engine
*
*	© 2018, Jens Heukers
*/
#pragma once

#include "SDL.h"
#include <GL/glew.h> 
#include <iostream>
#include <chrono>
#include <vector>

#include "../game/game.h"
#include "event/input.h"
#include "renderer.h"
#include "resourcemanager.h"
#include "scenemanager.h"

#include "camera.h"

#undef main

class Core {
private:
	typedef std::chrono::high_resolution_clock Time;

	static Core* _instance;

	std::string mainDirPath;

	Game* game;

	SDL_Window* window;
	SDL_Surface* screenSurface;

	bool running;

	/** Start time in milliseconds */
	unsigned timeStart;

	/** Current time in milliseconds */
	unsigned timeCurrent;

	/** Time elapsed in milliseconds */
	unsigned timeElapsed;

	/** The amount of frames calculated in the last second*/
	unsigned framesPerSecond;

	/** The time (in milliseconds) between each console status update*/
	static const unsigned STATUS_UPDATE_INTERVAL_TIME = 2500;
public:

	/**
	* Returns the instance if found.
	*/
	static Core* Instance();

	/**
	* Constructor
	*/
	Core(char* arguments[]);

	/**
	* Returns the resources directory path, the resources directory is moved 
	* post-build to %BuildDirectory%/resources..
	*/
	std::string GetResourceDirectory();

	/**
	* Returns the full path to the resource given in parameters by name
	*/
	std::string GetResourcePath(const char* name);

	/**
	* Handles all the events
	*/
	void HandleEvents();

	/**
	* Returns true if engine is running, otherwise returns false
	*/
	bool IsRunning() { return this->running; };

	/**
	* Prints a status update every x seconds to console
	*/
	void StatusUpdate();

	/**
	* Logs a message to the console...
	*/
	static void Log(std::string string);

	/**
	* Returns the current frames per second
	*/
	unsigned GetFPS() { return this->framesPerSecond; };

	/**
	* Returns the time elapsed since program start
	*/
	unsigned GetTimeElapsed() { return this->timeElapsed; };
};