/**
*	Filename: entity.cpp
*
*	Description: Source file for entity class
*	Version: 21/10/2018
*
*	© 2018, Jens Heukers
*/

#include "entity.h"
#include "core.h"
#include "../game/game.h"

unsigned Entity::next_unique_id = 0;

Entity::Entity() {
	this->parent = nullptr;
	this->position = Vector2(0, 0); 
	this->localPosition = Vector2(0,0);
	this->name = "Entity"; 
	this->rotation = 0; 
	this->z_layer = 0;
	this->scale = Vector2(1, 1);

	this->unique_id = next_unique_id;
	next_unique_id++;
}

Entity::Entity(Vector2 position) {
	this->parent = nullptr;
	this->position = position;
	this->localPosition = position;
	this->name = "Entity";
	this->rotation = 0;
	this->z_layer = 0;
	this->scale = Vector2(1,1);

	this->unique_id = next_unique_id;
	next_unique_id++;
}

Entity* Entity::GetParent() {
	return this->parent;
}

bool Entity::HasParent() {
	if (!parent) {
		return false;
	}
	return true;
}

void Entity::SetParent(Entity* parent) {
	this->parent = parent;
}

Entity* Entity::GetChild(int index) {
	return children[index];
}

void Entity::AddChild(Entity* entity) {
	if (!SceneManager::Instance()->GetActiveScene()) {
		Core::Log("Cannot child entity: No active Scene");
	}


	children.push_back(entity);

	bool entityFound = false;
	for (int i = 0; i < SceneManager::Instance()->GetActiveScene()->GetEnties().size(); i++) {
		if (SceneManager::Instance()->GetActiveScene()->GetEntity(i) == entity) {
			entityFound = true;
		}
	}

	if (!entityFound) {
		SceneManager::Instance()->GetActiveScene()->AddEntity(entity);
	}
	
	entity->SetParent(this);
}

void Entity::RemoveChild(int index) {
	children[index]->SetParent(nullptr);
	children.erase(children.begin() + index);
}

void Entity::UpdateChildren() {
	if (HasParent()) {
		this->position = Vector2(parent->position.GetX() + this->localPosition.GetX(), parent->position.GetY() + this->localPosition.GetY());
		this->scale = Vector2(this->scale.GetX() * parent->GetScale().GetX(), this->scale.GetY() * parent->GetScale().GetY());
	}

	for (int i = 0; i < children.size(); i++) {
		children[i]->UpdateChildren();
	}
}

void Entity::SetScale(Vector2 scale) {
	if (scale.GetX() < 0) {
		this->scale = Vector2(0,scale.GetY());
	}

	if (scale.GetY() < 0) {
		this->scale = Vector2(scale.GetX(), 0);
	}

	this->scale = scale;
}

void Entity::UpdateComponents() {
	for (int i = 0; i < components.size(); i++) {
		components[i]->Update();
	}
}

int Entity::GetComponentsSize() { return this->components.size(); }

Component* Entity::GetComponentById(int id) {
	return components[id];
}


const char* Entity::GetComponentType(unsigned id) {
	if (id < this->components.size()) {
		return this->components[id]->GetTypeName();
	}
	return nullptr;
}

const char* Entity::GetName() { return name.c_str(); };
void Entity::SetName(std::string name) { this->name = name; };

void Entity::SetRotation(float rotation) {
	if (rotation > 360) {
		rotation = 0;
	}
	this->rotation = rotation;
};

float Entity::GetRotation() { return this->rotation; };

void Entity::SetZLayer(unsigned layer) {
	if (z_layer < 0) {
		z_layer = 0;
	}

	z_layer = layer;

	if (SceneManager::Instance()->GetActiveScene() != nullptr) {
		SceneManager::Instance()->GetActiveScene()->SortLayers();
	}
}

Entity::~Entity() {
	for (unsigned i = 0; i < components.size(); i++) {
		delete components[i];
	}
}