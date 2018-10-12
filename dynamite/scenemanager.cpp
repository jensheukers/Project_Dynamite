/**
*	Filename: scenemanager.cpp
*
*	Description: SceneManager source file
*
*	© 2018, Jens Heukers
*/

#include "scenemanager.h"
#include "core.h"
#include <iostream>
#include <fstream>
#include <string>

SceneManager* SceneManager::_instance;

SceneManager* SceneManager::Instance() {
	if (!_instance) {
		_instance = new SceneManager();
	}
	return _instance;
}

SceneManager::SceneManager() {
	activeScene = nullptr;
	printf("DYNAMITE: ~SceneManager~ Initialized!\n");
}

Scene* SceneManager::GetActiveScene() {
	return activeScene;
}

Scene* SceneManager::CreateScene(std::string name) {
	Scene* scene = new Scene(this);
	scene->SetName(name);
	
	loadedScenes.push_back(scene);

	printf("DYNAMITE: ~SceneManager~ : Created new scene: %s\n", name);
	return scene;
}

void SceneManager::LoadExternalScene(std::string path) {
	std::string line;
	std::ifstream sceneFile(path);

	if (sceneFile.is_open()) {
		Scene* scene = CreateScene(path);

		std::string segment;
		std::vector<std::string> segments;
		while (getline(sceneFile, line))
		{
			
		}
		sceneFile.close();
	}
}

Scene* SceneManager::GetLoadedScene(int index) {
	return loadedScenes[index];
}

void* SceneManager::UnLoadScene(std::string name) {
	for (int i = 0; i < loadedScenes.size(); i++) {
		if (loadedScenes[i]->GetName() == name) {
			delete loadedScenes[i];
			loadedScenes.erase(loadedScenes.begin() + i);
		}
	}
	return nullptr;
}

void SceneManager::SetActiveScene(std::string name) {
	for (int i = 0; i < loadedScenes.size(); i++) {
		if (loadedScenes[i]->GetName() == name) {
			activeScene = loadedScenes[i];
			printf("DYNAMITE: ~SceneManager~ : Scene changed to: %s\n",loadedScenes[i]->GetName());
		}
	}
}

SceneManager::~SceneManager() {

}