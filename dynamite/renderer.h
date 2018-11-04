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
#include "component\sprite.h"
#include "ui\text.h"
#include "entity.h"
#include "camera.h"

class Renderer {
private:
	/**
	* static local instance variable
	*/
	static Renderer* _instance;

	/**
	* Private constructor due to Singleton.
	*/
	Renderer() {};
public:
	/**
	* Get the renderer singleton instance
	*/
	static Renderer* Instance();


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
	void RenderEntity(Entity* entity, bool uiElement);

	/**
	* Renders text on screen
	*/
	void RenderText(Text* text);

	/**
	* Draw all the rendered operations on screen
	*/
	void Draw(SDL_Window* window);
};