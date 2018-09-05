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
	Vector2 position;
public:
	/**
	* Constructor
	*/
	Entity() {};

	/**
	* Constructor
	*/
	Entity(Vector2 position);

	/**
	* Adds a component to the components Array.
	*/
	template<typename T>
	void AddComponent() {
		if (!std::is_base_of<Component, T>::value) {
			printf("DYNAMITE: Type is not derived from Component, cannot add.\n");
			return;
		}

		components.Push(new T());
	}

	/**
	* Returns the derived component if found, returns nullptr if component has not been found
	*/
	template<typename T>
	T* GetComponent() {
		for (int i = 0; i < components.Size(); i++) {
			Component* temp = *components.Get(i);
			if (typeid(T).name() == temp->GetTypeName()) {
				return dynamic_cast<T*>(temp);
			}
			else {
				delete temp;
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
			Component* temp = *components.Get(i);
			if (typeid(T).name() == temp->GetTypeName()) {
				components.Remove(i);
				delete temp;
			}
		}
	}	
};