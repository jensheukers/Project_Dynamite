/**
*	Filename: core.cpp
*
*	Description: Source file for core.h 
*
*	© 2018, Jens Heukers
*/


#include "core.h"

int main(int argc, char* argv[]) {
	new Core(argv);
	return 0;
}

Core* Core::_instance;


Core* Core::Instance() {
	if (!_instance) {
		printf("DYNAMITE: Core instance not created.");
	}
	
	return _instance;
}

Core::Core(char* arguments[]) {

	if (_instance) {
		return;
	}
	_instance = this;

	//Set timeStart value to current time in milliseconds
	timeStart = std::chrono::time_point_cast<std::chrono::milliseconds>(Time::now()).time_since_epoch().count();

	std::string mainDirPathFull = arguments[0];

	std::size_t found = mainDirPathFull.find_last_of("/\\");
	mainDirPath = mainDirPathFull.substr(0, found);

	printf("DYNAMITE: ~Core~ Executable path: %s\n", mainDirPath.c_str());
	
	activeCamera = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("DYNAMITE: ~Core~ SDL Could not initialize. SDL_ERROR: $s\n", SDL_GetError());
		return;
	}

	const char* glsl_version = "#version 130\n";

	window = SDL_CreateWindow(Game::GetGameName(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)Game::GetWindowDimensions().GetX(), (int)Game::GetWindowDimensions().GetY(), SDL_WINDOW_OPENGL);

	if (window == NULL)
	{
		printf("DYNAMITE: ~Core~ SDL_Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}

	screenSurface = SDL_GetWindowSurface(window);
	SDL_GLContext context = SDL_GL_CreateContext(window);

	SDL_GL_MakeCurrent(window,context);

	Renderer::Instance()->InitOpenGL();

	//Initialize GLEW
	glewExperimental = true;
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		printf("DYNAMITE: ~Core~ Glew could not be initialized. GLEW_ERROR: %s\n", glewGetErrorString(err));
	}

	printf("DYNAMITE: ~Core~ Calling Game()\n");

	game = new Game();

	running = true;

	printf("DYNAMITE: ~Core~ Game Started! \n");

	//Amount of frames rendered in the last second.
	unsigned frames;

	unsigned lastFrameCheckTime = 0;

	//Game loop
	while (IsRunning()) {

		//Handle Time
		timeCurrent = std::chrono::time_point_cast<std::chrono::milliseconds>(Time::now()).time_since_epoch().count();
		timeElapsed = timeCurrent - timeStart;
		frames++;

		if (timeCurrent - lastFrameCheckTime > 1000) {
			lastFrameCheckTime = timeCurrent;
			framesPerSecond = frames;
			frames = 0;
		}

		//Handle Events
		HandleEvents();

		//Update the components of entities 
		if (SceneManager::Instance()->GetActiveScene() != nullptr) {
			for (int i = 0; i < SceneManager::Instance()->GetActiveScene()->GetEnties().size(); i++) {
				SceneManager::Instance()->GetActiveScene()->GetEntity(i)->UpdateComponents();
			}
		}

		//Update the game
		game->Update();

		//Handle rendering to screen
		Renderer::Instance()->Clear();

		if (SceneManager::Instance()->GetActiveScene() != nullptr) {
			for (int i = 0; i < SceneManager::Instance()->GetActiveScene()->GetEnties().size(); i++) {
				if (SceneManager::Instance()->GetActiveScene()->GetEnties()[i]->HasComponent<Sprite>() && HasActiveCamera()) {
					Renderer::Instance()->RenderEntity(SceneManager::Instance()->GetActiveScene()->GetEnties()[i], activeCamera);
				}
			}
		}
		Renderer::Instance()->Draw(window);
	}
}

std::string Core::GetResourceDirectory() {
	std::string convertedString = mainDirPath;
	return convertedString.append("\\resources\\");
}

std::string Core::GetResourcePath(const char* name) {
	return this->GetResourceDirectory().append(name);
}

void Core::HandleEvents() {
	Input::Instance()->Handle();
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) { //Handle events
		switch (sdlEvent.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				Input::Instance()->HandleKeyPressEvent(sdlEvent.key.keysym.scancode);
				break;
			case SDL_KEYUP:
				Input::Instance()->HandleKeyReleaseEvent(sdlEvent.key.keysym.scancode);
				break;
			case SDL_MOUSEMOTION:
				Input::Instance()->HandleMouseMotion(Vector2((float)sdlEvent.motion.x, (float)sdlEvent.motion.y));
				break;
			case SDL_MOUSEBUTTONDOWN:
				Input::Instance()->HandleButtonPressEvent(sdlEvent.button.button);
				break;

			case SDL_MOUSEBUTTONUP:
				Input::Instance()->HandleButtonReleaseEvent(sdlEvent.button.button);
				break;
		}
	}
}
bool Core::HasActiveCamera() {
	if (this->activeCamera != nullptr) {
		return true;
	}
	return false;
}