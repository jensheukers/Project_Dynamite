#include "scene.h"
#include "scenemanager.h";

Scene::Scene(SceneManager* manager) {
	this->manager = manager;
}

void Scene::SetName(std::string name) {
	this->name = name;
}

std::string Scene::GetName() {
	return this->name;
}

void Scene::AddEntity(Entity* entity) {
	entities.push_back(entity);
}

void Scene::RemoveEntity(int index) {
	delete entities[index];
	entities.erase(entities.begin() + index);
}

Entity* Scene::GetEntity(int index) {
	return entities[index];
}

Scene::~Scene() {

}