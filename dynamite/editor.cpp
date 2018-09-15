/**
*	Filename: editor.cpp
*
*	Description: Editor source file
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/

#include "editor.h"
#include <iostream>
#include "component\sprite.h"
#include "core.h"


Editor::Editor(Core* core) {
	this->core = core;
}

void Editor::Update() {
	
	//ImGui Stuff

	ImGui::Begin("Hierarchy");
	char* listbox_items[9999];

	for (int i = 0; i < 9999; i++) {
		listbox_items[i] = " ";
	}

	static int listbox_item_current = 0;
	for (int i = 0; i < core->GetEntiesCount(); i++) {
		listbox_items[i] = (char*)core->GetEntity(i)->GetTag();
	}
	ImGui::ListBox("", &listbox_item_current, listbox_items, IM_ARRAYSIZE(listbox_items), 20);
	ImGui::End();

	if (listbox_item_current < core->GetEntiesCount()) {
		if (listbox_items[listbox_item_current] == core->GetEntity(listbox_item_current)->GetTag()) {
			this->SetSelectedEntity(core->GetEntity(listbox_item_current));
			selectedEntityId = listbox_item_current;
		}
	}
	else {
		this->SetSelectedEntity(nullptr);
	}

	ImGui::Begin("Inspector");
	if (selectedEntity == nullptr) {
		ImGui::Text("No Entity Selected");
	}
	else {
		ImGui::TextColored(ImVec4(1.f,0.f,0.f,1.f),"Selected Entity: %s",selectedEntity->GetTag());
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "Id: %i",selectedEntityId);
		ImGui::Text("\n");

		float position[] = { selectedEntity->position.GetX(), selectedEntity->position.GetY() };
		ImGui::InputFloat2("Position", position, 2, 0);
		selectedEntity->position = Vector2(position[0], position[1]);
		ImGui::Text("\n");

		ImGui::Text("Change Entity Tag: ");
		static char tag[50];
		ImGui::InputText("(Max 50 characters)", tag, IM_ARRAYSIZE(tag));


		if (ImGui::Button("Save"))
		{
			
			std::string tagFixed = tag;

			selectedEntity->SetTag(tagFixed);
			printf("DYNAMITE: ~Editor~ Entity %i tag changed to: %s\n", selectedEntityId ,tagFixed);
		}

		ImGui::BeginChild("Components");
		ImGui::Text("\n");
		ImGui::Text("Components:");
		for (int i = 0; i < selectedEntity->GetComponentsSize(); i++)
			ImGui::Text("%04d: %s", i, selectedEntity->GetComponentType(i));
		ImGui::EndChild();

	}

	ImGui::End();
}
