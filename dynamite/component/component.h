#pragma once
#include <iostream>

class Component {
private:
	const char* typeName;
public:
	Component() { this->typeName = typeid(*this).name(); };
	const char* GetTypeName() { return this->typeName; };
	virtual ~Component() {};
};