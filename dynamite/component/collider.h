/**
*	Filename: collider.h
*
*	Description: Header file for collider Component.
*
*	© 2018, Jens Heukers
*/


#pragma once
#include "component.h"
#include "../math/vector2.h"

class Collider : public Component {
private:
	Vector2 bounds;
public:
	/**
	* Constructor
	*/
	Collider();

	/**
	* Returns the bounds Vector2
	*/
	Vector2 GetBounds() { return bounds; }

	/**
	* Sets the bounds to vector2 given as parameter
	*/
	void SetBounds(Vector2 bounds) { this->bounds = bounds; }
};