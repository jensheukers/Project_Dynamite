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

Renderer* Renderer::_instance;

Renderer* Renderer::Instance() {
	if (!_instance) {
		_instance = new Renderer();
	}
	return _instance;
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
		return;
	}
	//Generate GL Texture from surface
	SDL_Surface* surface = entity->GetComponent<Sprite>()->GetSurface();

	glEnable(GL_TEXTURE_2D);

	if (entity->GetComponent<Sprite>()->GetTexture() == NULL) {
		entity->GetComponent<Sprite>()->GenerateTexture();
	}

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Map the surface to the texture in video memory
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_BGR, GL_UNSIGNED_BYTE, surface->pixels);

	//Calculate scales and camera positions
	float scaleX = entity->GetComponent<Sprite>()->GetScale().GetX();
	float scaleY = entity->GetComponent<Sprite>()->GetScale().GetY();
	float camX = activeCamera->GetXCoord();
	float camY = activeCamera->GetYCoord();


	//Rotation
	glPushMatrix();
	glTranslatef((entity->position.GetX()) + camX, (entity->position.GetY()) + camY, 0);
	glRotatef(entity->GetRotation(), 0.0, 0.0, 1.0);
	glTranslatef((-entity->position.GetX()) - camX, (-entity->position.GetY()) - camY, 0);

	//Draw vertecies
	Vector2 lu = Vector2(entity->position.GetX() + camX, entity->position.GetY() + camY);
	Vector2 ru = Vector2(entity->position.GetX() + camX, entity->position.GetY() + camY);
	Vector2 rd = Vector2(entity->position.GetX() + camX, entity->position.GetY() + camY);
	Vector2 ld = Vector2(entity->position.GetX() + camX, entity->position.GetY() + camY);


	glBindTexture(GL_TEXTURE_2D, *entity->GetComponent<Sprite>()->GetTexture());
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(lu.GetX(), lu.GetY()); //LU
		glTexCoord2f(1.0f, 0.0f); glVertex2f(ru.GetX() + (scaleX * surface->w), ru.GetY()); //RU
		glTexCoord2f(1.0f, 1.0f); glVertex2f(rd.GetX() + (scaleX * surface->w), rd.GetY() + (scaleY * surface->h)); //RD
		glTexCoord2f(0.0f, 1.0f); glVertex2f(ld.GetX(), rd.GetY() + (scaleY * surface->h)); //LD
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Renderer::Draw(SDL_Window* window) {
	SDL_GL_SwapWindow(window);
}