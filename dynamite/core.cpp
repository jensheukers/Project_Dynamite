/**
*	Filename: core.cpp
*
*	Description: Source file for core.h 
*
*	© 2018, Jens Heukers
*/


#include "core.h"
#include <sstream>

int main(int argc, char* argv[]) {
	new Core(argv);
	return 0;
}

Core* Core::_instance;


Core* Core::Instance() {
	if (!_instance) {
		std::cout << "DYNAMITE: Core instance not created.";
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
	timeCurrent = timeStart;
	timeElapsed = timeStart - timeCurrent; // 0

	std::string mainDirPathFull = arguments[0];

	std::size_t found = mainDirPathFull.find_last_of("/\\");
	mainDirPath = mainDirPathFull.substr(0, found);

	std::cout << "DYNAMITE: ~Core~ Executable path: " << mainDirPath.c_str() << std::endl;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "DYNAMITE: ~Core~ SDL Could not initialize. SDL_ERROR:" << SDL_GetError() << std::endl;
		return;
	}

	const char* glsl_version = "#version 130\n";

	window = SDL_CreateWindow(Game::GetGameName(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)Game::GetWindowDimensions().GetX(), (int)Game::GetWindowDimensions().GetY(), SDL_WINDOW_OPENGL);

	if (window == NULL)
	{
		std::cout << "DYNAMITE: ~Core~ SDL_Window could not be created! SDL_Error:" << SDL_GetError() << std::endl;
	}

	screenSurface = SDL_GetWindowSurface(window);
	SDL_GLContext context = SDL_GL_CreateContext(window);

	SDL_GL_MakeCurrent(window,context);

	Renderer::Instance()->InitOpenGL();

	//Initialize GLEW
	glewExperimental = true;
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cout << "DYNAMITE: ~Core~ Glew could not be initialized. GLEW_ERROR: " << glewGetErrorString(err) << std::endl;
	}

	std::cout << "DYNAMITE: ~Core~ Calling Game()" << std::endl;

	DEBUG_SHOW_COLLIDERS = false;

	game = new Game();

	running = true;

	std::cout << "DYNAMITE: ~Core~ Game Started!" << std::endl;

	//Amount of frames rendered in the last second.
	unsigned frames;

	//Last frame check time
	unsigned lastFrameCheckTime = 0;

	unsigned lastStatusUpdateIntervalTime = STATUS_UPDATE_INTERVAL_TIME;

	//Game loop
	while (IsRunning()) {

		//Handle Time
		timeCurrent = std::chrono::time_point_cast<std::chrono::milliseconds>(Time::now()).time_since_epoch().count();
		float _delta = timeCurrent;

		timeElapsed = timeCurrent - timeStart;
		frames++;

		if (timeCurrent - lastFrameCheckTime > 1000) {
			lastFrameCheckTime = timeCurrent;
			framesPerSecond = frames;
			frames = 0;
		}

		if (timeElapsed > lastStatusUpdateIntervalTime) {
			StatusUpdate();
			lastStatusUpdateIntervalTime += STATUS_UPDATE_INTERVAL_TIME;
		}

		//Handle Events
		HandleEvents();

		//Update the components of entities 
		if (SceneManager::Instance()->GetActiveScene() != nullptr) {
			for (int i = 0; i < SceneManager::Instance()->GetActiveScene()->GetEnties().size(); i++) {
				SceneManager::Instance()->GetActiveScene()->GetEntity(i)->Update();
				SceneManager::Instance()->GetActiveScene()->GetEntity(i)->UpdateComponents();
			}
		}

		//Update the game
		game->Update();

		//Handle rendering to screen
		Renderer::Instance()->Clear();

		if (SceneManager::Instance()->GetActiveScene() != nullptr) {
			for (int i = 0; i < SceneManager::Instance()->GetActiveScene()->GetEnties().size(); i++) {
				Entity* entityCurrent = SceneManager::Instance()->GetActiveScene()->GetEnties()[i];
				if (entityCurrent->HasComponent<Sprite>() && SceneManager::Instance()->GetActiveScene()->HasActiveCamera()) {
					Renderer::Instance()->RenderEntity(SceneManager::Instance()->GetActiveScene()->GetEnties()[i], SceneManager::Instance()->GetActiveScene()->GetActiveCamera());
				}
			}

		}
		Renderer::Instance()->Draw(window);

		//Calculate DeltaTime
		deltaTime = (std::chrono::time_point_cast<std::chrono::milliseconds>(Time::now()).time_since_epoch().count() - _delta) / 100;
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

void Core::StatusUpdate() {
	//Check if a scene is existant
	std::string logString = "FPS = ";
	logString.append(std::to_string(framesPerSecond));
	if (SceneManager::Instance()->GetActiveScene() == nullptr) {
		logString.append(" | ");
		logString.append("No active scene....");
	}
	else {
		if (!SceneManager::Instance()->GetActiveScene()->GetActiveCamera()) {
			logString.append(" | ");
			logString.append("No active camera....");
		}
	}
	Log(logString);
}

void Core::Log(std::string string) {
	std::cout << "DYNAMITE: ";
	std::cout << Core::Instance()->GetTimeElapsed() << " : ";
	std::cout << string.c_str() << std::endl;
}