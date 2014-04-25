#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "arrayStack.h"
#include "pointerStack.h"

class StackTest : public QObject
{
  Q_OBJECT
public:
  explicit StackTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void pushTest()
  {
    Stack *s = new ArrayStack();
    s->push(2);
    QVERIFY(s->top() == 2);
    s->push(3);
    QVERIFY(s->top() == 3);
    delete s;
  }

  void popTest()
  {
    Stack *s = new PointerStack();
    QVERIFY(s->top() == (int)'!');
    s->push(2);
    QVERIFY(s->pop() == 2);
    QVERIFY(s->top() == (int)'!');
    delete s;
  }
};
