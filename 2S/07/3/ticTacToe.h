#include <QMainWindow>
#include <QMap>
#include <QPushButton>
#include "ticTacToeFunc.h"

using namespace std;

namespace Ui {
class TicTacToe;
}

///Class for game tic-tac-toe
class TicTacToe : public QMainWindow
{
  Q_OBJECT

public:
  explicit TicTacToe(QWidget *parent = 0);
  ~TicTacToe();

private slots:
  ///Method which draws initial field
  void generate();
  void buttonClicked();

private:
  Ui::TicTacToe *ui;
  QMap<QPushButton *, pair<int, int> > pos;
  TicTacToeFunc tic;
  ///Method which set button's text's size correctly
  void updateButton(QPushButton *button);
  void resizeEvent(QResizeEvent *event);
};
