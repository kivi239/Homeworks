#ifndef POINTERLIST_H
#define POINTERLIST_H
#include <cstdio>

template <typename T>
/// @class PointerList
/// @brief Contains implementation of pointer linked list with functionality.
class PointerList
{
public:
  PointerList();

	~PointerList();

	void addInPos(T value, int position);
	void addLast(T value) { addInPos(value, length + 1); }
	void addFirst(T value) { addInPos(value, 1); }

	int getLength() const { return length; }

  bool isEmpty() { return head == NULL; }
	bool isContained(T value) const;

	void removeValue(T value);

protected:
	/// @struct ListElement
	/// @brief Contains implementation of linked list.
	struct ListElement
	{
		T value;
		ListElement *next;

		ListElement(ListElement * nextElement, T x) :
			value(x),
			next(nextElement)
		{}
	};
  ListElement *head;
	int length;
};

template <typename T>
PointerList<T>::PointerList() : head(NULL), length(0) {}

template <typename T>
bool PointerList<T>::isContained(T value) const
{
  ListElement *temp = head;
  int counter = 0;
  printf("here\n");
  while (length > counter)
	{
		if (temp->value == value)
			return true;

		temp = temp->next;
		counter++;
	}

  return false;
}

template <typename T>
void PointerList<T>::addInPos(T value, int position)
{
	if (isEmpty())
	{
    head = new ListElement(NULL, value);
		length++;
		return;
	}

	if (position > length)
    position = length;

  if (position == 1)
  {
    ListElement *newElement = new ListElement(head, value);
    head = newElement;
  }
  else
  {
    ListElement *temp = head;
    for (int i = 0; i < position - 1; i++)
      temp = temp->next;
    ListElement *newElement = new ListElement(temp->next, value);
    temp->next = newElement;
  }
  length++;
}

template <typename T>
void PointerList<T>::removeValue(T value)
{
  if (head->value == value)
	{
    ListElement *deletedElement = head;
    head = head->next;
		delete deletedElement;
		length--;
		return;
	}

  ListElement *temp = head;

  while (temp->next != NULL && temp->next->value != value)
		temp = temp->next;
  if (temp->next == NULL)
    return;

	ListElement *deletedElement = temp->next;
	temp->next = temp->next->next;

	delete deletedElement;
}

template <typename T>
PointerList<T>::~PointerList()
{
  ListElement *temp = head;
  while (head != NULL)
	{
		temp = temp->next;
    delete head;
    head = temp;
	}
}

#endif // POINTERLIST_H
