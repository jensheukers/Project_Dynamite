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
	for (int i = 0; i < 284; i++) {
		keysLast[i] = keys[i];
	}

	for (int ii = 0; ii < buttons.size(); ii++) {
		buttonsLast[ii] = buttons[ii];
	}
}

void Input::HandleKeyPressEvent(int key) {
	keys[key] = true;
}

void Input::HandleKeyReleaseEvent(int key) {
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

bool Input::KeyPressed(int key) {
	if (keys[key] && !keysLast[key]) {
		return true;
	}
	return false;
}

bool Input::KeyDown(int key) {
	return keys[key];
}

bool Input::KeyUp(int key) {
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

void Input::AddAxis(std::string name, int positive, int negative) {
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

