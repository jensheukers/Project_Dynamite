/**
*	Filename: physics.cpp
*
*	Description: Source file for physics.h
*
*	© 2018, Jens Heukers
*/
#include "physics.h";
#include "../entity.h"


bool Physics::InRange(Collider a, Collider b) {
	Entity* entA = a.GetEntity();
	Entity* entB = b.GetEntity();
	if (entA->position.GetX() > entB->position.GetX() && entA->position.GetY() > entB->position.GetY()) {
		if (a.GetBounds().GetX() < b.GetBounds().GetX() && a.GetBounds().GetY() < b.GetBounds().GetY()) {
			return true;
		}
	}

	return false;
}