/**
*	Filename: physics.cpp
*
*	Description: Source file for physics.h
*
*	© 2018, Jens Heukers
*/
#include "physics.h";
#include "../entity.h"
#include "../core.h"
#include "../scenemanager.h"

bool Physics::InRange(Collider a, Collider b) {
	Entity* entA = a.GetEntity();
	Entity* entB = b.GetEntity();
	if (entA->position.GetX() > entB->position.GetX() && entA->position.GetY() > entB->position.GetY()) {
		if (a.GetBounds().GetX() < b.GetBounds().GetX() + entB->position.GetX()) {
			if (a.GetBounds().GetY() < b.GetBounds().GetY() + entB->position.GetY()) {
				return true;
			}
		}
	}

	return false;
}

bool Physics::InRangePoint(Vector2 point, Collider collider) {
	Entity* ent = collider.GetEntity();
	if (point.GetX() > ent->position.GetX() && point.GetY() > ent->position.GetY()) {
		if (point.GetX() < collider.GetBounds().GetX() + ent->position.GetX()) {
			if (point.GetY() < collider.GetBounds().GetY() + ent->position.GetY()) {
				return true;
			}
		}
	}
	return false;
}

bool Physics::RayCast(Vector2 origin, Vector2 direction, float lenght, HitData returnData) {
	if (SceneManager::Instance()->GetActiveScene() == nullptr) {
		Core::Log("~RayCast~ Cannot shoot raycast, No Active Scene...");
		return false;
	}

	unsigned startTime = Core::Instance()->GetTimeElapsed();
	HitData hitData;

	//Calculate the end position
	Vector2 endPos = Vector2(origin.GetX() + (direction.GetX() + lenght), origin.GetY() + (direction.GetY() + lenght));
	
	for (int i = 0; i < Vector2::Distance(origin, endPos); i++) {
		for (int ii = 0; ii < SceneManager::Instance()->GetActiveScene()->GetEntiesCount(); ii++) {
			if (SceneManager::Instance()->GetActiveScene()->GetEntity(ii)->HasComponent<Collider>()) {
				//TODO IMPLEMENT HIT CHECK

				//hitData.hits.push_back(SceneManager::Instance()->GetActiveScene()->GetEntity(ii)->GetComponent<Collider>());
			}
		}
	}

	hitData.time = Core::Instance()->GetTimeElapsed() - startTime;
	
	returnData = hitData;

	if (returnData.hits.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}