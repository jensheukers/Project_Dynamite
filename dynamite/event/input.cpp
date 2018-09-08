/**
*	Filename: input.cpp
*
*	Description: Main Source file for Input class.
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/

#include "input.h"


void Input::HandleKeys() {
	for (int i = 0; i < keys.size(); i++) {
		keys[i] = false;
		keysLast[i] = keys[i];
	}
}

void Input::HandleKeyEvent(SDL_Keycode key) {
	keys[key] = true;
}

bool Input::KeyPressed(SDL_Keycode key) {
	if (keys[key] && !keysLast[key]) {
		return true;
	}
	return false;
}

bool Input::KeyDown(SDL_Keycode key) {
	return keys[key];
}

bool Input::KeyUp(SDL_Keycode key) {
	if (!keys[key] && keysLast[key]) {
		return true;
	}
	return false;
}