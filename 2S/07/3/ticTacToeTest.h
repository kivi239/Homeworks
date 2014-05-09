#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "ticTacToeFunc.h"
#include <cstdio>

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
        QVERIFY(tic.getCell(i, j) == TicTacToeFunc::stateFree);
  }

  void moveTest()
  {
    TicTacToeFunc tic;
    tic.makeMove(1, 1);
    tic.makeMove(0, 1);
    //qDebug() << (int)tic.getCell(1, 1) << ' ' << (int)tic.getCell(0, 1) ;
    printf("%d %d\n", (int)tic.getCell(1, 1), (int)tic.getCell(0, 1));
    QVERIFY(tic.getCell(1, 1) == TicTacToeFunc::stateX);
    QVERIFY(tic.getCell(0, 1) == TicTacToeFunc::stateO);
  }

  void winTest()
  {
    TicTacToeFunc tic;
    tic.makeMove(1, 1);
    tic.makeMove(0, 1);
    tic.makeMove(1, 0);
    tic.makeMove(0, 0);
    tic.makeMove(1, 2);
    QVERIFY(tic.getState() == TicTacToeFunc::winX);
  }

  void winTest2()
  {
    TicTacToeFunc tic;
    tic.makeMove(1, 1);
    tic.makeMove(0, 1);
    tic.makeMove(0, 2);
    tic.makeMove(1, 2);
    tic.makeMove(2, 0);
    QVERIFY(tic.getState() == TicTacToeFunc::winX);
  }
};
