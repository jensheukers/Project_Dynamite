/**
*	Filename: entity.h
*
*	Description: Header file for entity class, containing component system
*	Version: 21/10/2018
*
*	© 2018, Jens Heukers
*/


#pragma once
#include "component\component.h"
#include "math/vector2.h"
#include <iostream>
#include <vector>

class Core;

class Entity {
private:
	/** The list of components of this entity*/
	std::vector<Component*> components;

	/** The list of children of this entity*/
	std::vector<Entity*> children;

	/** The parent pointer of this entity, if entity has no parent, value shall be nullptr*/
	Entity* parent;

	/** The list of components of this entity*/
	std::string name;

	/** The unique id of this entity*/
	unsigned unique_id;

	/** Static next unique id, will be incremented in constructor*/
	static unsigned next_unique_id;

	/** The rotation of this Entity*/
	float rotation;

	/** The scale Vector2 of this Entity*/
	Vector2 scale;

	/** The z_layer to for the renderer, the higher the number, the more to the foreground*/
	unsigned z_layer;
public:
	/** The position Vector2 in local space*/
	Vector2 localPosition;

	/** The position Vector2 in global space*/
	Vector2 position;

	/**
	* Constructor
	*/
	Entity();

	/**
	* Constructor
	*/
	Entity(Vector2 position);

	/**
	* Update gets called every frame
	*/
	virtual void Update() {};

	/** 
	* Returns the unique id of this entity
	*/
	unsigned GetUniqueId() { return this->unique_id; };

	/**
	* Returns the parent object if entity has a parent, else returns nullptr
	*/
	Entity* GetParent();

	/**
	* Returns true if entity has a parent, else returns false
	*/
	bool HasParent();

	/**
	* Sets the parent of this entity
	*/
	void SetParent(Entity* parent);

	/**
	* Returns the child from vector if found.
	*/
	Entity* GetChild(int index);

	/**
	* Adds a new child to the entity, also adds the child to the scene if not added already.
	*/
	void AddChild(Entity* entity);

	/**
	* Removes the child from vector if found. 
	*/
	void RemoveChild(int index);

	/**
	* Handles all the updates for children entities
	*/
	void UpdateChildren();

	/**
	* Calls the update function on all components
	*/
	void UpdateComponents();

	/**
	* Set the scale of the entity
	*/
	void SetScale(Vector2 scale);

	/**
	* The scale of the entity
	*/
	Vector2 GetScale() { return this->scale; }

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


	/*
	* Set the z layer
	*/
	void SetZLayer(unsigned layer);

	/*
	* Return the z layer
	*/
	unsigned GetZLayer() { return this->z_layer; }

	/**
	* Destructor
	*/
	~Entity();
};