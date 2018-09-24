/**
*	Filename: scenemanager.cpp
*
*	Description: SceneManager source file
*
*	© 2018, Jens Heukers
*/

#include "scenemanager.h"
#include "core.h"

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

Scene* SceneManager::UnLoadScene(std::string name) {
	for (int i = 0; i < loadedScenes.size(); i++) {
		if (loadedScenes[i]->GetName() == name) {
			Scene* scene = loadedScenes[i];
			loadedScenes.erase(loadedScenes.begin() + i);
			return scene;
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

void SceneManager::SaveScene(std::string destination) {
	for (int i = 0; i < activeScene->GetEntiesCount(); i++) {
		std::string entityData;
		for (int ii = 0; ii < activeScene->GetEntity(i)->GetComponentsSize(); ii++) {
			std::vector<std::string*> componentData = activeScene->GetEntity(i)->GetComponentById(ii)->OnSave();
		}
	}
}

SceneManager::~SceneManager() {

}