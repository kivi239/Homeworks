#include "github.h"
#include "ui_github.h"
#include <QFont>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMessageBox>
#include <QGridLayout>
#include <QImage>
#include <QPixmap>
#include <QTableWidget>
#include <QLayout>

Github::Github(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Github)
{
  ui->setupUi(this);

  drawStart();
}

void Github::drawStart()
{
  QFont font;
  font.setPixelSize(20);

  talker = new QLabel;
  talker->setFont(font);
  talker->setText("Please, enter user name:");

  font.setPixelSize(16);
  user = new QLineEdit;
  user->setFont(font);

  selectUser = new QPushButton;
  selectUser->setText("Select user");
  selectUser->setFont(font);
  connect(selectUser, &QPushButton::clicked, this, &Github::selectUserClicked);

  font.setPixelSize(400);
  QLabel *empty = new QLabel;
  empty->setFont(font);
  empty->setText(" ");

  ui->gridLayout->addWidget(talker, 0, 0);
  ui->gridLayout->addWidget(user, 1, 0);
  ui->gridLayout->addWidget(selectUser, 1, 1);
  ui->gridLayout->addWidget(empty, 2, 0);

  manager = new QNetworkAccessManager;
}

void Github::selectUserClicked()
{
  QString name = user->text();
  QNetworkReply *reply = manager->get(QNetworkRequest(QUrl("https://api.github.com/users/" + name + "/repos")));
  userName = new QLabel;
  userName->setText("User: " + name);

  user->setEnabled(false);
  selectUser->setEnabled(false);
  connect(reply, &QNetworkReply::finished, this, &Github::selectUserFinished);
}

void Github::drawRepo()
{
  QFont font;
  font.setPixelSize(16);

  backToStart = new QPushButton;
  backToStart->setFont(font);
  backToStart->setText("Back");
  connect(backToStart, &QPushButton::clicked, this, &Github::backToStartClicked);

  talker = new QLabel;
  font.setPixelSize(20);
  talker->setFont(font);
  talker->setText("Please, select repository:");


  repositories = new QListWidget;
  font.setPixelSize(16);
  repositories->setFont(font);

  QJsonDocument doc = QJsonDocument::fromJson(contentRepos);
  for (auto json : doc.array())
  {
    QString repoName = json.toObject()["name"].toString();
    repositories->addItem(repoName);
  }
  connect(repositories, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(reposClicked(QListWidgetItem *)));

  userName->setFont(font);

  ui->gridLayout->addWidget(backToStart, 0, 0);
  ui->gridLayout->addWidget(userName, 1, 0);
  ui->gridLayout->addWidget(talker, 2, 0);
  ui->gridLayout->addWidget(repositories, 3, 0);
}

void Github::selectUserFinished()
{
  QNetworkReply *reply = dynamic_cast<QNetworkReply *>(sender());

  if (user->text() == "")
  {
    QMessageBox::warning(this, tr("Empty name"), tr("Name should not be empty"));
    user->setText("");
    user->setEnabled(true);
    selectUser->setEnabled(true);
    reply->deleteLater();
    return;
  }

  if (reply->error() != QNetworkReply::NoError)
  {
    QMessageBox::warning(this, tr("Error"), tr("User with this name does not exist"));
    user->setText("");
    user->setEnabled(true);
    selectUser->setEnabled(true);
    reply->deleteLater();
    return;
  }
  contentRepos = reply->readAll();

  delete user;
  delete selectUser;
  delete talker;
  delete ui->gridLayout->itemAtPosition(2, 0)->widget();

  drawRepo();

  reply->deleteLater();
}

void Github::backToStartClicked()
{
  delete backToStart;
  delete talker;
  delete repositories;
  delete userName;

  drawStart();
}

void Github::reposClicked(QListWidgetItem *repository)
{
  userRepos = new QLabel;
  userRepos->setText("Repository: " + repository->text());

  QNetworkReply *reply = manager->get(QNetworkRequest(QUrl("https://api.github.com/repos/" + userName->text().mid(6) + "/" + repository->text() + "/commits")));
  backToStart->setEnabled(false);
  repositories->setEnabled(false);

  connect(reply, &QNetworkReply::finished, this, &Github::reposFinished);
}

void Github::reposFinished()
{
  QNetworkReply *reply = dynamic_cast<QNetworkReply *>(sender());
  contentCommits = reply->readAll();

  delete repositories;
  delete backToStart;
  delete talker;

  drawCommits();

  reply->deleteLater();
}

void Github::drawCommits()
{
  QFont font;
  font.setPixelSize(16);

  backToRepository = new QPushButton;
  backToRepository->setFont(font);
  backToRepository->setText("back");
  connect(backToRepository, &QPushButton::clicked, this, &Github::backToReposClicked);

  userRepos->setFont(font);

  commits = new QScrollArea;
  commits->setWidgetResizable(true);
  QWidget *w = new QWidget(this);
  w->setLayout(new QVBoxLayout(w));
  commits->setWidget(w);

  QJsonDocument doc = QJsonDocument::fromJson(contentCommits);
  int cnt = 0;
  for (auto json : doc.array())
  {
    QString name = json.toObject()["commit"].toObject()["author"].toObject()["name"].toString();
    QString sha = json.toObject()["sha"].toString();
    QString date = json.toObject()["commit"].toObject()["author"].toObject()["date"].toString();
    QString comment = json.toObject()["commit"].toObject()["message"].toString();

    QString imageAddress = json.toObject()["author"].toObject()["avatar_url"].toString();

    QLabel *nameLabel = new QLabel("Author: " + name);
    nameLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QLabel *shaLabel = new QLabel("Hash: " + sha);
    shaLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QLabel *dateLabel = new QLabel("Date: " + date);
    dateLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QLabel *commentLabel = new QLabel("Comment: " + comment);
    commentLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *commit = new QWidget;

    QPixmap image;
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(imageAddress)));
    connect(reply, &QNetworkReply::finished, this, &Github::loadPicture);
    loaderImage[reply] = commit;

    QLayout *lay = new QGridLayout;
    commit->setLayout(lay);

    commit->layout()->addWidget(nameLabel);
    commit->layout()->addWidget(shaLabel);
    commit->layout()->addWidget(dateLabel);
    commit->layout()->addWidget(commentLabel);

    w->layout()->addWidget(commit);
    cnt++;
  }

  ui->gridLayout->addWidget(backToRepository, 0, 0);
  ui->gridLayout->addWidget(userRepos, 2, 0);
  ui->gridLayout->addWidget(commits, 3, 0);
}

void Github::backToReposClicked()
{
  delete backToRepository;
  delete userRepos;
  delete commits;

  drawRepo();
}

void Github::loadPicture()
{
  QNetworkReply *reply = dynamic_cast<QNetworkReply *>(sender());
  QByteArray content = reply->readAll();
  QPixmap image;
  image.loadFromData(content);
  QWidget *commit = loaderImage[reply];
  QLabel *imageLabel = new QLabel;
  imageLabel->setPixmap(image);
  commit->layout()->addWidget(imageLabel);
}

Github::~Github()
{
  delete ui;
}
