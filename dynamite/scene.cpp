/**
*	Filename: scene.cpp
*
*	Description: Source file for User Scene class
*	Version: 8/11/2018
*
*	© 2018, Jens Heukers
*/

#include "scene.h"
#include "scenemanager.h"
#include "core.h"
#include "ui\text.h"

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

Entity* Scene::GetEntityByName(std::string name) {
	for (int i = 0; i < entities.size(); i++) {
		if (entities[i]->GetName() == name) {
			return entities[i];
		}
	}
	return nullptr;
}

void Scene::SortLayers() {
	std::vector<Entity*> tempArray;

	int currentZMax = 0;
	for (int i = 0; i < entities.size(); i++) {
		if (currentZMax < (int)entities[i]->GetZLayer()) {
			currentZMax = entities[i]->GetZLayer();
		}
	}

	for (int ii = 0; ii <= currentZMax; ii++) {
		for (int iii = 0; iii < entities.size(); iii++) {
			if (entities[iii]->GetZLayer() == ii) {
				tempArray.push_back(entities[iii]);
			}
		}
	}
	std::string logMessage = "Scene: ";
	logMessage.append(name);
	logMessage.append(" Layers sorted");
	Core::Log(logMessage);

	entities = tempArray;
}

bool Scene::HasActiveCamera() {
	if (this->activeCamera != nullptr) {
		return true;
	}
	return false;
}

void Scene::AddUIElement(UIElement* element) {
	this->uiElements.push_back(element);
}

std::vector<UIElement*> Scene::GetUIElements() {
	return this->uiElements;
}

UIElement* Scene::GetUIElement(int index) {
	return this->uiElements[index];
}

Scene::~Scene() {
	for (int i = 0; i < uiElements.size(); i++) {
		Text* text = dynamic_cast<Text*>(uiElements[i]);
		if (text) {
			delete text;
		}
	}
}