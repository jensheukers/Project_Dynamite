/**
*	Filename: physics.h
*
*	Description: Header file for physics, physics class contains
*				 methods for collision, raycasting ect.
*
*	© 2018, Jens Heukers
*/

#pragma once
#include <iostream>
#include <vector>

#include "../math/math.h"
#include "../math/vector2.h"
#include "../component/collider.h"

class HitData {
public:
	/** List of colliders that have been hit by the raycast */
	std::vector<Collider> hits;

	/** Time it took for the raycast to execute */
	unsigned time;
};

class Physics {
public:
	/**
	* Returns true, if collider a is in collider b.
	*/
	static bool InRange(Collider a, Collider b);
};