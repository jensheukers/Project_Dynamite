/**
*	Filename: editor.h
*
*	Description: Editor header file
*	Version: 0.1
*
*	� 2018, Jens Heukers
*/

#pragma once
#include "../game/game.h"
#include "entity.h"
#include "imgui/imgui.h"

class Editor : public Game {
private:
	Entity* selectedEntity = nullptr;
	Component* currentSelectedComponent = nullptr;
	int selectedEntityId;
	bool showComponentSettings;
public:
	/**
	* Constructor
	*/
	Editor(Core* core);

	/**
	* Update every frame
	*/
	void Update();

	/**
	* Set the currently selected entity
	*/
	void SetSelectedEntity(Entity* entity) { this->selectedEntity = entity; };

	/**
	* Return the currently selected Entity
	*/
	Entity* GetSelectedEntity() { return this->selectedEntity; };
};