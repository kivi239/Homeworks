#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "exprTree.h"

class ExprTreeTest : public QObject
{
  Q_OBJECT
public:
  ExprTreeTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void minTest()
  {
    char s[10] = "(+ 1 2)";
    ExprTree tree(s, strlen(s));
    QVERIFY(tree.result() == 3);
    QVERIFY(tree.print() == "( + 1 2 )");
  }

  void someTest()
  {
    char s[100] = "(+ 1 (* 2 4))";
    ExprTree tree(s, strlen(s));
    QVERIFY(tree.result() == 9);
    QVERIFY(tree.print() == "( + 1 ( * 2 4 ) )");
  }

};
