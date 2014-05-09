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
  firstDrawing = true;
  generate();

  connect(ui->pushButton, &QPushButton::clicked, this, &TicTacToe::generate);
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
  button->setText(getCell(x, y));
  button->setEnabled(false);
  tic.updateState();
  if (tic.isFinished())
  {
    int ok = QMessageBox::information(this, "it's over", result());
    if (ok == QMessageBox::Ok)
      qApp->quit();
  }

}

void TicTacToe::generate()
{
  if (!firstDrawing)
  {
    int newSize = ui->spinBox->value();
    for (int i = 0; i < tic.getSize(); i++)
      for (int j = 0; j < tic.getSize(); j++)
      {
        pos.remove(dynamic_cast<QPushButton*> (ui->gridLayout->itemAtPosition(i, j)->widget()));
        delete ui->gridLayout->itemAtPosition(i, j)->widget();
      }
    tic.changeSize(newSize);
  }

  for (int i = 0; i < tic.getSize(); i++)
    for (int j = 0; j < tic.getSize(); j++)
    {
      QPushButton *button = new QPushButton;
      button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      pos[button] = make_pair(i, j);
      updateButton(button);
      ui->gridLayout->addWidget(button, i, j);

      connect(button, &QPushButton::clicked, this, &TicTacToe::buttonClicked);
    }

  firstDrawing = false;
}

void TicTacToe::updateButton(QPushButton *button)
{
  int fieldSize = std::min(geometry().height(), geometry().width());

  QFont fontForButton;
  fontForButton.setPixelSize(fieldSize * fieldSize * 3 / (3000 * tic.getSize()));
  button->setFont(fontForButton);
  button->setText(getCell(pos[button].first, pos[button].second));
}

void TicTacToe::resizeEvent(QResizeEvent *event)
{
  QMainWindow::resizeEvent(event);
  for (int i = 0; i < tic.getSize(); i++)
    for (int j = 0; j < tic.getSize(); j++)
      updateButton(dynamic_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, j)->widget()));
}

QString TicTacToe::getCell(int x, int y)
{
  if (tic.getCell(x,y) == TicTacToeFunc::stateFree)
    return " ";
  else if (tic.getCell(x, y) == TicTacToeFunc::stateX)
    return "X";
  else
    return "O";
}

QString TicTacToe::result()
{
  if (tic.getState() == TicTacToeFunc::inProcess)
    return "   Draw!   ";
  if (tic.getState() == TicTacToeFunc::winX)
    return " X wins!!! ";
  return " O wins!!! ";
}
