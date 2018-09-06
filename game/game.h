/**
*	Filename: game.h
*
*	Description: GAME HEADER DESCRIPTION.
*	Version: VERSION
*
*	© 2018, YOUR COMPANY NAME
*/

#pragma once
#include "../dynamite/entity.h"

class Core;


class Game {
private:
	Core* core;
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
	* Returns the x dimension of the window
	*/
	static int GetWindowDimensionsX() {
		return 800;
	}

	/**
	* Returns the y dimension of the window
	*/
	static int GetWindowDimensionsY() {
		return 600;
	}

	/**
	* Update method gets called each frame.
	*/
	void Update();
};
