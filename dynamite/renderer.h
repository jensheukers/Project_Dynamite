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
};