#include "scenemanager.h"
#include "core.h"

SceneManager::SceneManager(Core* core) {
	this->core = core;
	printf("DYNAMITE: ~SceneManager~ Initialized!\n");
}

Scene* SceneManager::GetActiveScene() {
	return activeScene;
}

Scene* SceneManager::CreateScene(std::string name) {
	Scene* scene = new Scene(this);
	scene->SetName(name);
	
	loadedScenes.push_back(scene);
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
}

Core* SceneManager::GetCore() {
	return this->core;
}

SceneManager::~SceneManager() {

}