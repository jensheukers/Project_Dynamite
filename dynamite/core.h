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
	static Core* _instance;

	std::string mainDirPath;

	Game* game;

	SDL_Window* window;
	SDL_Surface* screenSurface;

	bool running;

	Camera* activeCamera;

	/** Start time in milliseconds */
	unsigned timeStart;

	/** Current time in milliseconds */
	unsigned timeCurrent;

	/** Time elapsed in milliseconds */
	unsigned timeElapsed;

	/** The amount of frames calculated in the last second*/
	unsigned framesPerSecond;

public:
	typedef std::chrono::high_resolution_clock Time;

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
	* Sets the current active camera.
	*/
	void SetActiveCamera(Camera* camera) { this->activeCamera = camera; };

	/**
	* Returns the active camera.
	*/
	Camera* GetActiveCamera() { return this->activeCamera; };

	/**
	* Removes the active camera.
	*/
	void RemoveActiveCamera() { this->activeCamera = nullptr; };

	/**
	* Returns true if a active camera is present, else returns false
	*/
	bool HasActiveCamera();

	unsigned GetFPS() { return this->framesPerSecond; };
};