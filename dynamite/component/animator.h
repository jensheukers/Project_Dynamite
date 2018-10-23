#pragma once
#include "component.h"
#include "animation.h"

enum AnimationState { Play, Pause };

class Animator : public Component {
private:
	Animation* currentAnimation;
	AnimationState animationState;
	float timeStamp;
public:
	Animator();
	void Update() override;
	void SetCurrentAnimation(Animation* animation);
	void SetCurrentAnimationState(AnimationState state);
};