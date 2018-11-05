/**
*	Filename: uielement.cpp
*
*	Description: Source file for User Interface Element class
*	Version: 2/11/2018
*
*	© 2018, Jens Heukers
*/


#include "uielement.h"
#include "../scenemanager.h"
#include "../component/sprite.h"
#include "../component/collider.h"
#include "../event/input.h"
#include "../physics/physics.h"

UIElement::UIElement() {
	this->AddComponent<Collider>(); // Add a collider component

	if (SceneManager::Instance()->GetActiveScene()) { // If there is a active scene
		SceneManager::Instance()->GetActiveScene()->AddUIElement(this); // Add this to active scene
	}
}

UIElement::UIElement(Vector2 position) {
	this->position = position; //Set position to position parameter

	this->AddComponent<Collider>(); // Add a collider component

	if (SceneManager::Instance()->GetActiveScene()) { // If there is a active scene
		SceneManager::Instance()->GetActiveScene()->AddUIElement(this); // Add this to active scene
	}
}

UIElement::UIElement(Vector2 position, std::string path) {
	this->position = position; //Set position to position parameter

	this->AddComponent<Sprite>()->SetTexture(path); // Add a sprite component and set the texture
	this->AddComponent<Collider>()->SetBounds(Vector2((float)this->GetComponent<Sprite>()->GetTexture()->textureData->width,  // Add a collider component, and set bounds
													  (float)this->GetComponent<Sprite>()->GetTexture()->textureData->height)); 

	if (SceneManager::Instance()->GetActiveScene()) { // If there is a active scene
		SceneManager::Instance()->GetActiveScene()->AddUIElement(this); // Add this to active scene
	}
}

void UIElement::SetTexture(std::string path) {
	if (!this->HasComponent<Sprite>()) { // if there is no sprite component
		this->AddComponent<Sprite>(); // add a sprite component
	}

	this->GetComponent<Sprite>()->SetTexture(path); // Set the texture
	this->GetComponent<Collider>()->SetBounds(Vector2((float)this->GetComponent<Sprite>()->GetTexture()->textureData->width,
		(float)this->GetComponent<Sprite>()->GetTexture()->textureData->height)); // set the collider component bounds to texture
}

void UIElement::Update() {
	if (Physics::InRangePoint(Input::Instance()->GetMousePositionRelativeToScreen(), this->GetComponent<Collider>())) { // Check if mouse is in range of UI object

		this->OnHover(); // Call OnHover() Method

		if (Input::Instance()->ButtonPressed(1)) { //If clicked
			this->OnClick(1); //Call OnClick() Method
		}

		if (Input::Instance()->ButtonPressed(2)) { //If clicked
			this->OnClick(2); //Call OnClick() Method
		}

		if (Input::Instance()->ButtonPressed(3)) { //If clicked
			this->OnClick(3); //Call OnClick() Method
		}

		if (!entered) { //if not yet entered
			OnEnter(); //Call OnEnter() Method
			entered = true;
		}
	}
	else {
		if (entered) { //If entered
			OnLeave(); //Call OnLeave() Method
			entered = false;
		}
	}
}