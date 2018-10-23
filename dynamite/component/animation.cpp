/**
*	Filename: animation.cpp
*
*	Description: Source file for animation class.
*
*	Version: 22/10/2018
*
*	© 2018, Jens Heukers
*/


#include "animation.h"

Animation::Animation(float frameTime) {
	this->frameTime = frameTime;
	this->currentFrame = 0;
}

void Animation::AddFrame(std::string path) {
	frames.push_back(path);
}

void Animation::RemoveFrame(int index) {
	frames.erase(frames.begin() + index);
}

std::string Animation::NextFrame() {
	currentFrame++;

	if (currentFrame > frames.size() - 1) {
		currentFrame = 0;
	}

	return frames[currentFrame];
}

std::string Animation::PreviousFrame() {
	currentFrame--;

	if (currentFrame < 0) {
		currentFrame = frames.size() - 1;
	}

	return frames[currentFrame];
}

std::string Animation::GetFrame(int index) {
	currentFrame = index;
	return frames[index];
}

std::string Animation::GetCurrent() {
	return frames[currentFrame];
}

float Animation::GetFrameTime() {
	return this->frameTime;
}

void Animation::SetFrameTime(float frameTime) {
	this->frameTime = frameTime;
}

void Animation::Reset() {
	currentFrame = 0;
}