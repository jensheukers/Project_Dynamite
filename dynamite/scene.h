#pragma once
#include <iostream>
#include <vector>
#include "entity.h"
#include "camera.h"

class SceneManager;

class Scene {
private:
	std::string name;
	std::vector<Entity*> entities;
	SceneManager* manager;
	Camera* activeCamera;
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
	* Sets the current active camera.
	*/
	void SetActiveCamera(Camera* camera) { this->activeCamera = camera; };

	/**
	* Returns the active camera.
	*/
	Camera* GetActiveCamera() { return this->activeCamera; };

	/**
	* Removes the active camera.
	*/
	void RemoveActiveCamera() { this->activeCamera = nullptr; };

	/**
	* Returns true if a active camera is present, else returns false
	*/
	bool HasActiveCamera();
};