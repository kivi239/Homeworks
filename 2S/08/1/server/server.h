#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QtNetwork>
#include <QTextEdit>
#include <QLineEdit>

class Server : public QDialog
{
  Q_OBJECT

public:
  Server(QWidget *parent = 0);

private slots:
  void sessionOpened();
  void sendMessage();
  void acceptConnection();
  void readMessage();
  void disconnection();

private:
  QLabel *statusLabel;
  QPushButton *quitButton;
  QPushButton *sendButton;
  QTcpServer *tcpServer;
  QTcpSocket *clientSocket;
  QNetworkSession *networkSession;
  QTextEdit *chat;
  QLineEdit *message;
  quint16 blockSize;
  
};
