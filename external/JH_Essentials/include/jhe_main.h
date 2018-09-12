/**
*	Filename: jhe_main.h
*
*	Description: Main header file for jh_essentials.
*	Version: 0.3.1
*
*	© 2018, Jens Heukers
*/

#pragma once
#include "math\math.h"
#include "types\array.h"

#ifndef JHE_MAIN_H
#define JHE_MAIN_H

#include "vector2\vector2.h"
#include "types\string.h"

class Jhe {
private:
	const float VERSION = 0.31F;
public:
	/**
	* Returns the current version build
	*/
	float GetVersion() { return this->VERSION; };
};

#endif // !JHE_MAIN_H