/**
*	Filename: animation.h
*
*	Description: Header file for animation class.
*
*	Version: 22/10/2018
*
*	© 2018, Jens Heukers
*/

#pragma once
#include <iostream>
#include <vector>

class Animation {
private:
	/** The frames vector*/
	std::vector<std::string> frames;

	/** The time between the frames*/
	float frameTime;

	/** The current frame*/
	unsigned currentFrame;
public:

	/**
	* Constructor
	*/
	Animation(float frameTime);

	/**
	* Adds a new frame to the frames vector
	*/
	void AddFrame(std::string path);

	/**
	* Removes a frame from the frames vector where index matches
	*/
	void RemoveFrame(int index);

	/**
	* Returns the next frame from currentFrame
	*/
	std::string NextFrame();

	/**
	* Returns the previous frame from currentFrame
	*/
	std::string PreviousFrame();

	/**
	* Returns the frame at index in the frames vector
	*/
	std::string GetFrame(int index);

	/**
	* Returns the frame where index equals currentFrame
	*/
	std::string GetCurrent();

	/**
	* Returns the frametime
	*/
	float GetFrameTime();

	/**
	* Sets the frametime
	*/
	void SetFrameTime(float frameTime);

	/**
	* Resets currentFrame to 0
	*/
	void Reset();
};