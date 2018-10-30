/**
*	Filename: scene.h
*
*	Description: Header file for Scene class.
*
*	Version: 23/10/2018
*
*	© 2018, Jens Heukers
*/


#pragma once
#include <iostream>
#include <vector>
#include "entity.h"
#include "camera.h"

class SceneManager;

class Scene {
private:

	/// @brief Name of the scene
	std::string name;

	/// @brief List of entities in the scene
	std::vector<Entity*> entities;

	/// @brief The pointer to SceneManager instance
	SceneManager* manager;

	/// @brief The active camera pointer
	Camera* activeCamera;
public:
	/**
	* Constructor
	*/
	Scene(SceneManager* manager);
	
	/**
	* Destructor
	*/
	~Scene();

	/**
	* Set the name of the scene
	*/
	void SetName(std::string name);

	/**
	* Get the name of the Scene
	*/
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
	* Return the entity where parameter equals the name of the entity
	*/
	Entity* GetEntityByName(std::string name);

	/**
	* Sort all the z-layers to match from lowest to highest in the entities vector.
	*/
	void SortLayers();

	/**
	* Returns the amount of entities in the entities list
	*/
	int GetEntiesCount() { return (int)this->entities.size(); };

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