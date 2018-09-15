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
	std::string tag;
	float rotation;
public:
	Vector2 position;

	/**
	* Constructor
	*/
	Entity() { this->position = Vector2(0, 0); this->tag = "Entity"; this->rotation = 0; };

	/**
	* Constructor
	*/
	Entity(Vector2 position) { this->position = position; };

	/**
	* Adds a component to the components Array.
	*/
	template<typename T>
	T* AddComponent() {
		
		if (HasComponent<T>()) {
			std::cout << "DYNAMITE: ~Entity~ Warning: Component " << typeid(T).name() << " already exists on Entity!\n";
		}

		T* component = new T();
		if (!std::is_base_of<Component, T>::value) {
			printf("DYNAMITE: ~Entity~ Type is not derived from Component, cannot add.\n");
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
	* Destructor
	*/
	~Entity() {

		for (int i = 0; i < components.Size(); i++) {
			delete components.Get(i);
		}
	}

	/**
	* Get the size of the components array
	*/
	int GetComponentsSize() { return this->components.Size(); }


	/**
	* Returns the component found by the matching id
	*/
	Component* GetComponentById(int id) { return components.Get(id); }

	/**
	* Get component type with index of components array
	*/
	const char* GetComponentType(int id) {

		if (id < this->components.Size()) {
			return this->components.Get(id)->GetTypeName();
		}
		return nullptr;
	}

	/**
	* Returns the tag of the entity
	*/
	const char* GetTag() { return tag.c_str(); };

	/**
	* Sets the tag of the entity
	*/
	void SetTag(std::string tag) { this->tag = tag; };

	/**
	* Set the rotation
	*/
	void SetRotation(float rotation) { 
		if (rotation > 360) {
			rotation = 0;
		}

		this->rotation = rotation; 
	};

	/**
	* Get the rotation
	*/
	float  GetRotation() { return this->rotation; };
};