#include "uniqueList.h"
#include "excAddElement.h"
#include "excDeleteElement.h"

UniqueList::UniqueList() {}

void UniqueList::add(int value)
{
  if (find(value))
    throw ExcAddElement("This element already exists in list!");

  List::add(value);
}

void UniqueList::remove(int value)
{
  if (!find(value))
    throw ExcDeleteElement("This element doesn't exist in list!");
  List::remove(value);
}

int UniqueList::size()
{
  return List::size();
}
