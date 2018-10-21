/**
*	Filename: game.h
*
*	Description: GAME HEADER DESCRIPTION.
*	Version: VERSION
*
*	© 2018, YOUR COMPANY NAME
*/

#pragma once
#include "..\dynamite\math\vector2.h"

class Core;

class Game {
protected:

public:
	/* Specifies if colliders should be drawn to the screen**/
	static const bool DEBUG_SHOW_COLLIDERS = false;

	/**
	* Constructor
	*/
	Game();

	/**
	* Returns the game title
	*/
	static const char* GetGameName() {
		return "Project Dynamite";
	}

	/**
	* Returns the dimensions of the window.
	*/
	static Vector2 GetWindowDimensions() {
		return Vector2(1080,720);
	}

	/**
	* Update method gets called each frame.
	*/
	virtual void Update();
};
