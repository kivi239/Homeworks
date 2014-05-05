#include <cstdio>
#include "bag.h"
#include <iostream>

using std::max;

Bag::Bag() {}
Bag::~Bag() {}

bool Bag::find(int value)
{
  return AVLTree::find(root, value);
}

bool Bag::add(int value)
{
  bool isFind = find(value);
  AVLTree::add(root, value);
  return isFind;
}

bool Bag::remove(int value)
{
  if (!find(value))
    return false;

  AVLTree::remove(root, value);
  return true;
}

void Bag::printAscending()
{
  AVLTree::printAscending(root);
  printf("\n");
}

void Bag::printDescending()
{
  AVLTree::printDescending(root);
  printf("\n");
}

void Bag::printTree()
{
  AVLTree::printTree(root);
  printf("\n");
}

