/**
*	Filename: text.cpp
*
*	Description: Source file for Text class
*	Version: 3/11/2018
*
*	© 2018, Jens Heukers
*/
#include "text.h"
#include "../component/collider.h"

Text::Text(std::string text, Vector2 position, Font* font) {
	this->_text = text;
	this->position = position;
	this->_font = font;
	this->GetComponent<Collider>()->SetBounds(Vector2(_text.length() * _font->GetCharSize().GetX(), _font->GetCharSize().GetY()));
}

Font* Text::GetFont() {
	return this->_font;
}

void Text::SetColor(int b, int g, int r)
{
	_font->SetColor(b,g,r);
}

void Text::SetText(std::string text)
{
	this->_text = text;
	this->GetComponent<Collider>()->SetBounds(Vector2(_text.length() * _font->GetCharSize().GetX(), _font->GetCharSize().GetY()));
}

int Text::GetLenght() {
	return _text.length();
}

char Text::GetChar(int index) {
	return _text.at(index);
}