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
#include "editor.h"
#include "event/input.h"
#include "renderer.h"
#include "resourcemanager.h"
#include "scenemanager.h"

#include "camera.h"

#undef main

class Core {
private:
	std::string mainDirPath;

	SceneManager* sceneManager;
	Renderer* renderer;
	ResourceManager* resourceManager;
	Input* input;
	Game* game;

	SDL_Window* window;
	SDL_Surface* screenSurface;

	bool running;
	bool commandPromptActive;

	bool LastFrameTime;

	Camera* activeCamera;

	std::map<std::string, Component*> componentTypes;
public:

	/**
	* Adds a type to the component types list, Please note that component has to be derived
	* from the Component data type. And are made to be used for the in-build component system.
	* if base is not Component an error will be given.
	*/
	template<typename T> 
	void AddComponentType() { 
		if (!std::is_base_of<Component, T>::value) {
			printf("DYNAMITE: ~Core~ ERROR: Type is not derived from Component, cannot add to componentTypes List\n");
			return;
		}
		
		componentTypes[typeid(T).name()] = new T();
		printf("DYNAMITE: ~Core~ Added %s to componentTypes\n",typeid(T).name());
		return;
	};


	/**
	* Returns the component type pointer that equals type parameter. 
	* Please note that a dynamic cast is required in order to re-achieve your type
	*/
	Component* GetComponentType(std::string type) { return componentTypes[type]; };


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
	* Returns the resource manager
	*/
	ResourceManager* GetResourceManager() { return this->resourceManager; };

	/**
	* Calls input->KeyPressed Method, returns value.
	*/
	bool GetKeyPressed(int keyCode) { return input->KeyPressed(keyCode); };

	/**
	* Calls input->KeyDown Method, returns value.
	*/
	bool GetKeyDown(int keyCode) { return input->KeyDown(keyCode); };

	/**
	* Calls input->KeyUp Method, returns value.
	*/
	bool GetKeyUp(int keyCode) { return input->KeyUp(keyCode); };
	
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
	void AddAxis(std::string name, int positive, int negative) { input->AddAxis(name, positive, negative); };

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

	/**
	* Returns the scene manager.
	*/
	SceneManager* GetSceneManager() { return sceneManager; };
};