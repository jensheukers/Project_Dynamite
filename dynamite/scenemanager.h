/**
*	Filename: scenemanager.h
*
*	Description: SceneManager header file
*
*	© 2018, Jens Heukers
*/


#pragma once
#include "scene.h"

class Core;

class SceneManager {
private:
	static SceneManager* _instance;

	Scene* activeScene;
	std::vector<Scene*> loadedScenes;

	/**
	* Constructor.
	*/
	SceneManager();
public:

	/**
	* Returns the instance if found else creates a new instance
	*/
	static SceneManager* Instance();

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
	void LoadExternalScene(std::string path);

	/**
	* Returns the scene if found with index.
	*/
	Scene* GetLoadedScene(int index);

	/**
	* Unloads the scene given by name string, and delete it.
	*/
	void* UnLoadScene(std::string name);

	/**
	* Sets the currently active scene to scene found in loaded scenes by name.
	*/
	void SetActiveScene(std::string name);

	/**
	* Destructor.
	*/
	~SceneManager();
};