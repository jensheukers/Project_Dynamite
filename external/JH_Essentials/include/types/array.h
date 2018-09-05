/**
*	Filename: array.h
*
*	Description: Header for array data type
*	Version: 0.5
*
*	© 2018, Jens Heukers
*/

#pragma once
#include <stdexcept>

template<typename Type>
class Array {
private:
	unsigned size;
	Type* elements;
public:
	/**
	* Constructor
	*/
	Array() {
		size = 0;
		elements = new Type[size];
	}

	/**
	* Returns the size of the array
	*/
	unsigned Size() { return this->size; };

	/**
	* Adds a new entry to the array
	*/
	void Push(Type element) {
		size++;
		Type* newArray = new Type[size];
		
		for (int i = 0; i < size - 1; i++) {
			newArray[i] = elements[i];
		}

		newArray[size - 1] = element;
		elements = newArray;
	};

	/**
	* Removes a entry from the array
	*/
	void Remove(unsigned index) {
		size--;
		Type* newArray = new Type[size];

		unsigned count = 0;
		for (int i = 0; i < size + 1; i++) {
			if (i != index) {
				newArray[count] = elements[i];
				count++;
			}
		}

		elements = newArray;
	};

	/**
	* Returns element with the index given as parameter
	*/
	Type Get(unsigned index) {
		if (index > this->size) {
			throw std::out_of_range("Index out of range");
		}
		else {
			return elements[index];
		}
	}
};