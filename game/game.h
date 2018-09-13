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
#include "../dynamite/entity.h"

class Core;

class Game {
private:
	Core* core;
	Entity* entity;
public:
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
	* Update method gets called each frame.
	*/
	void Update();
};
