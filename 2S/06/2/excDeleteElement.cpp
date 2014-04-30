#include "excDeleteElement.h"
#include <iostream>

using namespace std;

ExcDeleteElement::ExcDeleteElement(string mess) : message(mess) {}

string ExcDeleteElement::printMessage()
{
  return message;
}
