/**
*	Filename: animator.cpp
*
*	Description: Source file for Animator class.
*
*	Version: 23/10/2018
*
*	© 2018, Jens Heukers
*/

#include "animator.h"
#include "../core.h"

Animator::Animator() {
	this->currentAnimation = nullptr;
	this->animationState = AnimationState::Play;
	timeStamp = (float)Core::Instance()->GetTimeElapsed();
}

void Animator::Update() {
	if (!currentAnimation || animationState == AnimationState::Pause || !parent->HasComponent<Sprite>()) {
		return;
	}

	if (Core::Instance()->GetTimeElapsed() > timeStamp + currentAnimation->GetFrameTime()) {
		timeStamp = (float)Core::Instance()->GetTimeElapsed();

		parent->GetComponent<Sprite>()->SetTexture(currentAnimation->NextFrame());
	}
}

void Animator::SetCurrentAnimation(Animation* animation) {
	this->currentAnimation = animation;
}

void Animator::SetCurrentAnimationState(AnimationState state) {
	this->animationState = state;
}