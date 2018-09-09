/**
*	Filename: input.cpp
*
*	Description: Main Source file for Input class.
*	Version: 0.3
*
*	© 2018, Jens Heukers
*/

#include "input.h"


void Input::HandleKeys() {
	for (int i = 0; i < keys.size(); i++) {
		keysLast[i] = keys[i];
	}
}

void Input::HandleKeyPressEvent(SDL_Keycode key) {
	keys[key] = true;
}

void Input::HandleKeyReleaseEvent(SDL_Keycode key) {
	keys[key] = false;
}

bool Input::KeyPressed(SDL_Keycode key) {
	return keys[key];
}

bool Input::KeyDown(SDL_Keycode key) {
	if (keys[key] && !keysLast[key]) {
		return true;
	}
	return false;
}

bool Input::KeyUp(SDL_Keycode key) {
	if (!keys[key] && keysLast[key]) {
		return true;
	}
	return false;
}

void Input::AddAxis(std::string name, KeyCode positive, KeyCode negative) {
	axises[name] = Axis(name, positive, negative);
}

float Input::GetAxis(std::string name) {
	if (KeyDown(axises.at(name).GetPositive())) {
		return 1;
	}

	if (KeyDown(axises.at(name).GetNegative())) {
		return -1;
	}

	return 0;
}