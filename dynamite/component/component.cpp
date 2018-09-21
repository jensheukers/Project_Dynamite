/**
*	Filename: component.cpp
*
*	Description: Main source file for component.
*
*	© 2018, Jens Heukers
*/
#include "component.h"
#include "../entity.h"

Component::Component() { this->typeName = typeid(*this).name(); };
void Component::Start(Core* core, Entity* parent) { this->parent = parent; };


void Component::OnLoad(std::vector<std::string*> data) {
	return;
}

std::vector<std::string*> Component::OnSave() {
	std::vector<std::string*> data;

	return data;
}

void Component::EditorSettings() {
	ImGui::Begin("");
	ImGui::Text("Component has no editor settings!");
	ImGui::End();
}