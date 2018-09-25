/**
*	Filename: sprite.cpp
*
*	Description: Main Source for Sprite Component.
*	Version: 0.3
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

void Sprite::SetSurface(SDL_Surface* surface) {
	this->surface = surface;
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
			this->SetSurface(ResourceManager::Instance()->GetSurface(Core::Instance()->GetResourcePath(path)));
		}

		float position[] = { scale.GetX(), scale.GetY() };
		ImGui::InputFloat2("Scale", position, 2, 0);

		scale = Vector2(position[0], position[1]);

		ImGui::End();
	}
}