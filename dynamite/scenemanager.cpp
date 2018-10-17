/**
*	Filename: scenemanager.cpp
*
*	Description: SceneManager source file
*
*	© 2018, Jens Heukers
*/

#include "scenemanager.h"
#include "core.h"
#include "component\collider.h"
#include <iostream>
#include <fstream>
#include <sstream>
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

	printf("DYNAMITE: ~SceneManager~ : Created new scene: %s\n", name.c_str());
	return scene;
}

void SceneManager::LoadExternalScene(std::string path) {
	std::string line;
	std::ifstream sceneFile(path);

	std::string type;
	bool note = false;
	if (sceneFile.is_open()) {
		Scene* scene = CreateScene(path);
		while (getline(sceneFile, line))
		{
			if (line == "") {
				continue;
			}

			if (line == "#NOTE") {
				note = true;
			}

			if (line == "#ENDNOTE") {
				note = false;
			}

			if (!note) {

				if (line == "#PROPERTIES") {
					type = line;
					continue;
				}

				if (line == "#ENTITIES") {
					type = line;
					continue;
				}

				if (type == "#PROPERTIES") {
					std::stringstream ss(line);
					std::string segment;
					std::vector<std::string> segments;
					while (std::getline(ss, segment, '=')) {
						segments.push_back(segment);
					}

					std::string variable = segments[0];
					std::string value = segments[1];

					if (variable == "name") {
						scene->SetName(value);
					}

					if (variable == "camera") {
						if (value != "create") {
							std::stringstream valueStringStream(value);
							std::string valueSegment;
							std::vector<std::string> camProperties;
							while (std::getline(valueStringStream, valueSegment, '|')) {
								camProperties.push_back(valueSegment);
							}
							scene->SetActiveCamera(new Camera(Vector2(std::stof(camProperties[0]), std::stof(camProperties[1]))));
						}
						else {
							scene->SetActiveCamera(new Camera());
						}
					}
				}

				if (type == "#ENTITIES") {
					std::stringstream ss(line);
					std::string segment;
					std::vector<std::string> segments;
					while (std::getline(ss, segment, '|')) {
						segments.push_back(segment);
					}

					Entity* entity = new Entity();
					entity->SetName(segments[0]);
					entity->position = Vector2(std::stof(segments[1]), std::stof(segments[2]));
					entity->SetRotation(std::stof(segments[3]));
					entity->SetZLayer(std::stof(segments[4]));

					if (segments[5] == "true") {
						entity->AddComponent<Sprite>();
						entity->GetComponent<Sprite>()->SetSurface(Core::Instance()->GetResourcePath(segments[6].c_str()).c_str());
						entity->GetComponent<Sprite>()->SetScale(Vector2(std::stof(segments[7]), std::stof(segments[8])));
					}

					if (segments[9] == "true") {
						entity->AddComponent<Collider>();
						entity->GetComponent<Collider>()->SetBounds(Vector2(std::stof(segments[10]), std::stof(segments[11])));
					}

					scene->AddEntity(entity);
					std::string logMessage = "Entity: ";
					logMessage.append(std::to_string(scene->GetEntiesCount()));
					logMessage.append(" Created and added to scene");
					Core::Log(logMessage);

				}
			}
		}

		std::string logMessage = "Scene: ";
		logMessage.append(scene->GetName());
		logMessage.append(" Loaded!");
		Core::Log(logMessage);
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
			activeScene->SortLayers();
			printf("DYNAMITE: ~SceneManager~ : Scene changed to: %s\n",loadedScenes[i]->GetName().c_str());
		}
	}
}

SceneManager::~SceneManager() {

}