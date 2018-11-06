/**
*	Filename: physics.cpp
*
*	Description: Source file for physics.h
*
*	© 2018, Jens Heukers
*/
#include "physics.h"
#include "../core.h"
#include "../scenemanager.h"

bool Physics::InRange(Collider* a, Collider* b) {
	Vector2 aLu = Vector2(a->GetPosition().GetX(), a->GetPosition().GetY());
	Vector2 aRu = Vector2(a->GetPosition().GetX() + a->GetBounds().GetX(), a->GetPosition().GetY());
	Vector2 aLd = Vector2(a->GetPosition().GetX(), a->GetPosition().GetY() + a->GetBounds().GetY());
	Vector2 aRd = Vector2(a->GetPosition().GetX() + a->GetBounds().GetX(), a->GetPosition().GetY() + a->GetBounds().GetY());

	if (InRangePoint(aLu, b)) {
		return true;
	}

	if (InRangePoint(aRu, b)) {
		return true;
	}

	if (InRangePoint(aLd, b)) {
		return true;
	}

	if (InRangePoint(aRd, b)) {
		return true;
	}

	return false;
}

bool Physics::InRangePoint(Vector2 point, Collider* collider) {
	Vector2 colliderLu = Vector2(collider->GetPosition().GetX(), collider->GetPosition().GetY());
	Vector2 colliderRd = Vector2(collider->GetPosition().GetX() + collider->GetBounds().GetX(), collider->GetPosition().GetY() + collider->GetBounds().GetY());

	if (point.GetX() >= colliderLu.GetX() && point.GetY() >= colliderLu.GetY()) {
		if (point.GetX() <= colliderRd.GetX() && point.GetY() <= colliderRd.GetY()) {
			return true;
		}
	}


	return false;
}