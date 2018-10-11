/**
*	Filename: entity.h
*
*	Description: Header file for entity class, containing component system
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/


#pragma once
#include "component\component.h"
#include "../game/game.h"
#include <iostream>
#include <vector>

class Core;

class Entity {
private:
	std::vector<Component*> components;
	std::string name;
	float rotation;
public:
	Vector2 position;

	/**
	* Constructor
	*/
	Entity() { this->position = Vector2(0, 0); this->name = "Entity"; this->rotation = 0; };

	/**
	* Constructor
	*/
	Entity(Vector2 position) { this->position = position; };

	/**
	* Update gets called every frame
	*/
	virtual void Update() {};

	/**
	* Calls the update function on all components
	*/
	void UpdateComponents();

	/**
	* Adds a component to the components Array.
	*/
	template<typename T>
	T* AddComponent() {

		if (HasComponent<T>()) {
			printf("DYNAMITE: ~Entity~ Warning: Component %s already exists on Entity!\n", typeid(T).name());
		}

		T* component = new T();
		if (!std::is_base_of<Component, T>::value) {
			printf("DYNAMITE: ~Entity~ ERROR: Type is not derived from Component, cannot add.\n");
			return component;
		}
		else {
			Component* convertedComponent = component;
			convertedComponent->Start(this);
			convertedComponent->Start();
		}

		components.push_back(component);
		return component;
	}

	/**
	* Returns the derived component if found, returns nullptr if component has not been found
	*/
	template<typename T>
	T* GetComponent() {
		for (unsigned i = 0; i < components.size(); i++) {
			if (typeid(T).name() == components[i]->GetTypeName()) {
				return dynamic_cast<T*>(components[i]);
			}
		}

		return nullptr;
	}

	/**
	* Removes the component if found
	*/
	template<typename T>
	void RemoveComponent() {
		for (int i = 0; i < components.size(); i++) {
			if (typeid(T).name() == components[i]->GetTypeName()) {
				components.erase(components.begin() + i);
			}
		}
	}	

	/**
	* Returns true if component is found, else returns false
	*/
	template<typename T>
	bool HasComponent() {
		for (unsigned i = 0; i < components.size(); i++) {
			if (typeid(T).name() == components[i]->GetTypeName()) {
				return true;
			}
		}
		return false;
	}


	/**
	* Get the size of the components array
	*/
	int GetComponentsSize();


	/**
	* Returns the component found by the matching id
	*/
	Component* GetComponentById(int id);

	/**
	* Get component type with index of components array
	*/
	const char* GetComponentType(unsigned id);

	/**
	* Returns the tag of the entity
	*/
	const char* GetName();

	/**
	* Sets the tag of the entity
	*/
	void SetName(std::string tag);

	/**
	* Set the rotation
	*/
	void SetRotation(float rotation);

	/**
	* Get the rotation
	*/
	float  GetRotation();

	/**
	* Destructor
	*/
	~Entity();
};