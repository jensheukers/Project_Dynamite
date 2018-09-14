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

	glClearColor(0.f,0.f,0.f,1.f);
}

void Renderer::Clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::RenderEntity(Entity* entity, Camera* activeCamera) {
	if (entity->GetComponent<Sprite>()->GetSurface() == nullptr) {
		printf("DYNAMITE: ~Renderer~ entity object has no surface!\n");
		return;
	}
	
	SDL_Surface surface = *entity->GetComponent<Sprite>()->GetSurface();

	//Multiply the scale with 0.01 to have a size more relative to screen
	float scale = entity->GetComponent<Sprite>()->GetScale() * 0.01f;

	glBegin(GL_QUADS);
		glVertex2f(entity->position.GetX() * scale, entity->position.GetY()  * scale);
		glVertex2f((entity->position.GetX() + surface.w)  * scale, entity->position.GetY()  * scale);
		glVertex2f((entity->position.GetX() + surface.w)  * scale, (entity->position.GetY() + surface.h) * scale);
		glVertex2f(entity->position.GetX()  * scale, (entity->position.GetY() + surface.h) * scale);
	glEnd();
}

void Renderer::Draw(SDL_Window* window) {
	SDL_GL_SwapWindow(window);
}