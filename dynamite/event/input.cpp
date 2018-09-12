/**
*	Filename: input.cpp
*
*	Description: Main Source file for Input class.
*	Version: 0.3
*
*	© 2018, Jens Heukers
*/

#include "input.h"


void Input::Handle() {
	for (int i = 0; i < keys.size(); i++) {
		keysLast[i] = keys[i];
	}

	for (int ii = 0; ii < buttons.size(); ii++) {
		buttonsLast[ii] = buttons[ii];
	}
}

void Input::HandleKeyPressEvent(SDL_Keycode key) {
	keys[key] = true;
}

void Input::HandleKeyReleaseEvent(SDL_Keycode key) {
	keys[key] = false;
}

void Input::HandleButtonPressEvent(int button) {
	buttons[button] = true;
}

void Input::HandleButtonReleaseEvent(int button) {
	buttons[button] = false;
}

void Input::HandleMouseMotion(Vector2 position) {
	mousePosition.Set(position.GetX(), position.GetY());
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

bool Input::ButtonPressed(int buttonCode) {
	return buttons[buttonCode];
}

bool Input::ButtonDown(int buttonCode) {
	if (buttons[buttonCode] && !buttonsLast[buttonCode]) {
		return true;
	}
	return false;
}

bool Input::ButtonUp(int buttonCode) {
	if (!buttons[buttonCode] && buttonsLast[buttonCode]) {
		return true;
	}
	return false;
}

void Input::AddAxis(std::string name, KeyCode positive, KeyCode negative) {
	axises[name] = Axis(name, positive, negative);
}

float Input::GetAxis(std::string name) {
	if (KeyDown(axises[name].GetPositive())) {
		return 1;
	}

	if (KeyDown(axises[name].GetNegative())) {
		return -1;
	}

	return 0;
}

