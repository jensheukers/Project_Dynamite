/**
*	Filename: component.h
*
*	Description: Main header file for component.
*	Version: 0.2
*
*	© 2018, Jens Heukers
*/

#pragma once
#include <iostream>
#include "../imgui/imgui.h"


class Entity;

class Core;

class Component {
protected:
	const char* typeName;
	Entity* parent;
public:
	/**
	* Constructor
	*/
	Component() { this->typeName = typeid(*this).name(); };

	/**
	* Returns the typename.
	*/
	const char* GetTypeName() { return this->typeName; };

	/**
	* Settings that are displayed in the editor.
	*/
	virtual void EditorSettings() {
		ImGui::Begin("");
		ImGui::Text("Component has no editor settings!");
		ImGui::End();
	}


	/**
	* Sets the parent Entity
	*/
	void Start(Core* core, Entity* parent) { this->parent = parent; };

	/**
	* Start gets called right as component is added to Entity.
	*/
	virtual void Start(Core* core) { };

	/**
	* Update gets called every frame by the Entity containing it.
	*/
	virtual void Update(Core* core) {};

	/**
	* Destructor
	*/
	virtual ~Component() {};
};