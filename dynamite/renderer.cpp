/**
*	Filename: renderer.cpp
*
*	Description: Source file for Renderer class
*	Version: 5/11/2018
*
*	© 2018, Jens Heukers
*/


#include "renderer.h"
#include <SDL_opengl.h>
#include "../game/game.h"
#include "component/collider.h"

ColorRGB::ColorRGB(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

ColorRGBA::ColorRGBA(int r, int g, int b, int a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}


UVData::UVData() {
	this->_leftUp = Vector2(0.0f, 1.0f);
	this->_rightUp = Vector2(1.0f, 1.0f);
	this->_rightDown = Vector2(1.0f, 0.0f);
	this->_leftDown = Vector2(0.0f, 0.0f);
}

UVData::UVData(Vector2 _leftUp, Vector2 _rightUp, Vector2 _rightDown, Vector2 _leftDown) {
	this->_leftUp = _leftUp;
	this->_rightUp = _rightUp;
	this->_rightDown = _rightDown;
	this->_leftDown = _leftDown;
}

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
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glOrtho(0.0f, (int)Game::GetWindowDimensions().GetX(), (int)Game::GetWindowDimensions().GetY(), 0.0f, 0.0f, 1.0f);

	glClearColor(0.f,0.f,0.f,1.f);
}

void Renderer::Clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::RenderTexture(Texture* texture, Vector2 position, Vector2 scale, float rotation, UVData uvData) {
	glPushAttrib(GL_CURRENT_BIT);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture->GetGLTexture());

	glPushMatrix();

	glTranslatef(position.GetX() + (texture->textureData->width / 2), position.GetY() + (texture->textureData->height / 2),0);
	glRotatef(rotation, 0.0, 0.0, 1.0);
	glTranslatef(-position.GetX() - (texture->textureData->width / 2),-position.GetY() - (texture->textureData->height / 2), 0);

	//Draw the mesh and handle uv's
	glBegin(GL_QUADS);
		glTexCoord2f(uvData._leftUp.GetX(), uvData._leftUp.GetY()); glVertex2f(position.GetX(), position.GetY()); //LU
		glTexCoord2f(uvData._rightUp.GetX(), uvData._rightUp.GetY()); glVertex2f(position.GetX() + (scale.GetX() * texture->textureData->width), position.GetY()); //RU
		glTexCoord2f(uvData._rightDown.GetX(), uvData._rightDown.GetY()); glVertex2f(position.GetX() + (scale.GetX() * texture->textureData->width), position.GetY() + (scale.GetY() * texture->textureData->height)); //RD
		glTexCoord2f(uvData._leftDown.GetX(), uvData._leftDown.GetY()); glVertex2f(position.GetX(), position.GetY() + (scale.GetY() * texture->textureData->height)); //LD
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPopAttrib();
}

void Renderer::RenderCube(Vector2 position, Vector2 bounds, ColorRGB color) {
	glPushAttrib(GL_CURRENT_BIT);
	glPushMatrix();

	glLineWidth(2);
	glColor3f((GLfloat)color.r, (GLfloat)color.g, (GLfloat)color.b);
	glBegin(GL_LINES);
		glVertex2f(position.GetX(), position.GetY());
		glVertex2f(position.GetX() + bounds.GetX(), position.GetY());
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(position.GetX() + bounds.GetX(), position.GetY());
		glVertex2f(position.GetX() + bounds.GetX(), position.GetY() + bounds.GetY());
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(position.GetX() + bounds.GetX(), position.GetY() + bounds.GetY());
		glVertex2f(position.GetX(), position.GetY() + bounds.GetY());
	glEnd();


	glBegin(GL_LINES);
		glVertex2f(position.GetX(), position.GetY() + bounds.GetY());
		glVertex2f(position.GetX(), position.GetY());
	glEnd();

	glPopAttrib();
	glPopMatrix();
}

void Renderer::Draw(SDL_Window* window) {
	SDL_GL_SwapWindow(window);
}