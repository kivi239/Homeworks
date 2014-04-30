#include <QObject>
#include <QtTest/QtTest>
#include "list.h"
#include "excAddElement.h"
#include "excDeleteElement.h"

class ListTest : public QObject
{
  Q_OBJECT
public:
  explicit ListTest(QObject *parent = 0);

private slots:
  void addTest()
  {
    List l;
    l.add(2);
    QVERIFY(true);
    try
    {
      l.add(2);
    }
    catch (ExcAddElement &exc)
    {
      QVERIFY(exc.printMessage() == "This element already exists in list!");
    }
  }

  void deleteTest()
  {
    List l;
    l.add(2);
    try
    {
      l.remove(3);
    }
    catch (ExcDeleteElement &exc)
    {
      QVERIFY(exc.printMessage() == "This element doesn't exist in list!");
    }
  }

};

