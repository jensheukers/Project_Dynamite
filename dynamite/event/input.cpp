/**
*	Filename: input.cpp
*
*	Description: Main Source file for Input class.
*	Version: 19/11/2018
*
*	� 2018, www.jensheukers.nl
*/

#include "input.h"
#include "../scenemanager.h"

Input* Input::_instance;

Input* Input::Instance() {
	if (!_instance) {
		_instance = new Input();
	}
	return _instance;
}

Input::Input() {
	for (int i = 0; i < 285; i++) {
		keys[i] = false;
		keysLast[i] = false;
	}

	for (int ii = 0; ii < 6; ii++) {
		buttons[ii] = false;
		buttonsLast[ii] = false;
	}

	this->_keysPressed = false;
	this->_buttonsPressed = false;
}

void Input::Handle() {
	for (int i = 0; i < 285; i++) {
		keysLast[i] = keys[i];
	}

	for (int ii = 0; ii < 6; ii++) {
		buttonsLast[ii] = buttons[ii];
	}
	this->_keysPressed = false;
	this->_buttonsPressed = false;
}

void Input::HandleKeyPressEvent(int key) {
	keys[key] = true;
	this->_lastKey = key;
	this->_keysPressed = true;
	
}

void Input::HandleKeyReleaseEvent(int key) {
	keys[key] = false;
}

void Input::HandleButtonPressEvent(int button) {
	buttons[button] = true;
	this->_lastButton = button;
	this->_buttonsPressed = true;
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
	if (buttons[buttonCode] && !buttonsLast[buttonCode]) {
		return true;
	}
	return false;

}

bool Input::ButtonDown(int buttonCode) {
	return buttons[buttonCode];
}

bool Input::ButtonUp(int buttonCode) {
	if (!buttons[buttonCode] && buttonsLast[buttonCode]) {
		return true;
	}
	return false;
}

Vector2 Input::GetMousePosition() {
	if (SceneManager::Instance()->GetActiveScene()) {
		if (SceneManager::Instance()->GetActiveScene()->HasActiveCamera()) {
			return Vector2(this->mousePosition.GetX() + SceneManager::Instance()->GetActiveScene()->GetActiveCamera()->GetXCoord(),
				this->mousePosition.GetY() + SceneManager::Instance()->GetActiveScene()->GetActiveCamera()->GetYCoord());
		}
	}

	return this->mousePosition;
}

Vector2 Input::GetMousePositionRelativeToScreen() {
	return this->mousePosition;
}

int Input::GetLastKeyPressed() {
	return this->_lastKey;
}

int Input::GetLastButtonPressed() {
	return this->_lastButton;
}

bool Input::AreKeysPressed() {
	return this->_keysPressed;
}

bool Input::AreButtonsPressed() {
	return this->_buttonsPressed;
}

const char* Input::GetKeyName(int key) {
	return SDL_GetKeyName(key);
}