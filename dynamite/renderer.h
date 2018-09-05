#pragma once
#include "SDL.h"
#include "jhe_main.h"

class Renderer {
private:
	SDL_Renderer* sdlRenderer;
	bool sdlRendererFound;
public:
	Renderer();
	Renderer(SDL_Renderer* sdlRenderer);
	void SetSdlRenderer(SDL_Renderer* sdlRenderer);
	void RemoveSdlRenderer();
	bool HasSdlRenderer() { return sdlRendererFound; };
};