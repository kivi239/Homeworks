#include <cstdio>
#include "tree.h"

using namespace Trees;

Node *createNode(char key, Node *left, Node *right)
{
  Node *newNode = new Node;
  newNode->key = key;
  newNode->left = left;
  newNode->right = right;
  return newNode;                                                                         
}

Node *buildHelper(FILE *archive)
{
  Node *left = NULL;
  Node *right = NULL;
  char nextChar = '\0';
  fread(&nextChar, sizeof(char), 1, archive);
  char key = nextChar;
  fread(&nextChar, sizeof(char), 1, archive);
  if (nextChar == '(')
    left = buildHelper(archive);                                                                      
  else                                                           
    for (int i = 0; i < 4; i++)
      fread(&nextChar, sizeof(char), 1, archive);

  fread(&nextChar, sizeof(char), 1, archive);
  if (nextChar == '(')
    right = buildHelper(archive);
  else
    for (int i = 0; i < 4; i++)
      fread(&nextChar, sizeof(char), 1, archive);
  
  fread(&nextChar, sizeof(char), 1, archive);
  
  return createNode(key, left, right);
}

Tree Trees::build(FILE *archive)
{
  Tree tree = {NULL};
  tree.root = buildHelper(archive);
  return tree;
}

void print(Node *curNode, FILE *archive, FILE *file)
{
  if (curNode->left == NULL && curNode->right == NULL)
  {
    fwrite(&curNode->key, sizeof(char), 1, file);                   
    return;
  }
  char nextChar = '\n';
  fread(&nextChar, sizeof(char), 1, archive);
  if (nextChar == '0')
    print(curNode->left, archive, file);
  else
    print(curNode->right, archive, file);
    
}

void Trees::printString(Tree &tree, FILE *archive, FILE *file)
{
  while (!feof(archive)) 
  {
    print(tree.root, archive, file);
    char nextChar = '\0';
    fread(&nextChar, sizeof(char), 1, archive);
  }
}

void remove(Node *curNode)
{
  if (curNode == NULL)
    return;
  remove(curNode->left);
  remove(curNode->right);
  delete curNode;
}

void Trees::remove(Tree &tree)
{
  ::remove(tree.root);
}
