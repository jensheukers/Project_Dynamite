/**
*	Filename: vector2.h
*
*	Description: Vector2 Class header.
*	Version: 0.7
*
*	© 2018, Jens Heukers
*/
#pragma once
#include "../math/math.h"


class Vector2 {
private:
	float x;
	float y;
public:
	/**
	* Default constructor
	*/
	Vector2() { this->x = 0; this->y = 0; };

	/**
	* Constructor
	*/
	Vector2(float x, float y) { this->x = x; this->y = y; };


	/**
	* Returns x value
	*/
	float GetX() { return this->x; };

	/**
	* Returns y value
	*/
	float GetY() { return this->y; };

	/**
	* Returns new vector for given direction
	*/
	static Vector2 Up() { return Vector2(0, 1); };
	static Vector2 Down() { return Vector2(0, -1); };
	static Vector2 Right() { return Vector2(1, 0); };
	static Vector2 Left() { return Vector2(-1, 0); };

	/**
	* Returns the vector
	*/
	Vector2 Copy() { return *this; };

	//Setters

	/**
	* Sets the vector
	*/
	void Set(float x, float y);

	/**
	* Multiply both x and y with the amount
	*/
	void Multiply(float amount);

	/**
	* Divide both x and y with the amount
	*/
	void Divide(float amount);

	/**
	* Add the amount to both x and y
	*/
	void Add(float amount);


	//Other methods

	/**
	* Returns true if vector matches given vector
	*/
	bool Equals(Vector2* other);

	/**
	* Returns the distance to other vector
	*/
	float Distance(Vector2* other);

	/*
	* Returns the magnitude
	*/
	float Magnitude();
		
	/**
	* Returns the angle
	*/
	float Angle();

	/**
	* Linearly interpolates between this vector and other by amount.
	*/
	void Lerp(Vector2* other, float amount);
};