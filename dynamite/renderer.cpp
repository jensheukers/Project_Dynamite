/**
*	Filename: renderer.cpp
*
*	Description: Source file for Renderer class
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/


#include "renderer.h";
#include "SDL_opengl.h"
#include "../game/game.h"

Renderer::Renderer() {
	sdlRendererFound = false;
}

Renderer::Renderer(SDL_Renderer* sdlRenderer) {
	this->sdlRenderer = sdlRenderer;
	sdlRendererFound = true;
}

void Renderer::SetSdlRenderer(SDL_Renderer* sdlRenderer) {
	this->sdlRenderer = sdlRenderer;
	sdlRendererFound = true;
}

void Renderer::RemoveSdlRenderer() {
	this->sdlRenderer = nullptr;
	sdlRendererFound = false;
}

void Renderer::InitOpenGL() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glOrtho(0.0f, (int)Game::GetWindowDimensions().GetX(), (int)Game::GetWindowDimensions().GetY(), 0.0f, 0.0f, 1.0f);

	glClearColor(0.f,0.f,0.f,1.f);
}

void Renderer::Clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::RenderEntity(Entity* entity, Camera* activeCamera) {
	if (entity->GetComponent<Sprite>()->GetSurface() == nullptr) {
		//printf("DYNAMITE: ~Renderer~ entity object has no surface!\n");
		return;
	}
	
	SDL_Surface surface = *entity->GetComponent<Sprite>()->GetSurface();

	float scaleX = entity->GetComponent<Sprite>()->GetScale().GetX();
	float scaleY = entity->GetComponent<Sprite>()->GetScale().GetY();

	glPushMatrix();

	glTranslatef(entity->position.GetX() * scaleX, entity->position.GetY() * scaleX, 0);
	glRotatef(entity->GetRotation(), 0.0, 0.0, 1.0);
	glTranslatef(-entity->position.GetX() * scaleX, -entity->position.GetY() * scaleY, 0);

	glBegin(GL_QUADS);
		glVertex2f(entity->position.GetX() * scaleX, entity->position.GetY()  * scaleY);
		glVertex2f((entity->position.GetX() + surface.w)  * scaleX, entity->position.GetY()  * scaleY);
		glVertex2f((entity->position.GetX() + surface.w)  * scaleX, (entity->position.GetY() + surface.h) * scaleY);
		glVertex2f(entity->position.GetX()  * scaleX, (entity->position.GetY() + surface.h) * scaleY);
	glEnd();

	glPopMatrix();
}

void Renderer::Draw(SDL_Window* window) {
	SDL_GL_SwapWindow(window);
}