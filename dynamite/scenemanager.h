#pragma once
#include "scene.h"

class Core;

class SceneManager {
private:
	Scene* activeScene;
	std::vector<Scene*> loadedScenes;
	Core* core;
public:
	/**
	* Constructor.
	*/
	SceneManager(Core* core);

	/**
	* Returns the currently active scene pointer.
	*/
	Scene* GetActiveScene();

	/**
	* Creates a new empty scene, and setting scene name to name parameter, then loads it into loaded scenes.
	*/
	Scene* CreateScene(std::string name);

	/**
	* Loads a scene by path given, It reads the file then creates the scene, then loads it into loaded scenes.
	*/
	void LoadScene(std::string path);

	/**
	* Returns the scene if found with index.
	*/
	Scene* GetLoadedScene(int index);

	/**
	* Unloads the scene given by name string, please note that scene does not get "DELETED". 
	* It just gets removed from the loadedScenes array. If you wish to delete the scene, 
	* you will have to manually remove the return value.
	*/
	Scene* UnLoadScene(std::string name);

	/**
	* Sets the currently active scene to scene found in loaded scenes by name.
	*/
	void SetActiveScene(std::string name);

	/**
	* Saves the scene where name equals name, and saves it to destination.
	*/
	void SaveScene(std::string name, std::string destination);

	/**
	* Returns the core instance
	*/
	Core* GetCore();

	/**
	* Destructor.
	*/
	~SceneManager();
};