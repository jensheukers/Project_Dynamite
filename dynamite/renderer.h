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
	* Creates a texture from surface from surface
	*/
	SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface);

	/**
	* Clear the screen
	*/
	void Clear();

	/**
	* Render the sprite of the entity.
	*/
	void RenderEntity(Entity* entity);

	/**
	* Draw all the rendered operations on screen
	*/
	void Draw();
};