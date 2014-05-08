#include <QMessageBox>
#include "ticTacToe.h"
#include "ui_ticTacToe.h"
#include <algorithm>
#include <QDebug>

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
  {
    int ok = QMessageBox::information(this, "it's over", tic.result());
    if (ok == QMessageBox::Ok)
      qApp->quit();
  }
}

void TicTacToe::generate()
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      QPushButton *button = new QPushButton;
      button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      pos[button] = make_pair(i, j);
      updateButton(button);
      ui->gridLayout->addWidget(button, i, j);

      connect(button, &QPushButton::clicked, this, &TicTacToe::buttonClicked);
    }
}

void TicTacToe::updateButton(QPushButton *button)
{
  int fieldSize = std::min(geometry().height(), geometry().width());

  QFont fontForButton;
  fontForButton.setPixelSize(fieldSize * fieldSize/ 2400);
  button->setFont(fontForButton);
  button->setText(tic.getCell(pos[button].first, pos[button].second));
}

void TicTacToe::resizeEvent(QResizeEvent *event)
{
  QMainWindow::resizeEvent(event);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      updateButton(dynamic_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, j)->widget()));
}
