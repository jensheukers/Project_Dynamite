/**
*	Filename: renderer.cpp
*
*	Description: Source file for Renderer class
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/


#include "renderer.h";

Renderer::Renderer() {
	sdlRendererFound = false;
}

Renderer::Renderer(SDL_Renderer* sdlRenderer) {
	this->sdlRenderer = sdlRenderer;
	sdlRendererFound = true;
}

void Renderer::SetSdlRenderer(SDL_Renderer* sdlRenderer) {
	this->sdlRenderer = sdlRenderer;
	sdlRendererFound = true;
}

void Renderer::RemoveSdlRenderer() {
	this->sdlRenderer = nullptr;
	sdlRendererFound = false;
}

void Renderer::CreateSpriteTextureFromSurface(Sprite* sprite) {
	SDL_Texture* generatedTexture = SDL_CreateTextureFromSurface(sdlRenderer,sprite->GetSurface());

	if (generatedTexture == NULL) {
		printf("DYNAMITE: Failed to generate texture ERROR: %s", SDL_GetError());
		delete generatedTexture;
		return;
	}

	sprite->SetTexture(generatedTexture);
}