/**
*	Filename: game.cpp
*
*	Version: VERSION
*
*	© 2018, YOUR COMPANY NAME
*/

#include "../dynamite/core.h"
#include "../dynamite/ui/text.h"
#include "game.h"

Game::Game() {
	SceneManager::Instance()->LoadExternalScene(Core::Instance()->GetResourcePath("test.dynamite"));
	SceneManager::Instance()->SetActiveScene("test");

	Font* bluefont = new Font(Core::Instance()->GetResourcePath("font2.tga"), Core::Instance()->GetResourcePath("font2.csv"));
	bluefont->SetColor(ColorRGB(0,0,255));

	Text* text = new Text(bluefont);
	text->SetText("Bigger Text");
	text->position = Vector2(50,50);
	SceneManager::Instance()->GetActiveScene()->AddUIElement(text);
}

void Game::Update() {	

}