/**
*	Filename: entity.h
*
*	Description: Header file for entity class, containing component system
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/


#pragma once
#include "jhe_main.h"
#include "component\component.h"
#include <iostream>

class Entity {
private:
	Array<Component*> components;
	Vector2* position;
public:
	/**
	* Constructor
	*/
	Entity() { this->position = new Vector2(0, 0); };

	/**
	* Constructor
	*/
	Entity(Vector2* position) { this->position = position; };

	/**
	* Adds a component to the components Array.
	*/
	template<typename T>
	T* AddComponent() {
		T* component = new T();
		if (!std::is_base_of<Component, T>::value) {
			printf("DYNAMITE: Type is not derived from Component, cannot add.\n");
			return component;
		}

		components.Push(component);

		return component;
	}

	/**
	* Returns the derived component if found, returns nullptr if component has not been found
	*/
	template<typename T>
	T* GetComponent() {
		for (int i = 0; i < components.Size(); i++) {
			if (typeid(T).name() == components.Get(i)->GetTypeName()) {
				return dynamic_cast<T*>(components.Get(i));
			}
		}

		return nullptr;
	}

	/**
	* Removes the component if found
	*/
	template<typename T>
	void RemoveComponent() {
		for (int i = 0; i < components.Size(); i++) {
			if (typeid(T).name() == components.Get(i)->GetTypeName()) {
				components.Remove(i);
			}
		}
	}	

	/**
	* Returns true if component is found, else returns false
	*/
	template<typename T>
	bool HasComponent() {
		for (int i = 0; i < components.Size(); i++) {
			if (typeid(T).name() == components.Get(i)->GetTypeName()) {
				return true;
			}
		}
	}

	/**
	* Returns the Vector2 instance of the entity
	*/
	Vector2* GetPosition() { return this->position; }
};