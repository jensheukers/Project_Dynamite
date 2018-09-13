/**
*	Filename: camera.h
*
*	Description: Header file for Camera class
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/

#pragma once

#include "vector2\vector2.h"
class Camera {
private:
	Vector2* position;
public:

	/**
	* Constructor.
	*/
	Camera() { this->position = new Vector2(0, 0); };

	/**
	* Constructor.
	*/
	Camera(Vector2 position) { this->position = &position; };

	/**
	* Sets the position of the camera
	*/
	void SetPosition(Vector2 position) { this->position = &position; };

	/**
	* Returns the X coord of the position Vector2
	*/
	float GetXCoord() { return this->position->GetX(); }; 

	/**
	* Returns the Y coord of the position Vector2
	*/
	float GetYCoord() { return this->position->GetY(); };

	/**
	* Destructor
	*/
	~Camera() {
		delete position;
	}
};