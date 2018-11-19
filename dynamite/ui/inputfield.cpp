/**
*	Filename: inputfield.cpp
*
*	Description: Source file for InputField class
*	Version: 19/11/2018
*
*	© 2018, www.jensheukers.nl
*/
#include "../resourcemanager.h"
#include "../scenemanager.h"
#include "../component/sprite.h"
#include "inputfield.h"
#include "text.h"

InputField::InputField(Text* text) {
	SceneManager::Instance()->GetActiveScene()->AddUIElement(this); // Instantly add InputField element to SceneManager
	this->text = text; // Set text to param
	this->text->ignoreParentScaling = true; // Ignore parent scaling
	this->AddChild(this->text); // Add text as child
}

void InputField::SetText(std::string textstr) {
	if (!this->HasComponent<Sprite>()) { // If there is no sprite component
		std::cout << "DYNAMITE: ~InputField~ Cant add text because Inputfield has no sprite component, please add it!" << std::endl; //Print error
		return; //Return
	}
	int boxWidth = this->GetComponent<Sprite>()->GetTexture()->textureData->width * this->GetScale().GetX(); // Get the width of the bg
	int lettersWidth = 0; // Width of the letters

	Text tempText(this->text->GetFont()); // Temporary text instance
	tempText.SetText(textstr); // Set the temporary text
	for (int i = 0; i < tempText.GetLenght(); i++) { // For every text character
		lettersWidth += tempText.GetCharacter(i)->width; // Add the size to letterswidth
	}

	if (lettersWidth <= boxWidth) { // Check if the letterwidth is less or equals boxwidth
		this->text->SetText(textstr); // If so set the text
		this->textWidth = lettersWidth; // Set the letter width
	}
}

void InputField::Append(std::string textstr) {
	if (!this->HasComponent<Sprite>()) { // If there is no sprite component
		std::cout << "DYNAMITE: ~InputField~ Cant append because Inputfield has no sprite component, please add it!" << std::endl; //Print error
		return; //Return
	}
	int boxWidth = this->GetComponent<Sprite>()->GetTexture()->textureData->width * this->GetScale().GetX(); // Get the width of the bg
	int lettersWidth = 0; // Width of the letters

	Text tempText(this->text->GetFont()); // Temporary text instance
	tempText.SetText(textstr); // Set the temporary text
	for (int i = 0; i < tempText.GetLenght(); i++) { // For every text character
		lettersWidth += tempText.GetCharacter(i)->width; // Add the size to letterswidth
	}

	if ((lettersWidth + this->textWidth) <= boxWidth) { // Check if the letterwidth  + textwidth is less or equals boxwidth
		this->text->Append(textstr); // If so append
		this->textWidth = lettersWidth + this->textWidth; // Set the width
	}
}