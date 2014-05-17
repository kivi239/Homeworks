#include "listonarray.h"
#include <iostream>

ListOnArray::ListOnArray()
{
	this->mainArray = new ListElement[this->MAX_LENGTH];
	this->currentLength = 0;
}

ListOnArray::~ListOnArray()
{
	this->deleteList();
}

void ListOnArray::printList()
{
	for (int i = 0; i < this->currentLength; ++i)
	{
		this->mainArray[i].printElement();
		std::cout << "; ";
	}
}

int ListOnArray::length()
{
	return this->currentLength;
}

void ListOnArray::insert(int position, ListElement * newElement)
{
	if (this->currentLength == this->MAX_LENGTH)
	{
		std::cerr << "Error. The maximum of elements is " << this->MAX_LENGTH << "\n";
		this->deleteList();
		exit(0);
	}
	ListElement * newArray = new ListElement [this->MAX_LENGTH];

	for (int i = 0; i < position; ++i)
	{
		newArray[i].takeValue(this->mainArray[i].getValue());
	}
	newArray[position].takeValue(newElement->getValue());
	for (int i = position; i < this->currentLength; ++i)
	{
		newArray[i + 1].takeValue(this->mainArray[i].getValue());
	}
	this->currentLength++;

	for (int i = 0; i < this->currentLength; ++i)
	{
		this->mainArray[i].takeValue(newArray[i].getValue());
	}

	delete[] newArray;
}

void ListOnArray::deleteElement(int position)
{
	if (this->currentLength <= position)
	{
		std::cerr << "Error. There is no element with this index " << "\n";
		this->deleteList();
		exit(0);
	}
	ListElement * newArray = new ListElement[this->MAX_LENGTH];
	for (int i = 0; i < position; ++i)
	{
		newArray[i].takeValue(this->mainArray[i].getValue());
	}
	for (int i = position + 1; i < this->currentLength; ++i)
	{
		newArray[i - 1].takeValue(this->mainArray[i].getValue());
	}
	this->currentLength--;

	for (int i = 0; i < this->currentLength; ++i)
	{
		this->mainArray[i].takeValue(newArray[i].getValue());
	}

	delete[] newArray;
}

void ListOnArray::deleteList()
{
	delete[] this->mainArray;
	this->currentLength = 0;
}
