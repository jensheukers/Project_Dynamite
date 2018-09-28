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

void SceneManager::LoadScene(std::string path) {
	//TODO: IMPLEMENT
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

void SceneManager::SaveScene() {
	std::string path = Core::Instance()->GetResourceDirectory();
	path.append(SceneManager::Instance()->GetActiveScene()->GetName());
	path.append(".dynscene");
	std::ofstream file(path);

	file << activeScene->GetName().c_str() << "\n";

	for (int i = 0; i < activeScene->GetEntiesCount(); i++) {
		file << activeScene->GetEntity(i)->GetTag() << "|";
		file << activeScene->GetEntity(i)->position.GetX() << "|";
		file << activeScene->GetEntity(i)->position.GetY() << "|";
		file << activeScene->GetEntity(i)->GetRotation() << "|";
		for (int ii = 0; ii < activeScene->GetEntity(i)->GetComponentsSize(); ii++) {
			file << activeScene->GetEntity(i)->GetComponentById(ii)->GetTypeName() << "&"; //Split components using & character
			file << activeScene->GetEntity(i)->GetComponentById(ii)->OnSave() << "&";
			file << "|";
		}
		file << "\n";
	}

	printf("DYNAMITE: ~SceneManager~ Scene saved to: %s", path.c_str());
}

SceneManager::~SceneManager() {

}