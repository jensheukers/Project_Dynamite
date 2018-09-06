/**
*	Filename: game.cpp
*
*	Version: VERSION
*
*	© 2018, YOUR COMPANY NAME
*/

#include "../dynamite/core.h"
#include "game.h"

Game::Game(Core* core) {
	this->core = core;
	Entity* entity = new Entity();

	entity->AddComponent<Sprite>();
	
	entity->GetComponent<Sprite>()->SetSurface(core->GetResourceManager()->GetSurface(core->GetResourcePath("cube.bmp")));
	entity->GetComponent<Sprite>()->SetTexture(core->GetResourceManager()->GetTexture(core->GetResourcePath("cube.bmp")));

}

void Game::Update() {

}