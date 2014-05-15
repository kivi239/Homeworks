#include <QPushButton>
#include <QMap>
#include <QMainWindow>
#include "calculatorFunc.h"

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
  Q_OBJECT

public:
  explicit Calculator(QWidget *parent = 0);
  ~Calculator();

private slots:
  ///Method which create buttons
  void generate();
  void buttonClicked();

private:
  Ui::Calculator *ui;
  QMap<QPushButton *, char> buttons;
  void generateButton(QString text, int posX, int posY);
  void resizeEvent(QResizeEvent *event);
  ///Const for 4
  const int size;
  ///Method which returns true if button's text == "." or any digit
  bool isForNumber(QPushButton *button);
  CalculatorFunc *calc;
  ///Field which shows that previous clicked button was "="
  bool wasEqual;
  ///Field which showa that previous clicked was "+", "-", "*" or "/"
  bool wasOperation;
};
