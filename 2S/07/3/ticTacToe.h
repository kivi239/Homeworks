#include <QMainWindow>
#include <QMap>
#include <QPushButton>
#include "ticTacToeFunc.h"

using namespace std;

namespace Ui {
class TicTacToe;
}

class TicTacToe : public QMainWindow
{
  Q_OBJECT

public:
  explicit TicTacToe(QWidget *parent = 0);
  ~TicTacToe();

private slots:
  void generate();
  void buttonClicked();

private:
  Ui::TicTacToe *ui;
  QMap<QPushButton *, pair<int, int> > pos;
  TicTacToeFunc tic;
};
