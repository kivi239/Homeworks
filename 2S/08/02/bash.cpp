#include "bash.h"
#include "ui_bash.h"
#include <QGridLayout>
#include <QTextEdit>
#include <QLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QWebElement>
#include <QWebFrame>
#include <QWebPage>
#include <QFont>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

Bash::Bash(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Bash),
  id(0)
{
  view = new QWebView();
  view->load(QUrl("http://bash.im/"));
  connect(view, SIGNAL(loadFinished(bool)), this, SLOT(load()));

  ui->setupUi(this);

  QFont font;
  font.setPixelSize(19);
  bayanButton = new QPushButton;
  bayanButton->setFont(font);
  bayanButton->setText("[:|||:]");
  connect(bayanButton, &QPushButton::clicked, this, &Bash::bayanClicked);

  rulezButton = new QPushButton;
  rulezButton->setFont(font);
  rulezButton->setText("+");
  connect(rulezButton, &QPushButton::clicked, this, &Bash::rulezClicked);

  suxButton = new QPushButton;
  suxButton->setFont(font);
  suxButton->setText("-");
  connect(suxButton, &QPushButton::clicked, this, &Bash::suxClicked);

  nextButton = new QPushButton;
  nextButton->setFont(font);
  nextButton->setText("next");
  connect(nextButton, &QPushButton::clicked, this, &Bash::nextClicked);

  prevButton = new QPushButton;
  prevButton->setFont(font);
  prevButton->setText("previous");
  connect(prevButton, &QPushButton::clicked, this, &Bash::prevClicked);

  rating = new QLabel;
  rating->setFont(font);
  rating->setText("rating: ----");

  quote = new QTextEdit;
  quote->setFont(font);
  quote->setEnabled(false);
  generate(0);
  quote->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  makeDisabled();
  QGridLayout *buttons = new QGridLayout;
  buttons->addWidget(prevButton, 0, 0);
  buttons->addWidget(nextButton, 0, 1);
  buttons->addWidget(rating, 0, 2);
  buttons->addWidget(rulezButton, 1, 0);
  buttons->addWidget(bayanButton, 1, 1);
  buttons->addWidget(suxButton, 1, 2);

  ui->gridLayout->addLayout(buttons, 0, 0, 1, 1);
  ui->gridLayout->addWidget(quote);
}

void Bash::makeEnabled()
{
  prevButton->setEnabled(true);
  nextButton->setEnabled(true);
  rating->setEnabled(true);
  bayanButton->setEnabled(true);
  rulezButton->setEnabled(true);
  suxButton->setEnabled(true);
}

void Bash::makeDisabled()
{
  prevButton->setEnabled(false);
  nextButton->setEnabled(false);
  rating->setEnabled(false);
  bayanButton->setEnabled(false);
  rulezButton->setEnabled(false);
  suxButton->setEnabled(false);
}

void Bash::load()
{
  qDebug() << "load started\n";
  QWebElementCollection elements = view->page()->mainFrame()->findAllElements("div[class=quote]");

  int cnt = 0;
  foreach (QWebElement const &element, elements)
  {
    if (element.findFirst("div[class=text]").toPlainText() == "")
      continue;
    quotes[cnt] = element.findFirst("div[class=text]").toPlainText();
    ratings[cnt] = element.findFirst("span[class=rating-o]").toPlainText();
    rulezLinks[cnt] = element.findFirst("a[class=up]").attribute("href");
    suxLinks[cnt] = element.findFirst("a[class=down]").attribute("href");
    bayanLinks[cnt++] = element.findFirst("a[class=bayan]").attribute("href");

    if (cnt == size)
      break;
  }
  makeEnabled();
  generate(0);
}

void Bash::generate(int id)
{
  quote->setText(quotes[id]);
  rating->setText("rating: " + ratings[id]);
}


void Bash::prevClicked()
{
  id--;
  if (id < 0)
    id += size;
  generate(id);
}

void Bash::nextClicked()
{
  id++;
  id %= size;
  generate(id);
}

void Bash::rulezClicked()
{
  QNetworkAccessManager manager;
  manager.get(QNetworkRequest(QUrl("bash.im" + rulezLinks[id])));
}

void Bash::suxClicked()
{
  QNetworkAccessManager manager;
  manager.get(QNetworkRequest(QUrl("bash.im" + suxLinks[id])));
}

void Bash::bayanClicked()
{
  QNetworkAccessManager manager;
  manager.get(QNetworkRequest(QUrl("bash.im" + bayanLinks[id])));
}

Bash::~Bash()
{
  delete ui;
  delete view;
}

