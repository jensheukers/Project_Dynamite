/**
*	Filename: component.h
*
*	Description: Main header file for component.
*	Version: 0.1
*
*	© 2018, Jens Heukers
*/

#pragma once
#include <iostream>

class Component {
protected:
	const char* typeName;
public:
	/**
	* Constructor
	*/
	Component() { this->typeName = typeid(*this).name(); };

	/**
	* Returns the typename.
	*/
	const char* GetTypeName() { return this->typeName; };

	/**
	* Destructor
	*/
	virtual ~Component() {};
};