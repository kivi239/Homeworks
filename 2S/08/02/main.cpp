#include "bash.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Bash window;

  window.show();
  //qDebug() << w.getText(1);

  return a.exec();
}
