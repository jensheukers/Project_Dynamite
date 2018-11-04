/**
*	Filename: renderer.cpp
*
*	Description: Source file for Renderer class
*	Version: 2/11/2018
*
*	© 2018, Jens Heukers
*/


#include "renderer.h"
#include <SDL_opengl.h>
#include "../game/game.h"
#include "component/collider.h"
#include "ui\font.h"

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

void Renderer::RenderEntity(Entity* entity, bool uiElement) {
	glPushAttrib(GL_CURRENT_BIT);
	if (entity->GetComponent<Sprite>()->GetTexture() == nullptr) {
		return;
	}
	//Generate GL Texture from surface
	Texture* texture = entity->GetComponent<Sprite>()->GetTexture();

	glEnable(GL_TEXTURE_2D);

	//Calculate scales and camera positions
	float scaleX = entity->GetScale().GetX();
	float scaleY = entity->GetScale().GetY();
	float camX = 0;
	float camY = 0;
	if (!uiElement) {
		camX = SceneManager::Instance()->GetActiveScene()->GetActiveCamera()->GetXCoord();
		camY = SceneManager::Instance()->GetActiveScene()->GetActiveCamera()->GetYCoord();
	}


	glBindTexture(GL_TEXTURE_2D, entity->GetComponent<Sprite>()->GetTexture()->GetTexturePointer());


	//Rotation
	glPushMatrix();
	glTranslatef((entity->position.GetX() + (entity->GetComponent<Sprite>()->GetTexture()->textureData->width / 2)) + camX, 
				(entity->position.GetY() + (entity->GetComponent<Sprite>()->GetTexture()->textureData->height / 2)) + camY, 0);

	glRotatef(entity->GetRotation(), 0.0, 0.0, 1.0);

	glTranslatef((-entity->position.GetX() - (entity->GetComponent<Sprite>()->GetTexture()->textureData->width / 2)) - camX,
		(-entity->position.GetY() - (entity->GetComponent<Sprite>()->GetTexture()->textureData->height / 2)) - camY, 0);

	//Draw vertecies
	Vector2 calPos = Vector2(entity->position.GetX() + -camX, entity->position.GetY() + -camY);

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(calPos.GetX(), calPos.GetY()); //LU
		glTexCoord2f(1.0f, 1.0f); glVertex2f(calPos.GetX() + (scaleX * texture->textureData->width), calPos.GetY()); //RU
		glTexCoord2f(1.0f, 0.0f); glVertex2f(calPos.GetX() + (scaleX * texture->textureData->width), calPos.GetY() + (scaleY * texture->textureData->height)); //RD
		glTexCoord2f(0.0f, 0.0f); glVertex2f(calPos.GetX(), calPos.GetY() + (scaleY * texture->textureData->height)); //LD
	glEnd();
	glDisable(GL_TEXTURE_2D);

	if (entity->HasComponent<Collider>() && Core::Instance()->DEBUG_SHOW_COLLIDERS) {
		glLineWidth(2);
		glColor3f(0.0, 255.0, 0.0);
		glBegin(GL_LINES);
		glVertex2f(entity->position.GetX() + camX, entity->position.GetY() + camY);
		glVertex2f((entity->position.GetX() + camX) + entity->GetComponent<Collider>()->GetBounds().GetX(), entity->position.GetY() + camY);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f((entity->position.GetX() + camX) + entity->GetComponent<Collider>()->GetBounds().GetX(), entity->position.GetY() + camY);
		glVertex2f((entity->position.GetX() + camX) + entity->GetComponent<Collider>()->GetBounds().GetX(), (entity->position.GetY() + camY) + entity->GetComponent<Collider>()->GetBounds().GetY());
		glEnd();

		glBegin(GL_LINES);
		glVertex2f((entity->position.GetX() + camX) + entity->GetComponent<Collider>()->GetBounds().GetX(), (entity->position.GetY() + camY) + entity->GetComponent<Collider>()->GetBounds().GetY());
		glVertex2f(entity->position.GetX() + camX, (entity->position.GetY() + camY) + entity->GetComponent<Collider>()->GetBounds().GetY());
		glEnd();


		glBegin(GL_LINES);
		glVertex2f(entity->position.GetX() + camX, (entity->position.GetY() + camY) + entity->GetComponent<Collider>()->GetBounds().GetY());
		glVertex2f(entity->position.GetX() + camX, entity->position.GetY() + camY);
		glEnd();

	}

	glPopAttrib();
	glPopMatrix();
}

void Renderer::RenderText(Text* text) {
	Font* font = text->GetFont();

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, font->GetTexturePointer());

	glBegin(GL_QUADS);
	for (int i = 0; i < text->GetLenght(); i++) {
		std::vector<Vector2> coords = font->GetCharacterCoordinates(text->GetChar(i));
		glTexCoord2f(coords[0].GetX(), coords[0].GetY()); glVertex2f(text->position.GetX() * i, text->position.GetY()); //LU
		glTexCoord2f(coords[1].GetX(), coords[1].GetY()); glVertex2f(text->position.GetX() + font->GetCharSize().GetX() * i, text->position.GetY());//RU
		glTexCoord2f(coords[2].GetX(), coords[2].GetY()); glVertex2f(text->position.GetX() + font->GetCharSize().GetX() * i, text->position.GetY() + font->GetCharSize().GetY());//RD
		glTexCoord2f(coords[3].GetX(), coords[3].GetY()); glVertex2f(text->position.GetX() * i, text->position.GetY() + font->GetCharSize().GetY());//LD
		}
	glEnd();

	glDisable(GL_TEXTURE_2D);

}

void Renderer::Draw(SDL_Window* window) {
	SDL_GL_SwapWindow(window);
}