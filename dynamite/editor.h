/**
*	Filename: editor.h
*
*	Description: Editor header file
*
*	© 2018, Jens Heukers
*/

#pragma once
#include "../game/game.h"
#include "entity.h"
#include "imgui/imgui.h"
#include "camera.h"

class Editor : public Game {
private:
	Camera* camera;
	Entity* selectedEntity = nullptr;
	Component* currentSelectedComponent = nullptr;
	char* listbox_items[9999];
	int selectedEntityId;
	bool showComponentSettings;
	bool newScene;
	bool addNewComponent;
public:
	/**
	* Constructor
	*/
	Editor();

	/**
	* Update every frame
	*/
	void Update();

	/**
	* Creates a new scene, and sets it active.
	*/
	void NewScene(std::string name);

	/**
	* Creates a new entity on the heap, and adds to the Scene.
	*/
	void CreateEntity();

	/**
	* Deletes the selected entity from current scene.
	*/
	void RemoveEntitySelected();

	/**
	* Searches for component in core, then adds copy to the entity if found
	*/
	void AddComponent(std::string name);

	/**
	* Set the currently selected entity
	*/
	void SetSelectedEntity(Entity* entity) { this->selectedEntity = entity; };

	/**
	* Return the currently selected Entity
	*/
	Entity* GetSelectedEntity() { return this->selectedEntity; };
};