#include "github.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Github w;
  w.show();

  return a.exec();
}
