/**
*	Filename: collider.h
*
*	Description: Source file for collider
*
*	© 2018, Jens Heukers
*/


#include "collider.h"

Collider::Collider() {
	this->typeName = typeid(*this).name();
	this->bounds = Vector2(0,0);
}