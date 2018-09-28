/**
*	Filename: component.h
*
*	Description: Main header file for component.
*
*	© 2018, Jens Heukers
*/

#pragma once
#include <iostream>
#include <vector>
#include "../imgui/imgui.h"
#include "../math/vector2.h"

//Forward declarations
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
	* OnLoad will be called when a Scene is beign loaded, a data array is given containing all contents that can be set
	* for said component.
	*/
	virtual void OnLoad(const char* data);

	/**
	* OnSave is beign called when a Scene is to be saved, you have to return a string with the data to be saved
	* for said component.
	*/
	virtual const char* OnSave();

	/**
	* Settings that are displayed in the editor.
	*/
	virtual void EditorSettings();


	/**
	* Sets the parent Entity
	*/
	void Start(Entity* parent);

	/**
	* Start gets called right as component is added to Entity.
	*/
	virtual void Start() {};

	/**
	* Update gets called every frame by the Entity containing it.
	*/
	virtual void Update() {};

	/**
	* Creates a new instance and returns a pointer to it
	*/
	virtual Component* Copy();

	/**
	* Destructor
	*/
	virtual ~Component() {};
};