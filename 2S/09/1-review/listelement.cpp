#include "listelement.h"
#include <iostream>

ListElement::ListElement(int value)
{
    this->takeValue(value);
}

ListElement::ListElement()
{
    this->takeValue(0);
}

int ListElement::getValue()
{
    return this->value;
}

void ListElement::takeValue(int value)
{
    this->value = value;
}

void ListElement::printElement()
{
    std::cout << this->value;
}
