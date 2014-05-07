#include "ticTacToe.h"
#include "ticTacToeTest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  TicTacToeTest test;
  QTest::qExec(&test);

  QApplication a(argc, argv);
  TicTacToe w;
  w.show();

  return a.exec();
}
