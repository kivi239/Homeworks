#include <QMessageBox>
#include "ticTacToe.h"
#include "ui_ticTacToe.h"

TicTacToe::TicTacToe(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::TicTacToe)
{
  ui->setupUi(this);
  generate();
}

TicTacToe::~TicTacToe()
{
  delete ui;
}

void TicTacToe::buttonClicked()
{
  if (tic.isFinished())
    return;
  QPushButton *button = dynamic_cast<QPushButton *> (sender());
  int x = pos[button].first;
  int y = pos[button].second;
  tic.makeMove(x, y);
  button->setText(tic.getCell(x, y));
  button->setEnabled(false);
  tic.updateState();
  if (tic.isFinished())
    QMessageBox::information(this, "it's over", tic.result());
}

void TicTacToe::generate()
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      QPushButton *button = new QPushButton;
      button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      button->setText(" ");
      ui->gridLayout->addWidget(button, i, j);
      pos[button] = make_pair(i, j);

      connect(button, &QPushButton::clicked, this, &TicTacToe::buttonClicked);
    }
}
