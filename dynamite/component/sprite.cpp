/**
*	Filename: sprite.cpp
*
*	Description: Main Source for Sprite Component.
*
*	© 2018, Jens Heukers
*/

#include "sprite.h"

SDL_Surface* Sprite::GetSurface() {
	if (this->surface == nullptr) {
		return nullptr;
	}

	return this->surface;
}

void Sprite::SetSurface(const char* path) {
	this->surface = ResourceManager::Instance()->GetSurface(path);

	this->surfacePath = path;
}

const char* Sprite::GetSurfacePath() {
	return this->surfacePath;
}

void Sprite::GenerateTexture() {
	if (this->surface == nullptr) {
		return;
	}

	glEnable(GL_TEXTURE_2D);

	GLuint texture;
	glGenTextures(1, &texture);
	this->texture = texture;
}

GLint Sprite::GetTexture() { return this->texture; }

void Sprite::EditorSettings() {
	{
		ImGui::Begin("Sprite");

		ImGui::Text("Surface File (in resources folder)");

		static char path[50];
		ImGui::InputText("", path, IM_ARRAYSIZE(path));

		ImGui::SameLine();

		if (ImGui::Button("Set")) {
			this->SetSurface(Core::Instance()->GetResourcePath(path).c_str());
		}

		float position[] = { scale.GetX(), scale.GetY() };
		ImGui::InputFloat2("Scale", position, 2, 0);

		scale = Vector2(position[0], position[1]);

		ImGui::End();
	}
}

Component* Sprite::Copy() {
	Component* component = new Sprite();
	return component;
}


const char* Sprite::OnSave() {
	std::string tempString;
	tempString.append(this->GetSurfacePath());
	return tempString.c_str();
}

void Sprite::OnLoad(const char* data) {
	
}