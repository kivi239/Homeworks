#include <cstdio>
#include "priority_queue.h"

using namespace PriorityQueues;

const int inf = (int)(1e9);

int max(int a, int b)
{
  if (a < b)
    return b;
  return a;
}

Node *createNode(int value, char key)
{
  Node *newNode = new Node;
  newNode->value = value;
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
                                                                                                          
  return newNode;                                                      
}

PriorityQueue PriorityQueues::create()
{
  Node *tailNode = createNode(inf, '?');
  Node *headNode = createNode(0, '?');
  Tree *tail = new Tree;
  tail->root = tailNode;
  tail->next = NULL;
  Tree *head = new Tree;
  head->root = headNode;
  head->next = NULL;
  PriorityQueue q = {head, tail};
       
  return q;
}

Node* pop(PriorityQueue &q)
{
  Tree *headTree = q.head->next->next;
  Node *delNode = q.head->next->root;
  delete q.head->next;
  q.head->next = headTree;
  return delNode;
}
  
void PriorityQueues::add(PriorityQueue &q, int value, char key)
{                                   
  Tree *curTree = q.head;
  while (curTree->next != NULL && curTree->next->root->value < value)
    curTree = curTree->next;

  Node *newNode = createNode(value, key);
  Tree *newTree = new Tree;
  newTree->root = newNode;
  newTree->next = curTree->next;
  curTree->next = newTree;
} 

void add(PriorityQueue &q, Tree *addedTree)
{                                   
  Tree *curTree = q.head;
  while (curTree->next != NULL && curTree->next->root->value < addedTree->root->value)
    curTree = curTree->next;

  addedTree->next = curTree->next;
  curTree->next = addedTree;
} 

void removeTree(Node *curNode)
{
  if (curNode->left != NULL)
    removeTree(curNode->left);
  if (curNode->right != NULL)
    removeTree(curNode->right);

  delete curNode;
}

void remove(Tree *curTree)
{
  if (curTree->next != NULL)
    ::remove(curTree->next);
  removeTree(curTree->root);
  delete curTree;                                                                                                               
}

void PriorityQueues::remove(PriorityQueue &q)
{
  ::remove(q.head);
}

int PriorityQueues::size(PriorityQueue &q)
{
  int answer = 0;
  Tree *curTree = q.head;
  while (curTree->next != NULL)
  {
    curTree = curTree->next;
    answer++;
  }

  return answer;
}

void PriorityQueues::merge(PriorityQueue &q)
{
  Node *leftNode = pop(q);
  Node *rightNode = pop(q);                                                                                                           

  Node *newNode = new Node;
  newNode->value = leftNode->value + rightNode->value;                                                                      
  newNode->left = leftNode;
  newNode->right = rightNode;                                                                                                  
  Tree *newTree = new Tree;
  newTree->root = newNode;                                              
  newTree->next = NULL;
  ::add(q, newTree);
}

void traversal(Node *curNode, long long *save, int code)
{                                                                                                                                     
  if (curNode->left == NULL && curNode->right == NULL)
    save[(int)curNode->key] = code;

  if (curNode->left != NULL)
    ::traversal(curNode->left, save, code * 3 + 1);
  if (curNode->right != NULL)
    ::traversal(curNode->right, save, code * 3 + 2);
}

void PriorityQueues::traversal(PriorityQueue &q, long long *save)
{
  ::traversal(q.head->next->root, save, 0);
}

void out(Node *curNode)
{
  if (curNode == NULL)
  {
    printf(" null");
    return;
  }

  printf("(");
  if (curNode->left == NULL && curNode->right == NULL)
    printf("%c", curNode->key);
  else
    printf("?");
  ::out(curNode->left);
  ::out(curNode->right);
  printf(")");    
}

void PriorityQueues::out(PriorityQueue &q)
{
  ::out(q.head->next->root);
}
