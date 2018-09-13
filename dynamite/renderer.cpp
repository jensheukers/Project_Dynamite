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

SDL_Texture* Renderer::CreateTextureFromSurface(SDL_Surface* surface) {
	SDL_Texture* generatedTexture = SDL_CreateTextureFromSurface(sdlRenderer, surface);

	if (generatedTexture == NULL) {
		printf("DYNAMITE: ~Renderer~ Failed to generate texture ERROR: %s\n", SDL_GetError());
		delete generatedTexture;
		return  nullptr;
	}

	return generatedTexture;
}

void Renderer::Clear() {
	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
	SDL_RenderClear(sdlRenderer);
	SDL_SetRenderDrawBlendMode(sdlRenderer, SDL_BLENDMODE_BLEND);
}

void Renderer::RenderEntity(Entity* entity, Camera* activeCamera) {
	if (entity->GetComponent<Sprite>()->GetSurface() == nullptr) {
		printf("DYNAMITE: ~Renderer~ entity object has no surface!\n");
		return;
	}
	
	if (entity->GetComponent<Sprite>()->GetTexture() == nullptr) {
		printf("DYNAMITE: ~Renderer~ entity object has no texture!\n");
		return;
	}

	SDL_Rect rect;
	rect.h = entity->GetComponent<Sprite>()->GetSurface()->h;
	rect.w = entity->GetComponent<Sprite>()->GetSurface()->w;
	rect.x = entity->position.GetX() - activeCamera->GetXCoord();
	rect.y = entity->position.GetY() - activeCamera->GetYCoord();

	SDL_RendererFlip flip = SDL_FLIP_NONE;

	SDL_RenderCopyEx(sdlRenderer, entity->GetComponent<Sprite>()->GetTexture(),nullptr,&rect,0,NULL,flip);
}

void Renderer::Draw() {
	SDL_RenderPresent(sdlRenderer);
}