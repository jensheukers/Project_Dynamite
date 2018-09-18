/**
*	Filename: entity.cpp
*
*	Description: Source file for entity class
*
*	© 2018, Jens Heukers
*/

#include "entity.h"
#include "core.h"


void Entity::SetCore(Core* core) {
	this->core = core;
}

void Entity::UpdateComponents() {
	for (int i = 0; i < components.Size(); i++) {
		components.Get(i)->Update(core);
	}
}

int Entity::GetComponentsSize() { return this->components.Size(); }

Component* Entity::GetComponentById(int id) {
	return components.Get(id);
}


const char* Entity::GetComponentType(unsigned id) {
	if (id < this->components.Size()) {
		return this->components.Get(id)->GetTypeName();
	}
	return nullptr;
}

const char* Entity::GetTag() { return tag.c_str(); };
void Entity::SetTag(std::string tag) { this->tag = tag; };

void Entity::SetRotation(float rotation) {
	if (rotation > 360) {
		rotation = 0;
	}
	this->rotation = rotation;
};

float Entity::GetRotation() { return this->rotation; };

Entity::~Entity() {
	for (unsigned i = 0; i < components.Size(); i++) {
		delete components.Get(i);
	}
}