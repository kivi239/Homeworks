#include "github.h"
#include "ui_github.h"

Github::Github(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Github)
{
  ui->setupUi(this);
}

Github::~Github()
{
  delete ui;
}
