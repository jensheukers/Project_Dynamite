/**
*	Filename: math.cpp
*
*	Description: Math class source file.
*
*	© 2018, Jens Heukers
*/

#include "math.h"

float Jhmath::Clamp(float number, float min, float max) {
	if (number > min && number < max) {
		return number;
	}

	if (number < min) {
		return min;
	}

	if (number > max) {
		return max;
	}
}

float Jhmath::Rad2Deg(float radians) {
	return 360 - (radians * Jhmath::Pi()) * 180;
}

float Jhmath::Deg2Rad(float degrees) {
	return degrees * Jhmath::Pi() / 180;
}

float Jhmath::Highest(float i, float ii) {
	if (i > ii) {
		return i;
	}

	if (i < ii) {
		return ii;
	}

	return i;
}

float Jhmath::Lowest(float i, float ii) {
	if (i < ii) {
		return i;
	}

	if (i > ii) {
		return ii;
	}

	return i;
}

int Jhmath::Random(int min, int max) {
	return rand() % max + min;
}
