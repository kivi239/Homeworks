#include <cstdio>
#include "bag.h"
#include <iostream>

using std::max;

Bag::Bag() : root(nullptr) {}

void Bag::deleteAll(AVLTreeNode *&curNode)
{
  if (curNode == nullptr)
    return;

  deleteAll(curNode->left);
  deleteAll(curNode->right);

  delete curNode;
}

Bag::~Bag()
{
  this->deleteAll(root);
}

int Bag::height(AVLTreeNode *curNode)
{
  if (curNode == nullptr)
    return 0;

  return curNode->height;
}

int Bag::balance(AVLTreeNode *curNode)
{
  if (curNode == nullptr)
    return 0;
  return this->height(curNode->left) - this->height(curNode->right);
}

void Bag::update(AVLTreeNode *curNode)
{
  curNode->height = max(this->height(curNode->left), this->height(curNode->right)) + 1;
}

Bag::AVLTreeNode *Bag::leftSpin(AVLTreeNode *curNode)
{
  AVLTreeNode *nodeUp = curNode->right;
  curNode->right = nodeUp->left;
  nodeUp->left = curNode;
  this->update(curNode);
  this->update(nodeUp);

  return nodeUp;
}

Bag::AVLTreeNode *Bag::rightSpin(AVLTreeNode *curNode)
{
  AVLTreeNode *nodeUp = curNode->left;
  curNode->left = nodeUp->right;
  nodeUp->right = curNode;
  this->update(curNode);
  this->update(nodeUp);

  return nodeUp;
}

Bag::AVLTreeNode *Bag::find(AVLTreeNode *&curNode, int value)
{
  if (curNode == nullptr)
    return nullptr;

  if (curNode->value > value)
    return this->find(curNode->left, value);
  if (curNode->value < value)
    return this->find(curNode->right, value);

  return curNode;
}

bool Bag::find(int value)
{
  return (this->find(root, value) != nullptr);
}

void Bag::balanceNode(AVLTreeNode *&curNode)
{
  if (this->balance(curNode) == 2 && this->height(curNode->left->left) >= this->height(curNode->left->right))
    curNode = this->rightSpin(curNode);
  if (this->balance(curNode) == 2 && this->height(curNode->left->left) < this->height(curNode->left->right))
  {
    curNode->left = this->leftSpin(curNode->left);
    curNode = this->rightSpin(curNode);
  }
  if (this->balance(curNode) == -2 && this->height(curNode->right->left) <= this->height(curNode->right->right))
    curNode = this->leftSpin(curNode);
  if (this->balance(curNode) == -2 && this->height(curNode->right->left) > this->height(curNode->right->right))
  {
    curNode->right = this->rightSpin(curNode->right);
    curNode = this->leftSpin(curNode);
  }
}

void Bag::add(AVLTreeNode *&curNode, int value)
{
  if (curNode == nullptr)
  {
    curNode = new AVLTreeNode(value, 1, 1, nullptr, nullptr);
    return;
  }
  if (curNode->value == value)
  {
    curNode->amount++;
    return;
  }
  if (curNode->value > value)
    this->add(curNode->left, value);
  else
    this->add(curNode->right, value);

  curNode->height = max(this->height(curNode->left), this->height(curNode->right)) + 1;
  balanceNode(curNode);
}

bool Bag::add(int value)
{
  bool isFind = !this->find(value);
  this->add(root, value);
  return isFind;
}

Bag::AVLTreeNode *&Bag::mostLeft(AVLTreeNode *&curNode)
{
  if (curNode->left == nullptr)
    return curNode;

  return this->mostLeft(curNode->left);
}

void Bag::remove(AVLTreeNode *&curNode, int value)
{
  if (curNode->value == value)
  {
    if (this->height(curNode) == 1)
    {
      delete curNode;
      curNode = nullptr;
    }
    else if (curNode->right == nullptr)
    {
      AVLTreeNode *left = curNode->left;
      delete curNode;
      curNode = left;
    }
    else if (curNode->left == nullptr)
    {
      AVLTreeNode *right = curNode->right;
      delete curNode;
      curNode = right;
    }
    else
    {
      if (curNode->right == nullptr)
      {
        AVLTreeNode *right = curNode->right;
        delete curNode;
        curNode = right;
      }
      else
      {
        AVLTreeNode *&newNode = this->mostLeft(curNode->right);
        AVLTreeNode *right = newNode->right;
        curNode->value = newNode->value;
        delete newNode;
        newNode = right;
      }
    }
    return;
  }
  if (curNode->value > value)
    this->remove(curNode->left, value);
  else
    this->remove(curNode->right, value);

  this->update(curNode);
  this->balanceNode(curNode);
}

bool Bag::remove(int value)
{
  if (!find(value))
    return false;

  this->remove(root, value);
  return true;
}

void Bag::printAscending(AVLTreeNode *curNode)
{
  if (curNode == nullptr)
    return;

  printAscending(curNode->left);
  printf("%d ", curNode->value);
  printAscending(curNode->right);
}

void Bag::printAscending()
{
  this->printAscending(root);
  printf("\n");
}

void Bag::printDescending(AVLTreeNode *curNode)
{
  if (curNode == nullptr)
    return;

  printDescending(curNode->right);
  printf("%d ", curNode->value);
  printDescending(curNode->left);
}

void Bag::printDescending()
{
  this->printDescending(root);
  printf("\n");
}

void Bag::printTree(AVLTreeNode *curNode)
{
  if (curNode == nullptr)
  {
    printf("null");
    return;
  }
  printf("(%d ", curNode->value);
  printTree(curNode->left);
  printf(" ");
  printTree(curNode->right);
  printf(") ");
}

void Bag::printTree()
{
  this->printTree(root);
  printf("\n");
}

