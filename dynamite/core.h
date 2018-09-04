/**
*	Filename: core.h
*
*	Description: Core engine class, the 'heart' of the engine
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/
#pragma once
#include "../game/game.h"

class Core {
private:
	Game* game;
public:

	/**
	* Constructor
	*/
	Core();

	/**
	* Handles events required to be updated each frame
	*/
	void HandleFrames();
};




