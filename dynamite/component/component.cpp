/**
*	Filename: component.cpp
*
*	Description: Main source file for component.
*
*	© 2018, Jens Heukers
*/
#include "component.h"
#include "../entity.h"

Component::Component() { this->typeName = typeid(*this).name(); };
void Component::Start(Entity* parent) { this->parent = parent; };


void Component::OnLoad(const char* data) {
	return;
}

const char* Component::OnSave() {
	return "";
}

Component* Component::Copy() {
	Component* component = new Component();
	return component;
}