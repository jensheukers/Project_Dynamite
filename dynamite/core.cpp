/**
*	Filename: core.cpp
*
*	Description: Source file for core.h 
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/


#include "core.h"

int main(int argc, char* argv[]) {
	Core core(argv);
	return 0;
}

Core::Core(char* arguments[]) {
	
	std::string mainDirPathFull = arguments[0];

	std::size_t found = mainDirPathFull.find_last_of("/\\");
	mainDirPath = mainDirPathFull.substr(0, found);

	printf("DYNAMITE: %s\n", mainDirPath.c_str());
	

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("DYNAMITE: SDL Could not initialize. SDL_ERROR: $s\n", SDL_GetError());
		return;
	}
	
	window = SDL_CreateWindow(Game::GetGameName(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::GetWindowDimensionsX(), Game::GetWindowDimensionsY(), SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		printf("DYNAMITE: SDL_Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}

	screenSurface = SDL_GetWindowSurface(window);

	renderer = new Renderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE));

	game = new Game(this);
	running = true;

	printf("DYNAMITE: Game Started! \n");

	while (IsRunning()) {
		HandleEvents();
		HandleFrames();
	}
}

void Core::HandleFrames() {
	renderer->Clear();
	game->Update();
	HandleEntities();
	renderer->Draw();
}

void Core::HandleEntities() {
	for (int i = 0; i < entities.Size(); i++) {
		Entity* temp = *entities.Get(i);
		if (temp->HasComponent<Sprite>()) {
			renderer->RenderEntity(temp);
		}
	}
}

void Core::HandleEvents() {
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) { //Handle events
		if (sdlEvent.type == SDL_QUIT) {
			running = false;
		}
	}
}

void Core::AddEntity(Entity* entity) {
	entities.Push(entity);
}

void Core::RemoveEntity(int index) {
	entities.Remove(index);
}

Entity* Core::GetEntity(int index) {
	return *entities.Get(index);
}