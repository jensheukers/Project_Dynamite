/**
*	Filename: uielement.h
*
*	Description: Header file for User Interface Element class
*	Version: 2/11/2018
*
*	� 2018, Jens Heukers
*/

#pragma once
#include "../entity.h"
#include "../math/vector2.h"

class UIElement : public Entity {
private:
	bool entered;
public:
	/// @brief The position of the ui element on screen.
	Vector2 screenPosition;

	/**
	* Constructor, sets position to paramater
	*/
	UIElement(Vector2 position);


	/**
	* Constructor, sets position to parameter 0, and path to parameter 1
	*/
	UIElement(Vector2 position, std::string path);

	/**
	* Update gets called every frame
	*/
	void Update() override;

	/*
	* Set the ui element sprite texture
	*/
	void SetTexture(std::string path);

	/**
	* Triggered when user hovers over the element with mouse
	*/
	virtual void OnHover() {};

	/**
	* Triggered when user clicks while hovering over the UI Element
	*/
	virtual void OnClick(int btn) {};

	/**
	* Triggered when user enters the UI Element with the mouse
	*/
	virtual void OnEnter() {};


	/**
	* Triggered when user leaves the UI Element with mouse.
	*/
	virtual void OnLeave() {};
};