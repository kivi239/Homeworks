#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include <QScrollArea>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QByteArray>
#include <QGridLayout>
#include <QImage>
#include <QPixmap>

namespace Ui {
class Github;
}

class Github : public QMainWindow
{
  Q_OBJECT

public:
  explicit Github(QWidget *parent = 0);
  ~Github();

private slots:
  void selectUserClicked();
  void selectUserFinished();
  void backToStartClicked();
  void backToReposClicked();
  void reposClicked(QListWidgetItem *repository);
  void reposFinished();
  void loadPicture();

private:
  void drawStart();
  void drawRepo();
  void drawCommits();

  Ui::Github *ui;

  QLabel *talker;

  QLineEdit *user;
  QPushButton *selectUser;
  QPushButton *backToStart;
  QPushButton *backToRepository;

  QLabel *userName;
  QLabel *userRepos;
  QListWidget *repositories;

  QScrollArea *commits;

  QNetworkAccessManager *manager;
  QByteArray contentRepos;
  QByteArray contentCommits;

  QPixmap *image;
};
