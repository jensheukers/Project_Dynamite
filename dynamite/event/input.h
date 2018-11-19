/**
*	Filename: input.h
*
*	Description: Main Header file for Input class.
*	Version: 19/11/2018
*
*	© 2018, www.jensheukers.nl
*/


#pragma once
#include "SDL.h"
#include "..\math\vector2.h"
#include <iostream>
#include <map>

/**
* Enum containing all translations for buttons
*/
enum MouseCode {
	Left = SDL_BUTTON_LEFT,
	Right = SDL_BUTTON_RIGHT,
	Middle = SDL_BUTTON_MIDDLE,
	X1 = SDL_BUTTON_X1,
	X2 = SDL_BUTTON_X2
};

/**
* Enum containing all translations for keyboard codes
*/
enum KeyCode {
	//---------------------
	Space = SDL_SCANCODE_SPACE,
	Enter = SDL_SCANCODE_KP_ENTER,
	CapsLock = SDL_SCANCODE_CAPSLOCK,
	Backspace = SDL_SCANCODE_BACKSPACE,
	Esc = SDL_SCANCODE_ESCAPE,
	Tab = SDL_SCANCODE_TAB,
	Grave = SDL_SCANCODE_GRAVE,
	//---------------------
	//---------------------
	Delete = SDL_SCANCODE_DELETE,
	Insert = SDL_SCANCODE_INSERT,
	Home = SDL_SCANCODE_HOME,
	End = SDL_SCANCODE_END,
	PageUp = SDL_SCANCODE_PAGEUP,
	PageDown = SDL_SCANCODE_PAGEDOWN,
	PrintScreen = SDL_SCANCODE_PRINTSCREEN,
	ScrollLock = SDL_SCANCODE_SCROLLLOCK,
	PauseBreak = SDL_SCANCODE_PAUSE,
	//---------------------
	//---------------------
	LeftShift = SDL_SCANCODE_LSHIFT,
	RightShift = SDL_SCANCODE_RSHIFT,
	LeftAlt = SDL_SCANCODE_LALT,
	RightAlt = SDL_SCANCODE_RALT,
	LeftCtrl = SDL_SCANCODE_LCTRL,
	RightCtrl = SDL_SCANCODE_RCTRL,
	LGui = SDL_SCANCODE_LGUI,
	RGui = SDL_SCANCODE_RGUI,
	//---------------------
	//---------------------
	ArrowUp = SDL_SCANCODE_UP,
	ArrowDown = SDL_SCANCODE_DOWN,
	ArrowRight = SDL_SCANCODE_RIGHT,
	ArrowLeft = SDL_SCANCODE_LEFT,
	//---------------------
	//---------------------
	Numpad_0 = SDL_SCANCODE_KP_0,
	Numpad_1 = SDL_SCANCODE_KP_1,
	Numpad_2 = SDL_SCANCODE_KP_2,
	Numpad_3 = SDL_SCANCODE_KP_3,
	Numpad_4 = SDL_SCANCODE_KP_4,
	Numpad_5 = SDL_SCANCODE_KP_5,
	Numpad_6 = SDL_SCANCODE_KP_6,
	Numpad_7 = SDL_SCANCODE_KP_7,
	Numpad_8 = SDL_SCANCODE_KP_8,
	Numpad_9 = SDL_SCANCODE_KP_9,
	NumLock = SDL_SCANCODE_NUMLOCKCLEAR,
	Numpad_Devide = SDL_SCANCODE_KP_DIVIDE,
	Numpad_Multiply = SDL_SCANCODE_KP_MULTIPLY,
	Numpad_Minus = SDL_SCANCODE_KP_MINUS,
	Numpad_Plus = SDL_SCANCODE_KP_PLUS,
	Numpad_Enter = SDL_SCANCODE_KP_ENTER,
	Numpad_Dot = SDL_SCANCODE_KP_PERIOD,
	//---------------------
	//---------------------
	Plus = SDL_SCANCODE_EQUALS,
	Minus = SDL_SCANCODE_MINUS,
	LeftBracket = SDL_SCANCODE_LEFTBRACKET,
	RightBracket = SDL_SCANCODE_RIGHTBRACKET,
	BackSlash = SDL_SCANCODE_BACKSLASH,
	SemiColumn = SDL_SCANCODE_SEMICOLON,
	Aphostrove = SDL_SCANCODE_APOSTROPHE,
	Comma = SDL_SCANCODE_COMMA,
	Dot = SDL_SCANCODE_PERIOD,
	Slash = SDL_SCANCODE_SLASH,
	//---------------------
	//---------------------
	F1 = SDL_SCANCODE_F1,
	F2 = SDL_SCANCODE_F2,
	F3 = SDL_SCANCODE_F3,
	F4 = SDL_SCANCODE_F4,
	F5 = SDL_SCANCODE_F5,
	F6 = SDL_SCANCODE_F6,
	F7 = SDL_SCANCODE_F7,
	F8 = SDL_SCANCODE_F8,
	F9 = SDL_SCANCODE_F9,
	F10 = SDL_SCANCODE_F10,
	F11 = SDL_SCANCODE_F11,
	F12= SDL_SCANCODE_F12,
	//---------------------
	//---------------------
	Alpha0 = SDL_SCANCODE_0,
	Alpha1 = SDL_SCANCODE_1,
	Alpha2 = SDL_SCANCODE_2,
	Alpha3 = SDL_SCANCODE_3,
	Alpha4 = SDL_SCANCODE_4,
	Alpha5 = SDL_SCANCODE_5,
	Alpha6 = SDL_SCANCODE_6,
	Alpha7 = SDL_SCANCODE_7,
	Alpha8 = SDL_SCANCODE_8,
	Alpha9 = SDL_SCANCODE_9,
	//---------------------
	//---------------------
	A = SDL_SCANCODE_A,
	B = SDL_SCANCODE_B,
	C = SDL_SCANCODE_C,
	D = SDL_SCANCODE_D,
	E = SDL_SCANCODE_E,
	F = SDL_SCANCODE_F,
	G = SDL_SCANCODE_G,
	H = SDL_SCANCODE_H,
	I = SDL_SCANCODE_I,
	J = SDL_SCANCODE_J,
	K = SDL_SCANCODE_K,
	L = SDL_SCANCODE_L,
	M = SDL_SCANCODE_M,
	N = SDL_SCANCODE_N,
	O = SDL_SCANCODE_O,
	P = SDL_SCANCODE_P,
	Q = SDL_SCANCODE_Q,
	R = SDL_SCANCODE_R,
	S = SDL_SCANCODE_S,
	T = SDL_SCANCODE_T,
	U = SDL_SCANCODE_U,
	V = SDL_SCANCODE_V,
	W = SDL_SCANCODE_W,
	X = SDL_SCANCODE_X,
	Y = SDL_SCANCODE_Y,
	Z = SDL_SCANCODE_Z
	//---------------------
};

class Input {
private:
	//Constructor private due to singleton
	Input();

	static Input* _instance; /// @brief the singleton instance
	bool keys[284]; /// @brief all the keys currently pressed
	bool keysLast[284]; /// @brief all the keys active in last frame and not active in this frame
	bool buttons[5]; /// @brief All buttons currently pressed
	bool buttonsLast[5]; /// @brief All buttons active in last frame and not active in this frame

	Vector2 mousePosition; /// @brief The mouse position, relative to the canvas
	int _lastKey; /// @brief the last key pressed in the frame.
	int _lastButton; /// @brief the last button pressed in the frame.

	bool _keysPressed; /// @brief true if keys are pressed this frame, else fals
	bool _buttonsPressed; /// @brief true if buttons are pressed this frame, else false
public:

	/**
	* Returns the currently active Input instance
	*/
	static Input* Instance();

	/**
	* Handles all the keys, buttons each frame sets Key[Key] to KeyLast[Key] & Button[Int] to ButtonLast[Int].
	*/
	void Handle();

	/**
	* Handles KeyEvent if key is pressed.
	*/
	void HandleKeyPressEvent(int key);

	/**
	* Handles KeyEvent if key is release.
	*/
	void HandleKeyReleaseEvent(int key);

	/**
	* Handles KeyEvent if key is pressed.
	*/
	void HandleButtonPressEvent(int button);

	/**
	* Handles KeyEvent if key is release.
	*/
	void HandleButtonReleaseEvent(int button);

	/**
	* Handles the mouse motion
	*/
	void HandleMouseMotion(Vector2 position);

	/**
	* Returns true if key is down, else returns false.
	*/
	bool KeyPressed(int key);

	/**
	* Returns true if key is pressed in both this frame and last frame, else returns false.
	*/
	bool KeyDown(int key);

	/**
	* Returns true if key is up this frame and down last frame, else returns false.
	*/
	bool KeyUp(int key);

	/**
	* Returns true if button is down, else returns false.
	*/
	bool ButtonPressed(int buttonCode);

	/**
	* Returns true if button is down both in this frame and last frame, else returns false.
	*/
	bool ButtonDown(int buttonCode);

	/**
	* Returns true if key is up this frame and down last frame, else returns false.
	*/
	bool ButtonUp(int buttonCode);

	/**
	* Returns the mouse position on screen, if a camera is present, it will also include the camera position
	*/
	Vector2 GetMousePosition();

	/**
	* Returns the mouse position on screen.
	*/
	Vector2 GetMousePositionRelativeToScreen();

	/**
	* Returns the id of the last key pressed
	*/
	int GetLastKeyPressed();

	/**
	* Returns the id of the last button pressed
	*/
	int GetLastButtonPressed();

	/**
	* Returns true if keys are pressed this frame, else returns false
	*/
	bool AreKeysPressed();

	/**
	* Returns true if buttons are pressed this frame, else returns false
	*/
	bool AreButtonsPressed();

	/**
	* Returns a UTF-8 string with the character that matches the key
	*/
	const char* GetKeyName(int key);
};