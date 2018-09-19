/**
*	Filename: core.cpp
*
*	Description: Source file for core.h 
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/


#include "core.h"
#include <chrono>

int main(int argc, char* argv[]) {
	Core core(argv);
	return 0;
}

Core::Core(char* arguments[]) {
	
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

	sceneManager = new SceneManager(this);
	renderer = new Renderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE));
	renderer->InitOpenGL();
	resourceManager = new ResourceManager(renderer);
	input = new Input();

	//Initialize GLEW
	glewExperimental = true;
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		printf("DYNAMITE: ~Core~ Glew could not be initialized. GLEW_ERROR: %s\n", glewGetErrorString(err));
	}

	// Setup Dear ImGui binding
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

	ImGui_ImplSDL2_InitForOpenGL(window, context);
	ImGui_ImplOpenGL3_Init(glsl_version);

	//Imgui Style
	ImGui::StyleColorsDark();


	printf("DYNAMITE: ~Core~ Calling Game()\n");

	if (!Game::LaunchEditorMode()) {
		game = new Game(this);
	}
	else {
		game = new Editor(this);
	}

	running = true;
	commandPromptActive = false;

	printf("DYNAMITE: ~Core~ Game Started! \n");


	if (!HasActiveCamera()) {
		printf("DYNAMITE: ~Core~ No active camera found, please create a camera and set it as active\n");
	}

	//Game loop
	while (IsRunning()) {

		//Handle Events
		HandleEvents();


		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame(window);
		ImGui::NewFrame();

		//Update the components of entities 

		for (int i = 0; i < sceneManager->GetActiveScene()->GetEnties().size(); i++) {
			sceneManager->GetActiveScene()->GetEntity(i)->UpdateComponents();
		}

		//Update the game
		game->Update();


		//Command Prompt
		if (GetKeyDown(KeyCode::Slash) && GetKeyDown(KeyCode::Minus)) {
			commandPromptActive = true;
		}

		if (commandPromptActive) {
			char input[50];

			ImGui::Begin("Command Prompt");
			ImGui::InputText("Input", input, sizeof(input));

			if (ImGui::Button("Run"))
			{
				printf("DYNAMITE: ~Core~ Console commands are still W.I.P\n");
			}

			ImGui::End();
		}

		if (GetKeyPressed(KeyCode::Grave)) {
			if (!commandPromptActive) {
				commandPromptActive = true;
			}
			else {
				commandPromptActive = false;
			}
		}

		//Handle rendering to screen
		renderer->Clear();

		ImGui::Render();

		for (int i = 0; i < sceneManager->GetActiveScene()->GetEnties().size(); i++) {
			if (sceneManager->GetActiveScene()->GetEnties()[i]->HasComponent<Sprite>() && HasActiveCamera()) {
				renderer->RenderEntity(sceneManager->GetActiveScene()->GetEnties()[i], activeCamera);
			}
		}

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		renderer->Draw(window);
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
	input->Handle();
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) { //Handle events
		ImGui_ImplSDL2_ProcessEvent(&sdlEvent);
		switch (sdlEvent.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				input->HandleKeyPressEvent(sdlEvent.key.keysym.scancode);
				break;
			case SDL_KEYUP:
				input->HandleKeyReleaseEvent(sdlEvent.key.keysym.scancode);
				break;
			case SDL_MOUSEMOTION:
				input->HandleMouseMotion(Vector2((float)sdlEvent.motion.x, (float)sdlEvent.motion.y));
				break;
			case SDL_MOUSEBUTTONDOWN:
				input->HandleButtonPressEvent(sdlEvent.button.button);
				break;

			case SDL_MOUSEBUTTONUP:
				input->HandleButtonReleaseEvent(sdlEvent.button.button);
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