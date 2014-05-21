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
    QString s = "(+ 1 2)";
    ExprTree tree(s);
    QVERIFY(tree.result() == 3);
    QVERIFY(tree.print() == "( + 1 2 )");
  }

  void someTest()
  {
    QString s = "(+ 1 (* 2 4))";
    ExprTree tree(s);
    QVERIFY(tree.result() == 9);
    QVERIFY(tree.print() == "( + 1 ( * 2 4 ) )");
  }

};
