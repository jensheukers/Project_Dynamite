/**
*	Filename: animator.h
*
*	Description: Header file for Animator class.
*
*	Version: 23/10/2018
*
*	© 2018, Jens Heukers
*/


#pragma once
#include "component.h"
#include "animation.h"

enum AnimationState { Play, Pause };

class Animator : public Component {
private:
	/// @brief The current playing animation
	Animation* currentAnimation;

	/// @brief The current animation State
	AnimationState animationState;

	/// @brief the timestamp from the last update
	float timeStamp;

public:
	Animator();
	void Update() override;
	void SetCurrentAnimation(Animation* animation);
	void SetCurrentAnimationState(AnimationState state);
};