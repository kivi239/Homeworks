#include "excAddElement.h"
#include <iostream>

using namespace std;

ExcAddElement::ExcAddElement(string mess) : message(mess) {}

string ExcAddElement::printMessage()
{
  return message;
}
