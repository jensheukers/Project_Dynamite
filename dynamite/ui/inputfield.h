/**
*	Filename: inputfield.h
*
*	Description: Header file for InputField class, Use this class as a "Template" as the full functionality is mostly up to the user
*	Version: 19/11/2018
*
*	© 2018, www.jensheukers.nl
*/
#pragma once
#include "uielement.h"
#include "text.h"

class InputField : public UIElement {
private:
	Text* text; ///@ The text in the InputField
	int textWidth; /// @ The width of all the characters in the input field
public:
	/**
	* Constructor
	*/
	InputField(Text* text);

	/**
	* Set the Input field text
	*/
	void SetText(std::string text);
	
	/**
	* Append a character to the text
	*/
	void Append(std::string text);
};