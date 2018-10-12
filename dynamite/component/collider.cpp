/**
*	Filename: collider.h
*
*	Description: Source file for collider
*
*	© 2018, Jens Heukers
*/


#include "collider.h"
#include "../entity.h"

Collider::Collider() {
	this->typeName = typeid(*this).name();
	this->position = Vector2(0, 0);
	this->bounds = Vector2(0,0);
}

void Collider::Update() {
	this->position = parent->position;
}