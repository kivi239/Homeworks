#include <cstdio>
#include <iostream>

using namespace std;

template<typename T>
///Class which is used to work with sets
class Set
{
public:
  Set();
  ~Set();
  void print();
  void add(T);
  bool find(T);
  void remove(T);
  ///Method which returns intersection of two sets
  Set intersec(Set &);
  ///Method which returns union of two sets
  Set un(Set &);
  int size();
  bool operator == (Set &);

private:
  struct SetElement
  {
    T value;
    SetElement *next;
    SetElement() {}
    SetElement(T _value, SetElement *_next) : value(_value), next(_next) {}
  };

  SetElement *head;
};

template<typename T>
Set<T>::Set() : head(new SetElement(T(), nullptr)) {}

template<typename T>
Set<T>::~Set()
{
  SetElement *curElement = head;
  while (curElement != nullptr)
  {
    SetElement *tmp = curElement->next;
    delete curElement;
    curElement = tmp;
  }
}

template<typename T>
void Set<T>::add(T value)
{
  SetElement *curElement = head;
  while (curElement->next != nullptr && curElement->next->value < value)
    curElement = curElement->next;

  if (curElement->next != nullptr && curElement->next->value == value)
    return;

  SetElement *newElement = new SetElement(value, curElement->next);
  curElement->next = newElement;
}

template<typename T>
void Set<T>::print()
{
  SetElement *curElement = head->next;
  while (curElement != nullptr)
  {
    cout << curElement->value << ' ' ;
    curElement = curElement->next;
  }
  cout << endl;
}

template<typename T>
bool Set<T>::find(T value)
{
  SetElement *curElement = head;
  while (curElement->next != nullptr && curElement->next->value < value)
    curElement = curElement->next;

  return (curElement->next != nullptr && curElement->next->value == value);
}

template<typename T>
void Set<T>::remove(T value)
{
  if (!this->find(value))
    return;

  SetElement *curElement = head;
  while (curElement->next != nullptr && curElement->next->value < value)
    curElement = curElement->next;

  SetElement *removeElement = curElement->next;
  curElement->next = curElement->next->next;
  delete removeElement;
}

template<typename T>
Set<T> Set<T>::intersec(Set<T> &set)
{
  Set<T> newSet;
  SetElement *firstElement = head->next;
  SetElement *secondElement = set.head->next;

  while (firstElement != nullptr && secondElement != nullptr)
  {
    if (firstElement->value == secondElement->value)
    {
      newSet.add(firstElement->value);
      firstElement = firstElement->next;
      secondElement = secondElement->next;
    }
    else if (firstElement->value > secondElement->value)
      secondElement = secondElement->next;
    else
      firstElement = firstElement->next;
  }

  return newSet;
}

template<typename T>
Set<T> Set<T>::un(Set<T> &set)
{
  Set<T> newSet;
  SetElement *firstElement = head->next;
  SetElement *secondElement = set.head->next;

  while (firstElement != nullptr)
  {
    newSet.add(firstElement->value);
    firstElement = firstElement->next;
  }
  while (secondElement != nullptr)
  {
    newSet.add(secondElement->value);
    secondElement = secondElement->next;
  }

  return newSet;
}

template <typename T>
int Set<T>::size()
{
  int result = 0;
  SetElement *curElement = head;
  while (curElement != nullptr)
  {
    curElement = curElement->next;
    result++;
  }

  return result - 1;
}

template <typename T>
bool Set<T>::operator == (Set &s)
{
  if (this->size() != s.size())
    return false;

  SetElement *element1 = head->next;
  SetElement *element2 = s.head->next;

  while (element1 != nullptr)
  {
    if (element1->value != element2->value)
      return false;
    element1 = element1->next;
    element2 = element2->next;
  }

  return true;
}
