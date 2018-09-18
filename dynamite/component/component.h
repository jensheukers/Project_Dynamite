/**
*	Filename: component.h
*
*	Description: Main header file for component.
*
*	© 2018, Jens Heukers
*/

#pragma once
#include <iostream>
#include "../imgui/imgui.h"
#include "vector2\vector2.h"

//Forward declarations
class Core;
class Entity;

class Component {
protected:
	const char* typeName;
	Entity* parent;
public:
	/**
	* Constructor
	*/
	Component();

	/**
	* Returns the typename.
	*/
	const char* GetTypeName() { return this->typeName; };

	/**
	* Settings that are displayed in the editor.
	*/
	virtual void EditorSettings();


	/**
	* Sets the parent Entity
	*/
	void Start(Core* core, Entity* parent);

	/**
	* Start gets called right as component is added to Entity.
	*/
	virtual void Start(Core* core) {};

	/**
	* Update gets called every frame by the Entity containing it.
	*/
	virtual void Update(Core* core) {};

	/**
	* Destructor
	*/
	virtual ~Component() {};
};