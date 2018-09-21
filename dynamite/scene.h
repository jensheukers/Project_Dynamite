#pragma once
#include <iostream>
#include <vector>
#include "entity.h"

class SceneManager;

class Scene {
private:
	std::string name;
	std::vector<Entity*> entities;
	SceneManager* manager;
public:
	Scene(SceneManager* manager);
	~Scene();
	void SetName(std::string name);
	std::string GetName();

	/**
	* Adds a new entity to the entitites Array
	*/
	void AddEntity(Entity* entity);

	/**
	* Removes entity from the entitites Array where index matches Array Index
	*/
	void RemoveEntity(int index);

	/**
	* Returns entity from the entitites Array where index matches Array Index
	*/
	Entity* GetEntity(int index);

	/**
	* Returns the amount of entities in the entities list
	*/
	int GetEntiesCount() { return this->entities.size(); };

	/*
	* Returns the entities list
	**/
	std::vector<Entity*> GetEnties() { return this->entities; };


	/**
	* Loads all entity properties and calls OnLoad method on all entities.
	*/
	void LoadEntities(std::string data);
};