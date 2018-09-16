/**
*	Filename: game.h
*
*	Description: GAME HEADER DESCRIPTION.
*	Version: VERSION
*
*	© 2018, YOUR COMPANY NAME
*/

#pragma once
#include "vector2\vector2.h"

class Core;

class Game {
protected:
	Core* core;
public:

	/**
	* Constructor
	*/
	Game() {};

	/**
	* Constructor
	*/
	Game(Core* core);

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
	* If true editor will be launched instead of game, else  false.
	*/
	static bool LaunchEditorMode() {
		return true;
	}

	/**
	* Update method gets called each frame.
	*/
	virtual void Update();
};
