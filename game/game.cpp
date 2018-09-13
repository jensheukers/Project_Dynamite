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

	core->SetActiveCamera(new Camera());

	entity = new Entity();

	entity->AddComponent<Sprite>();

	entity->GetComponent<Sprite>()->SetSurface(core->GetResourceManager()->GetSurface(core->GetResourcePath("cube.bmp")));
	entity->GetComponent<Sprite>()->SetTexture(core->GetResourceManager()->GetTexture(core->GetResourcePath("cube.bmp")));

	core->AddEntity(entity);


	core->AddAxis("Horizontal",KeyCode::D,KeyCode::A);
	core->AddAxis("Vertical", KeyCode::S, KeyCode::W);
}

void Game::Update() {
	int x = core->GetAxis("Horizontal");
	int y = core->GetAxis("Vertical");

	entity->position = Vector2(entity->position.GetX() + x, entity->position.GetY() + y);

}