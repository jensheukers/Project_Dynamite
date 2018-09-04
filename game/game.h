/**
*	Filename: game.h
*
*	Description: GAME HEADER DESCRIPTION.
*	Version: VERSION
*
*	© 2018, YOUR COMPANY NAME
*/

#pragma once

//Forward declaration
class Core;

class Game {
private:
	Core* core;
public:
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
