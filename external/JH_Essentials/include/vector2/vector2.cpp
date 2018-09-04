/**
*	Filename: vector2.cpp
*
*	Description: Vector2 source file.
*	Version: 0.7
*
*	© 2018, Jens Heukers
*/
#include "vector2.h"


void Vector2::Set(float x, float y) {
	this->x = x;
	this->y = y;
}

void Vector2::Multiply(float amount) {
	this->x *= amount;
	this->y *= amount;
}

void Vector2::Divide(float amount) {
	this->x /= amount;
	this->y /= amount;
}

void Vector2::Add(float amount) {
	this->x += amount;
	this->y += amount;
}

bool Vector2::Equals(Vector2* other) {
	if (this->x == other->x && this->y == other->y) {
		return true;
	}
	return false;
}

float Vector2::Distance(Vector2* other) {
	return other->x - this->x + other->y + this->y;
}

float Vector2::Magnitude() {
	return Jhmath::Sqrt(this->x * this->x + this->y * this->y);
}

float Vector2::Angle() {
	return Jhmath::Atan2(this->y, this->x);
}

void Vector2::Lerp(Vector2* other, float amount) {
	this->x = (this->x + other->x) * amount;
	this->y = (this->y + other->y) * amount;
}
