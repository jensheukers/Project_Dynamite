/**
*	Filename: renderer.h
*
*	Description: Header file for Renderer class
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/

#pragma once
#include "SDL.h"
#include "jhe_main.h"
#include "component\sprite.h"
#include "entity.h"
#include "camera.h"

class Renderer {
private:
	SDL_Renderer* sdlRenderer;
	bool sdlRendererFound;
public:
	/**
	* Constructor
	*/
	Renderer();

	/**
	* Constructor
	*/
	Renderer(SDL_Renderer* sdlRenderer);

	/**
	* Sets the SDL_Renderer to given parameter
	*/
	void SetSdlRenderer(SDL_Renderer* sdlRenderer);

	/**
	* Removes the current loaded SDL_Renderer
	*/
	void RemoveSdlRenderer();

	/**
	* Returns true if renderer has a SDL_Renderer, else returns false
	*/
	bool HasSdlRenderer() { return sdlRendererFound; };

	/**
	* Sets all the properties for OpenGL Rendering, returns true if success, else returns false
	*/
	void InitOpenGL();

	/**
	* Clear the screen
	*/
	void Clear();

	/**
	* Render the sprite of the entity.
	*/
	void RenderEntity(Entity* entity, Camera* activeCamera);

	/**
	* Draw all the rendered operations on screen
	*/
	void Draw(SDL_Window* window);
};