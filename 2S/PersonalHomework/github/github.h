#ifndef GITHUB_H
#define GITHUB_H

#include <QMainWindow>

namespace Ui {
class Github;
}

class Github : public QMainWindow
{
  Q_OBJECT

public:
  explicit Github(QWidget *parent = 0);
  ~Github();

private:
  Ui::Github *ui;
};

#endif // GITHUB_H
