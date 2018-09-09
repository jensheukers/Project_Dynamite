/**
*	Filename: input.h
*
*	Description: Main Header file for Input class.
*	Version: 0.3
*
*	© 2018, Jens Heukers
*/


#pragma once
#include "SDL.h"
#include "vector2\vector2.h"
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
	Space = SDLK_SPACE,
	Enter = SDLK_KP_ENTER,
	CapsLock = SDLK_CAPSLOCK,
	Backspace = SDLK_BACKSPACE,
	Tab = SDLK_TAB,
	Escape = SDLK_ESCAPE,
	Grave = SDL_SCANCODE_GRAVE,
	//---------------------
	//---------------------
	Delete = SDLK_DELETE,
	Insert = SDLK_INSERT,
	Home = SDLK_HOME,
	End = SDLK_END,
	PageUp = SDLK_PAGEUP,
	PageDown = SDLK_PAGEDOWN,
	PrintScreen = SDLK_PRINTSCREEN,
	ScrollLock = SDLK_SCROLLLOCK,
	PauseBreak = SDLK_PAUSE,
	//---------------------
	//---------------------
	LeftShift = SDLK_LSHIFT,
	RightShift = SDLK_RSHIFT,
	LeftAlt = SDLK_LALT,
	RightAlt = SDLK_RALT,
	LeftCtrl = SDLK_LCTRL,
	RightCtrl = SDLK_RCTRL,
	LGui = SDLK_LGUI,
	RGui = SDLK_RGUI,
	//---------------------
	//---------------------
	ArrowUp = SDLK_UP,
	ArrowDown = SDLK_DOWN,
	ArrowRight = SDLK_RIGHT,
	ArrowLeft = SDLK_LEFT,
	//---------------------
	//---------------------
	Numpad_0 = SDLK_KP_0,
	Numpad_1 = SDLK_KP_1,
	Numpad_2 = SDLK_KP_2,
	Numpad_3 = SDLK_KP_3,
	Numpad_4 = SDLK_KP_4,
	Numpad_5 = SDLK_KP_5,
	Numpad_6 = SDLK_KP_6,
	Numpad_7 = SDLK_KP_7,
	Numpad_8 = SDLK_KP_8,
	Numpad_9 = SDLK_KP_9,
	NumLock = SDLK_NUMLOCKCLEAR,
	Numpad_Devide = SDLK_KP_DIVIDE,
	Numpad_Multiply = SDLK_KP_MULTIPLY,
	Numpad_Minus = SDLK_KP_MINUS,
	Numpad_Plus = SDLK_KP_PLUS,
	Numpad_Enter = SDLK_KP_ENTER,
	Numpad_Dot = SDLK_KP_PERIOD,
	//---------------------
	//---------------------
	Plus = SDLK_PLUS,
	Minus = SDLK_MINUS,
	LeftBracket = SDLK_LEFTBRACKET,
	RightBracket = SDLK_RIGHTBRACKET,
	BackSlash = SDLK_BACKSLASH,
	SemiColumn = SDLK_SEMICOLON,
	Aphostrove = SDL_SCANCODE_APOSTROPHE,
	Comma = SDLK_COMMA,
	Dot = SDLK_PERIOD,
	Slash = SDLK_SLASH,
	//---------------------
	//---------------------
	F1 = SDLK_F1,
	F2 = SDLK_F2,
	F3 = SDLK_F3,
	F4 = SDLK_F4,
	F5 = SDLK_F5,
	F6 = SDLK_F6,
	F7 = SDLK_F7,
	F8 = SDLK_F8,
	F9 = SDLK_F9,
	F10 = SDLK_F10,
	F11 = SDLK_F11,
	F12= SDLK_F12,
	//---------------------
	//---------------------
	Alpha0 = SDLK_0,
	Alpha1 = SDLK_1,
	Alpha2 = SDLK_2,
	Alpha3 = SDLK_3,
	Alpha4 = SDLK_4,
	Alpha5 = SDLK_5,
	Alpha6 = SDLK_6,
	Alpha7 = SDLK_7,
	Alpha8 = SDLK_8,
	Alpha9 = SDLK_9,
	//---------------------
	//---------------------
	A = SDLK_a,
	B = SDLK_b,
	C = SDLK_c,
	D = SDLK_d,
	E = SDLK_e,
	F = SDLK_f,
	G = SDLK_g,
	H = SDLK_h,
	I = SDLK_i,
	J = SDLK_j,
	K = SDLK_k,
	L = SDLK_l,
	M = SDLK_m,
	N = SDLK_n,
	O = SDLK_o,
	P = SDLK_p,
	Q = SDLK_q,
	R = SDLK_r,
	S = SDLK_s,
	T = SDLK_t,
	U = SDLK_u,
	V = SDLK_v,
	W = SDLK_w,
	X = SDLK_x,
	Y = SDLK_y,
	Z = SDLK_z
	//---------------------
};

class Axis {
private:
	std::string name;
	KeyCode positive;
	KeyCode negative;
public:
	Axis() {};

	/**
	* Constructor
	*/
	Axis(std::string name, KeyCode positive, KeyCode negative) {
		this->name = name;
		this->positive = positive;
		this->negative = negative;
	}

	/**
	* Returns the positive Keycode value/
	*/
	int GetPositive() { return this->positive; }

	/**
	* Returns the negative Keycode value.
	*/
	int GetNegative() { return this->negative; }
};

class Input {
private:
	std::map<std::string, Axis> axises;
	std::map<SDL_Keycode, bool> keys;
	std::map<SDL_Keycode, bool> keysLast;
	std::map<int, bool> buttons;
	std::map<int, bool> buttonsLast;
	Vector2 mousePosition;
public:

	/**
	* Handles all the keys, buttons each frame sets Key[Key] to KeyLast[Key] & Button[Int] to ButtonLast[Int].
	*/
	void Handle();

	/**
	* Handles KeyEvent if key is pressed.
	*/
	void HandleKeyPressEvent(SDL_Keycode key);

	/**
	* Handles KeyEvent if key is release.
	*/
	void HandleKeyReleaseEvent(SDL_Keycode key);

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
	bool KeyPressed(SDL_Keycode key);

	/**
	* Returns true if key is pressed in both this frame and last frame, else returns false.
	*/
	bool KeyDown(SDL_Keycode key);

	/**
	* Returns true if key is up this frame and down last frame, else returns false.
	*/
	bool KeyUp(SDL_Keycode key);

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
	* Adds a new axis to the axises list.
	*/
	void AddAxis(std::string name, KeyCode positive, KeyCode negative);

	/**
	* Returns 1 if positive axis key is pressed, returns -1 if negative axis key is pressed, otherwise returns 0.
	*/
	float GetAxis(std::string name);
};