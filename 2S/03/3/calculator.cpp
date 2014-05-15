#include "calculator.h"
#include "ui_calculator.h"
#include <QDebug>

Calculator::Calculator(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Calculator),
  size(4),
  calc(new CalculatorFunc()),
  wasEqual(false),
  wasOperation(false)
{
  ui->setupUi(this);

  generate();
}

QString digitToStr(int dig)
{
  QString answer = "";
  char c = char(dig) + '0';
  answer += c;
  return answer;
}

void Calculator::generateButton(QString text, int posX, int posY)
{
  QPushButton *button = new QPushButton;

  QFont font;
  int fieldSize = std::min(geometry().height(), geometry().width());
  font.setPixelSize(fieldSize * fieldSize / 3200);
  button->setFont(font);

  button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  button->setText(text);
  buttons[button] = text[0].toLatin1();

  ui->gridLayout->addWidget(button, posX, posY);

  connect(button, &QPushButton::clicked, this, &Calculator::buttonClicked);
}

void Calculator::generate()
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      generateButton(digitToStr(i * 3 + j + 1), i, j);

  QString operations[4] = {"+", "-", "*", "/"};
  for (int i = 0; i < 4; i++)
    generateButton(operations[i], i, 3);

  generateButton(".", 3, 0);
  generateButton("0", 3, 1);
  generateButton("=", 3, 2);
}

bool Calculator::isForNumber(QPushButton *button)
{
  QString text = QString(buttons[button]);
  return (text == "." || ('0' <= text[0].toLatin1() && text[0].toLatin1() <= '9'));
}

void Calculator::buttonClicked()
{
  QPushButton *button = dynamic_cast<QPushButton*>(sender());
  if (isForNumber(button))
  {
    if (wasEqual || wasOperation)
      ui->lineEdit->setText("");
    wasEqual = false;
    wasOperation = false;
    QString number = ui->lineEdit->displayText();
    number += buttons[button];
    ui->lineEdit->setText(number);
  }
  else
  {
    QString text = ui->lineEdit->displayText();
    int len = text.size();
    char *str = new char[len + 1];
    for (int i = 0; i < len; i++)
      str[i] = text[i].toLatin1();
    str[len] = '\n';

    double number = 0;
    sscanf(str, "%lf", &number);

    if (buttons[button] == '=')
    {
      wasEqual = true;
      wasOperation = false;
      ui->lineEdit->setText(calc->calc(number));
      delete[] str;
    }
    else
    {
      wasEqual = false;
      wasOperation = true;
      QString newText = QString(buttons[button]);
      delete calc;
      calc = new CalculatorFunc(number, newText);
      ui->lineEdit->setText(newText);
    }
  }
}

void Calculator::resizeEvent(QResizeEvent *event)
{
  QMainWindow::resizeEvent(event);
  int fieldSize = std::min(geometry().height(), geometry().width());
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
    {
      QFont font;
      font.setPixelSize(fieldSize * fieldSize / 3200);
      QPushButton *button = dynamic_cast<QPushButton *>(ui->gridLayout->itemAtPosition(i, j)->widget());
      button->setFont(font);
    }
}

Calculator::~Calculator()
{
  delete ui;
  delete calc;
}
