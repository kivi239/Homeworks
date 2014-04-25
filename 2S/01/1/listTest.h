#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "doubly_linked_list.h"
#include "singly_linked_list.h"

class ListTest : public QObject
{
  Q_OBJECT
public:
  explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void addTest()
  {
    List *l = new SinglyLinkedList();
    l->add(2);
    l->add(10);
    l->add(2);
    QVERIFY(l->size() == 3);

    delete l;
    l = new DoublyLinkedList();
    l->add(5);
    l->add(3);
    QVERIFY(l->size() == 2);
    delete l;
  }

  void removeTest()
  {
    List *l = new SinglyLinkedList();
    l->add(5);
    l->add(2);
    l->remove(2);
    QVERIFY(l->size() == 1);
    l->remove(5);
    QVERIFY(l->size() == 0);
  }

};
