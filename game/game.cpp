/**
*	Filename: game.cpp
*
*	Version: VERSION
*
*	© 2018, YOUR COMPANY NAME
*/

#include "../dynamite/core.h"
#include "game.h"

Game::Game() {
	SceneManager::Instance()->LoadExternalScene(Core::Instance()->GetResourcePath("test.dynamite"));
	SceneManager::Instance()->SetActiveScene("test");
}

void Game::Update() {
}