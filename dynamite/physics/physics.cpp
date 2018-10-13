/**
*	Filename: physics.cpp
*
*	Description: Source file for physics.h
*
*	© 2018, Jens Heukers
*/
#include "physics.h";
#include "../core.h"
#include "../scenemanager.h"

bool Physics::InRange(Collider a, Collider b) {
	if (a.GetPosition().GetX() > b.GetPosition().GetX() && a.GetPosition().GetY() > b.GetPosition().GetY()) {
		if (a.GetBounds().GetX() < b.GetBounds().GetX() + b.GetPosition().GetX()) {
			if (a.GetBounds().GetY() < b.GetBounds().GetY() + b.GetPosition().GetY()) {
				return true;
			}
		}
	}

	return false;
}

bool Physics::InRangePoint(Vector2 point, Collider collider) {
	if (point.GetX() > collider.GetPosition().GetX() && point.GetY() > collider.GetPosition().GetY()) {
		if (point.GetX() < collider.GetBounds().GetX() + collider.GetPosition().GetX()) {
			if (point.GetY() < collider.GetBounds().GetY() + collider.GetPosition().GetY()) {
				return true;
			}
		}
	}
	return false;
}

bool Physics::RayCast(Vector2 origin, Vector2 endPos, float resolution, HitData* hitData) {
	if (SceneManager::Instance()->GetActiveScene() == nullptr) {
		Core::Log("~RayCast~ Cannot shoot raycast, No Active Scene...");
		return false;
	}
	unsigned startTime = Core::Instance()->GetTimeElapsed();
	
	if (resolution > 1) {
		resolution = 1;
	}

	Collider* lastCollider = nullptr;

	for (float i = 0; i < 1; i += resolution) {
		Vector2 rayPos = Vector2::Lerp(origin,endPos,i);
		for (int ii = 0; ii < SceneManager::Instance()->GetActiveScene()->GetEntiesCount(); ii++) {
			Entity* entityCurrent = SceneManager::Instance()->GetActiveScene()->GetEntity(ii);
			if (entityCurrent->HasComponent<Collider>() && entityCurrent->GetComponent<Collider>() != lastCollider) {
				if (InRangePoint(rayPos, *entityCurrent->GetComponent<Collider>())) {
					hitData->hits.push_back(entityCurrent->GetComponent<Collider>());
					lastCollider = entityCurrent->GetComponent<Collider>();
				}
			}
		}
	}

	hitData->time = Core::Instance()->GetTimeElapsed() - startTime; 
	if (hitData->hits.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}