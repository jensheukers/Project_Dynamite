/**
*	Filename: math.h
*
*	Description: Math class for jh_essentials, containing basic math functionality, extending upon cmath.
*	Version: 0.5
*
*	© 2018, Jens Heukers
*/
#pragma once
#include <cmath>

class Jhmath {
public:

	//Basic mathmetic methods

	/**
	* Returns the value of Pi
	*/
	static float Pi() { return (float)3.14159265359; };

	/**
	* Multiply's the given number with the amount
	*/
	static float Multiply(float number, float amount) { return number *= amount; };

	/**
	* Devides's the given number with the amount
	*/
	static float Devide(float number, float amount) { return number /= amount; };

	/**
	* Adds's the amount to the number
	*/
	static float Add(float number, float amount) { return number += amount; };

	/**
	* Removes's the amount from the number
	*/
	static float Remove(float number, float amount) { return number -= amount; };

	/**
	* Returns outcome of sqrt method
	*/
	static float Sqrt(float number) { return sqrt(number); };

	/**
	* Returns outcome of atan method
	*/
	static float Atan(float number) { return atan(number); };

	/**
	* Returns outcome of atan2 method
	*/
	static float Atan2(float i, float ii) { return atan2(i,ii); };

	//More complex mathmetic methods

	/**
	* Clamps the given number between the 2 amounts
	*/
	static float Clamp(float number, float min, float max);

	/**
	* Transfers radians to degrees
	*/
	static float Rad2Deg(float radians);

	/**
	* Transfers degrees to radians
	*/
	static float Deg2Rad(float degrees);

	/**
	* Returns the highest of 2 floating points
	*/
	static float Highest(float i, float ii);

	/**
	* Returns the highest of 2 floating points
	*/
	static float Lowest(float i, float ii);


	/**
	* Returns a random number between min and max
	*/
	static int Random(int min, int max); 
};
