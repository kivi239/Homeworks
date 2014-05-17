#ifndef LISTONARRAY_H
#define LISTONARRAY_H

#pragma once
#include "list.h"

class ListOnArray : public List
{
public:
	ListOnArray();
	~ListOnArray();
	void printList();
	int length();
	void insert(int position, ListElement * newElement);
	void deleteElement(int position);
	void deleteList();
	const int MAX_LENGTH = 100;
	ListElement * mainArray;
	int currentLength;
};

#endif // LISTONARRAY_H
