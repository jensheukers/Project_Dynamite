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
#include "event/input.h"
#include "renderer.h"
#include "resourcemanager.h"
#include "jhe_main.h"
#include "SDL.h"
#include "entity.h"
#include "camera.h"

#undef main

class Core {
private:
	std::string mainDirPath;

	Renderer* renderer;
	ResourceManager* resourceManager;
	Input* input;
	Game* game;

	SDL_Window* window;
	SDL_Surface* screenSurface;

	bool running;

	Camera* activeCamera;
	Array<Entity*> entities;
public:

	/**
	* Constructor
	*/
	Core(char* arguments[]);

	/**
	* Returns the resources directory path
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

	/**
	* Returns the resource manager
	*/
	ResourceManager* GetResourceManager() { return this->resourceManager; };

	/**
	* Calls input->KeyPressed Method, returns value.
	*/
	bool GetKeyPressed(KeyCode keyCode) { return input->KeyPressed(keyCode); };

	/**
	* Calls input->KeyDown Method, returns value.
	*/
	bool GetKeyDown(KeyCode keyCode) { return input->KeyDown(keyCode); };

	/**
	* Calls input->KeyUp Method, returns value.
	*/
	bool GetKeyUp(KeyCode keyCode) { return input->KeyUp(keyCode); };
	
	/**
	* Calls input->ButtonPressed Method, returns value.
	*/
	bool GetButtonPressed(int buttonCode) { return input->ButtonPressed(buttonCode); };

	/**
	* Calls input->ButtonDown Method, returns value.
	*/
	bool GetButtonDown(int buttonCode) { return input->ButtonDown(buttonCode); };

	/**
	* Calls input->ButtonUp Method, returns value.
	*/
	bool GetButtonUp(int buttonCode) { return input->ButtonUp(buttonCode); };

	/**
	* Calls input->AddAxis method
	*/
	void AddAxis(std::string name, KeyCode positive, KeyCode negative) { input->AddAxis(name, positive, negative); };

	/**
	* Calls input->GetAxis method, returns value
	*/
	float GetAxis(std::string name) { return input->GetAxis(name); };
	
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




