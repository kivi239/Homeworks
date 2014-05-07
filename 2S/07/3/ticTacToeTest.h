#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "ticTacToeFunc.h"

class TicTacToeTest : public QObject
{
  Q_OBJECT
public:
  explicit TicTacToeTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void startTest()
  {
    TicTacToeFunc tic;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        QVERIFY(tic.getCell(i, j) == " ");
  }

  void moveTest()
  {
    TicTacToeFunc tic;
    tic.makeMove(1, 1);
    tic.makeMove(0, 1);
    QVERIFY(tic.getCell(1, 1) == "X");
    QVERIFY(tic.getCell(0, 1) == "O");
  }

  void winTest()
  {
    TicTacToeFunc tic;
    tic.makeMove(1, 1);
    tic.makeMove(0, 1);
    tic.makeMove(1, 0);
    tic.makeMove(0, 0);
    tic.makeMove(1, 2);
    QVERIFY(tic.result() == " X wins!!! ");
  }

  void winTest2()
  {
    TicTacToeFunc tic;
    tic.makeMove(1, 1);
    tic.makeMove(0, 1);
    tic.makeMove(0, 2);
    tic.makeMove(1, 2);
    tic.makeMove(2, 0);
    QVERIFY(tic.result() == " X wins!!! ");
  }
};
