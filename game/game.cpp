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
	SceneManager::Instance()->CreateScene("scene");
	SceneManager::Instance()->SetActiveScene("scene");
	SceneManager::Instance()->GetActiveScene()->SetActiveCamera(new Camera());

	Entity* entity = new Entity();
	entity->AddComponent<Sprite>()->SetTexture(Core::Instance()->GetResourcePath("destroyer_Arrows.tga").c_str());

	SceneManager::Instance()->GetActiveScene()->AddEntity(entity);
}

void Game::Update() {
}