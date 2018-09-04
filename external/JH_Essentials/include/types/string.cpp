/**
*	Filename: string.cpp
*
*	Description: Source for string data type
*	Version: 0.6
*
*	© 2018, Jens Heukers
*/
#include "string.h"

String::String() {
	length = 0;
	data = new char['\0'];
}

String::String(const char* c) {
	int i = 0;
	while (c[i] != '\0') {
		i++;
	}

	length = i;
	data = new char[length];

	for (int ii = 0; ii < length; ii++) {
		data[ii] = c[ii];
	}
}

char* String::Get() {
	char* returnString = new char[length];

	for (int i = 0; i < length; i++) {
		returnString[i] = GetLetter(i);
	}

	returnString[length] = '\0';
	return returnString;
}

char String::GetLetter(unsigned index) {
	return data[index];
}

Array<String>* String::Split(const char* c) {
	Array<String>* returnArray = new Array<String>();

	unsigned i = 0;
	unsigned lastWordIndex = 0;
	bool finished = false;

	data[length + 1] = '\0';
	data[length] = c[0];

	while (!finished) {

		if (data[i] == '\0') {
			finished = true;
		}

		if (data[i] == c[0]) {
			char* word = new char[i - lastWordIndex];
			unsigned letterCount = 0;
			for (int ii = 0; ii < i - lastWordIndex; ii++) {
				if (data[lastWordIndex + ii] != c[0]) {
					word[letterCount] = data[lastWordIndex + ii];
					letterCount++;
				}
			}
			word[letterCount] = '\0';
			lastWordIndex = i;
			returnArray->Push(String(word));
		}
		i++;
	}

	return returnArray;
}

void String::Append(String* other) {
	char* appendedString = new char[this->length + other->length];
	appendedString[this->length + other->length] = '\0';


	for (int i = 0; i < this->length; i++) {
		appendedString[i] = this->GetChar()[i];
	}

	for (int i = this->length; i < this->length + other->length; i++) {
		appendedString[i] = other->GetChar()[i - this->length];
	}

	this->length = this->length + other->length;
	this->data = appendedString;
}
