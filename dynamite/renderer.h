/**
*	Filename: renderer.h
*
*	Description: Header file for Renderer class
*	Version: 8/11/2018
*
*	© 2018, Jens Heukers
*/

#pragma once
#include "SDL.h"
#include "texture.h"
#include "math\vector2.h"

class Font; ///@brief forward declaration
struct FontChar; ///@brief forward declaration
class Text; ///@brief forward declaration

/**
* Basic structure for rgb color
*/
struct ColorRGB {
	unsigned r, g, b;
	ColorRGB(int r, int g, int b);
}; 

/**
* Basic structure for rgba color
*/
struct ColorRGBA {
	unsigned r, g, b, a;
	ColorRGBA(int r, int g, int b, int a);
}; 

/**
* Structure containing UV Data that is used for rendering
*/
struct UVData {
	Vector2 _leftUp;
	Vector2 _rightUp;
	Vector2 _rightDown;
	Vector2 _leftDown;

	UVData();
	UVData(Vector2 _leftUp, Vector2 _rightUp, Vector2 _rightDown, Vector2 _leftDown);
};


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
	* Renders a texture to the current rendering object
	*/
	void RenderTexture(Texture* texture, Vector2 position, Vector2 scale, float rotation, UVData uvData);

	/**
	* Renders a cube of lines to the screen
	*/
	void RenderCube(Vector2 position, Vector2 bounds, ColorRGB color);

	/**
	* Renders text on screen
	*/
	void RenderText(Text* text);

	/**
	* Render a character using texture at position
	*/
	void RenderLetter(FontChar* character, Texture* texture, Vector2 position, float rotation);

	/**
	* Draw all the rendered operations on screen
	*/
	void Draw(SDL_Window* window);
};