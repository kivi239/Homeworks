#include "uniqueList.h"
#include "excAddElement.h"
#include "excDeleteElement.h"

UniqueList::UniqueList() {}

void UniqueList::add(int value)
{
  if (findInList(value))
    throw ExcAddElement("This element already exists in list!");

  addToList(value);
}

void UniqueList::remove(int value)
{
  if (!findInList(value))
    throw ExcDeleteElement("This element doesn't exist in list!");
  removeFromList(value);
}

int UniqueList::size()
{
  return sizeOfList();
}
