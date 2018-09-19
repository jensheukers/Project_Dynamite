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
#include "core.h"

Editor::Editor(Core* core) {
	this->core = core;

	camera = new Camera();
	camera->SetPosition(Vector2(Game::GetWindowDimensions().GetX() / 2, Game::GetWindowDimensions().GetY() / 2));
	core->SetActiveCamera(camera);

	//Setup Imgui Styling
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowRounding = 0.0f;
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.8f, 0.0f, 0.0f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.8f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.8f, 0.0f, 0.0f, 1.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.5f, 0.0f, 0.0f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.5f, 0.0f, 0.0f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.5f, 0.0f, 0.0f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.3f, 0.0f, 0.0f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.3f, 0.0f, 0.0f, 1.00f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.3f, 0.0f, 0.0f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.8f, 0.0f, 0.0f, 1.00f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.8f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.8f, 0.0f, 0.0f, 1.00f);

	//Setup camera controls
	core->AddAxis("Horizontal", KeyCode::ArrowLeft, KeyCode::ArrowRight);
	core->AddAxis("Vertical", KeyCode::ArrowUp, KeyCode::ArrowDown);
}

void Editor::Update() {
	
	//Camera controls
	float x = core->GetAxis("Horizontal");
	float y = core->GetAxis("Vertical");

	camera->SetPosition(Vector2(camera->GetXCoord() + x, camera->GetYCoord() + y));

	//ImGui Stuff
	ImGui::Begin("Dynamite",nullptr, ImGuiWindowFlags_MenuBar);

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("Scene"))
		{
			if (ImGui::MenuItem("Open", "Ctrl+O")) { /* Do stuff */ }
			if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	ImGui::SetWindowSize(ImVec2(Game::GetWindowDimensions().GetX(),15));
	ImGui::SetWindowPos(ImVec2(0, 0), true);
	ImGui::End();



	ImGui::Begin("Hierarchy");

	for (int i = 0; i < 9999; i++) {
		listbox_items[i] = " ";
	}

	static int listbox_item_current = 0;
	for (int i = 0; i < core->GetSceneManager()->GetActiveScene()->GetEntiesCount(); i++) {
		listbox_items[i] = (char*)core->GetSceneManager()->GetActiveScene()->GetEntity(i)->GetTag();
	}
	ImGui::ListBox("", &listbox_item_current, listbox_items, IM_ARRAYSIZE(listbox_items), 20);

	ImGui::SetWindowSize(ImVec2(150, 400));
	ImGui::SetWindowPos(ImVec2(0, 50), true);
	ImGui::End();

	if (listbox_item_current < core->GetSceneManager()->GetActiveScene()->GetEntiesCount()) {
		if (listbox_items[listbox_item_current] == core->GetSceneManager()->GetActiveScene()->GetEntity(listbox_item_current)->GetTag()) {
			this->SetSelectedEntity(core->GetSceneManager()->GetActiveScene()->GetEntity(listbox_item_current));
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
		float rotation = selectedEntity->GetRotation();
		ImGui::SliderFloat("Rotation", &rotation, 0.0f, 360.0f);

		selectedEntity->position = Vector2(position[0], position[1]);
		selectedEntity->SetRotation(rotation);
		ImGui::Text("\n");

		ImGui::Text("Change Entity Tag: ");
		static char tag[50];
		ImGui::InputText("(Max 50 characters)", tag, IM_ARRAYSIZE(tag));


		if (ImGui::Button("Save"))
		{
			
			std::string tagFixed = tag;

			selectedEntity->SetTag(tagFixed);
			printf("DYNAMITE: ~Editor~ Entity %i tag changed to: %s\n", selectedEntityId , tagFixed.c_str());
		}

		/*ImGui::BeginChild("Components");
		ImGui::Text("\n");
		ImGui::Text("Components:");
		for (int i = 0; i < selectedEntity->GetComponentsSize(); i++)
			ImGui::Text("%04d: %s", i, selectedEntity->GetComponentType(i));
			ImGui::Button("Settings");
		ImGui::EndChild();*/

		ImGui::Text("\n");
		ImGui::Text("Components:");


		const char* components[100];
		int componentsCurrentSelectedIndex;

		for (int i = 0; i < 100; i++) {
			components[i] = " ";
		}

		for (int i = 0; i < selectedEntity->GetComponentsSize(); i++) {
			components[i] = selectedEntity->GetComponentType(i);
		}

		ImGui::ListBox("", &componentsCurrentSelectedIndex, components, IM_ARRAYSIZE(components), 5);
	
		for (int ii = 0; ii < selectedEntity->GetComponentsSize(); ii++) {
			if (selectedEntity->GetComponentType(componentsCurrentSelectedIndex) != nullptr) {
				if (selectedEntity->GetComponentType(componentsCurrentSelectedIndex) == components[ii]) {
					currentSelectedComponent = selectedEntity->GetComponentById(ii);
				}
			}
		}

		if (!showComponentSettings) {
			if (ImGui::Button("Component Settings") && currentSelectedComponent != nullptr)
			{
				showComponentSettings = true;
			}
		}
		else {
			if (ImGui::Button("Close"))
			{
				showComponentSettings = false;
			}
		}

		if (showComponentSettings) {
			currentSelectedComponent->EditorSettings();
		}


	}


	ImGui::SetWindowSize(ImVec2(250, 400));
	ImGui::SetWindowPos(ImVec2(Game::GetWindowDimensions().GetX() - 250, 50), true);
	ImGui::End();
}