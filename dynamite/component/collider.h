/**
*	Filename: collider.h
*
*	Description: Header file for collider Component.
*
*	Version: 23/10/2018
*
*	© 2018, Jens Heukers
*/


#pragma once
#include "component.h"
#include "../math/vector2.h"

class Collider : public Component {
private:
	/// @brief the position of the collider (is auto-updated in Update() method, to parent position).
	Vector2 position;

	/// @brief the position of the bounds (in world space)
	Vector2 bounds;

	/// @brief the position of the bounds (in local space)
	Vector2 localBounds;
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
	void SetBounds(Vector2 bounds) { this->localBounds = bounds; }
};