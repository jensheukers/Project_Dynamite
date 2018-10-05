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
#include <vector>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl3.h"

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
	bool commandPromptActive;

	bool LastFrameTime;

	Camera* activeCamera;
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
};