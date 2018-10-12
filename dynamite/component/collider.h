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
	Vector2 position;
	Vector2 bounds;
public:
	/**
	* Constructor
	*/
	Collider();

	void Update() override;

	/**
	* Returns the bounds Vector2
	*/
	Vector2 GetBounds() { return bounds; }

	/**
	* Returns the position Vector2 (Relative to parent)
	*/
	Vector2 GetPosition() { return position; }

	/**
	* Sets the bounds to vector2 given as parameter
	*/
	void SetBounds(Vector2 bounds) { this->bounds = bounds; }
};