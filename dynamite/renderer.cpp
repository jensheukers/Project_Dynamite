/**
*	Filename: renderer.cpp
*
*	Description: Source file for Renderer class
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/


#include "renderer.h"
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
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);

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

	SDL_Surface* surface = entity->GetComponent<Sprite>()->GetSurface();

	float scaleX = entity->GetComponent<Sprite>()->GetScale().GetX();
	float scaleY = entity->GetComponent<Sprite>()->GetScale().GetY();
	float camX = activeCamera->GetXCoord();
	float camY = activeCamera->GetYCoord();
	float baseScale = 1;


	//Rotation
	glPushMatrix();
	glTranslatef((entity->position.GetX()) + camX, (entity->position.GetY()) + camY, 0);
	glRotatef(entity->GetRotation(), 0.0, 0.0, 1.0);
	glTranslatef((-entity->position.GetX()) - camX, (-entity->position.GetY()) - camY, 0);

	//Draw vertecies
	Vector2 lu = Vector2(entity->position.GetX(), entity->position.GetY());
	Vector2 ru = Vector2(entity->position.GetX(), entity->position.GetY());
	Vector2 rd = Vector2(entity->position.GetX(), entity->position.GetY());
	Vector2 ld = Vector2(entity->position.GetX(), entity->position.GetY());



	glBegin(GL_QUADS);
		glVertex2f(lu.GetX(), lu.GetY()); //LU
		glVertex2f(ru.GetX() + (scaleX * surface->w), ru.GetY()); //RU
		glVertex2f(rd.GetX() + (scaleX * surface->w), rd.GetY() + (scaleY * surface->h)); //RD
		glVertex2f(ld.GetX(), rd.GetY() + (scaleY * surface->h)); //LD
	glEnd();

	glPopMatrix();
}

void Renderer::Draw(SDL_Window* window) {
	SDL_GL_SwapWindow(window);
}