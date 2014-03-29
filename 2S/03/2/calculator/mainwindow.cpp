#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->value1, SIGNAL(valueChanged(int)), this, SLOT(answer()));
  connect(ui->value2, SIGNAL(valueChanged(int)), this, SLOT(answer()));
  connect(ui->operation, SIGNAL(currentTextChanged(QString)), this, SLOT(answer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::answer()
{
  int value1 = ui->value1->value();
  int value2 = ui->value2->value();
  char operation = ui->operation->currentText().toStdString()[0];

  Calculator calc;
  if (calc.calc(value1, value2, operation) == error)
    ui->lineEdit->setText("Error!");
  else
    ui->lineEdit->setText(QString::number(calc.calc(value1, value2, operation)));
}
