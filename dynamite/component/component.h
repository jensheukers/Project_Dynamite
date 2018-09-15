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

class Component {
protected:
	const char* typeName;
public:
	/**
	* Constructor
	*/
	Component() { this->typeName = typeid(*this).name(); };

	/**
	* Returns the typename.
	*/
	const char* GetTypeName() { return this->typeName; };

	virtual void EditorSettings() {
		ImGui::Begin("");
		ImGui::Text("Component has no editor settings!");
		ImGui::End();
	}

	/**
	* Destructor
	*/
	virtual ~Component() {};
};