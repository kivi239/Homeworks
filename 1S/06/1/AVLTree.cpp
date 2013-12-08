#include <cstdio>
#include "AVLTree.h"
#include <iostream>

using namespace AVLTrees;
using std::max;

int height(AVLTreeNode *curNode)
{
  if (curNode == NULL)
    return 0;

  return curNode->height;
}                                                                                                              

int balance(AVLTreeNode *curNode)
{
  if (curNode == NULL)
    return 0;
  return height(curNode->left) - height(curNode->right);
}

void update(AVLTreeNode *curNode)
{
  curNode->height = max(height(curNode->left), height(curNode->right)) + 1;
}

AVLTree AVLTrees::create()
{
  AVLTree newTree = {NULL};
  return newTree;
}

AVLTreeNode *leftSpin(AVLTreeNode *curNode)
{
  AVLTreeNode *nodeUp = curNode->right;
  curNode->right = nodeUp->left;
  nodeUp->left = curNode; 
  update(curNode);
  update(nodeUp);
  
  return nodeUp;
}

AVLTreeNode *rightSpin(AVLTreeNode *curNode)                                    
{
  AVLTreeNode *nodeUp = curNode->left;
  curNode->left = nodeUp->right;
  nodeUp->right = curNode;
  update(curNode);
  update(nodeUp);

  return nodeUp;
}

AVLTreeNode *find(AVLTreeNode *&curNode, int value)
{
  if (curNode == NULL)
    return NULL;

  if (curNode->value > value)
    return ::find(curNode->left, value);
  if (curNode->value < value)
    return ::find(curNode->right, value);

  return curNode;
}

bool AVLTrees::find(AVLTree &tree, int value)
{
  return (::find(tree.root, value) != NULL); 
}

void balanceNode(AVLTreeNode *&curNode)
{
  if (balance(curNode) == 2 && height(curNode->left->left) >= height(curNode->left->right))
    curNode = rightSpin(curNode);
  if (balance(curNode) == 2 && height(curNode->left->left) < height(curNode->left->right))
  {
    curNode->left = leftSpin(curNode->left);
    curNode = rightSpin(curNode);
  }
  if (balance(curNode) == -2 && height(curNode->right->left) <= height(curNode->right->right))
    curNode = leftSpin(curNode);
  if (balance(curNode) == -2 && height(curNode->right->left) > height(curNode->right->right))
  {
    curNode->right = rightSpin(curNode->right);
    curNode = leftSpin(curNode);
  }
}

void add(AVLTreeNode *&curNode, int value)
{
  if (curNode == NULL)
  {
    curNode = new AVLTreeNode;                                                            
    curNode->value = value;                                                                    
    curNode->height = 1;                                                       
    curNode->left = NULL;
    curNode->right = NULL;
    return;
  }
  if (curNode->value > value)
    ::add(curNode->left, value);
  else
    ::add(curNode->right, value);
  
  curNode->height = max(height(curNode->left), height(curNode->right)) + 1;
  balanceNode(curNode);
}
                                                             
bool AVLTrees::add(AVLTree &tree, int value)
{
  if (find(tree, value))
    return false;

  ::add(tree.root, value);
  return true;
}

AVLTreeNode *&mostLeft(AVLTreeNode *&curNode)
{
  if (curNode->left == NULL)
    return curNode;

  return mostLeft(curNode->left);
}

void remove(AVLTreeNode *&curNode, int value)
{
  if (curNode->value == value)
  {
    if (height(curNode) == 1)
    {
      delete curNode;
      curNode = NULL;
    }
    else if (curNode->right == NULL)
    {
      AVLTreeNode *left = curNode->left;
      delete curNode;
      curNode = left;
    }
    else if (curNode->left == NULL)
    {
      AVLTreeNode *right = curNode->right;
      delete curNode;
      curNode = right;
    }
    else
    {
      if (curNode->right == NULL)
      {
        AVLTreeNode *right = curNode->right;
        delete curNode;
        curNode = right;
      }
      else
      {
        AVLTreeNode *&newNode = mostLeft(curNode->right);
        AVLTreeNode *right = newNode->right;
        curNode->value = newNode->value;
        delete newNode;
        newNode = right;
      }
    }
    return;
  }
  if (curNode->value > value)
    ::remove(curNode->left, value);
  else
    ::remove(curNode->right, value);

  update(curNode);
  balanceNode(curNode);
}

bool AVLTrees::remove(AVLTree &tree, int value)
{
  if (!find(tree, value))
    return false;
  
  ::remove(tree.root, value);
  return true;
}

void deleteAll(AVLTreeNode *&curNode)        
{                                                                                         
  if (curNode == NULL)
    return;

  deleteAll(curNode->left);
  deleteAll(curNode->right);

  delete curNode;
}

void AVLTrees::deleteAll(AVLTree &tree)
{
  ::deleteAll(tree.root);
}            
                             
void printAscending(AVLTreeNode *curNode)
{
  if (curNode == NULL)
    return;

  printAscending(curNode->left);
  printf("%d ", curNode->value);
  printAscending(curNode->right);
}

void AVLTrees::printAscending(AVLTree &tree)
{
  ::printAscending(tree.root);
  printf("\n");
}

void printDescending(AVLTreeNode *curNode)
{                      
  if (curNode == NULL)
    return;

  printDescending(curNode->right);
  printf("%d ", curNode->value);
  printDescending(curNode->left);
}

void AVLTrees::printDescending(AVLTree &tree)
{                               
  ::printDescending(tree.root);
  printf("\n");
}

void printTree(AVLTreeNode *curNode)
{
  if (curNode == NULL)
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
                                                                                                                                  
void AVLTrees::printTree(AVLTree &tree)
{
  ::printTree(tree.root);
  printf("\n");
}
                                                    