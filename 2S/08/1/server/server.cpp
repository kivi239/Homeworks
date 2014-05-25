#include <QtWidgets>
#include <QtNetwork>
#include <stdlib.h>
#include "server.h"
#include <QString>

Server::Server(QWidget *parent) : QDialog(parent), tcpServer(0), clientSocket(0), networkSession(0), blockSize(0)
{
  statusLabel = new QLabel;
  
  quitButton = new QPushButton(tr("Quit"));
  quitButton->setAutoDefault(false);

  sendButton = new QPushButton(tr("Send"));

  chat = new QTextEdit;
  chat->setReadOnly(true);

  message = new QLineEdit;

  QNetworkConfigurationManager manager;
  if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) 
  {
    // Get saved network configuration
    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
    settings.endGroup();

    // If the saved network configuration is not currently discovered use the system default
    QNetworkConfiguration config = manager.configurationFromIdentifier(id);
    if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered) 
      config = manager.defaultConfiguration();
    
    networkSession = new QNetworkSession(config, this);
    connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

    statusLabel->setText(tr("Opening network session."));
    networkSession->open();
  } 
  else 
    sessionOpened();

  connect(sendButton, &QPushButton::clicked, this, &Server::sendMessage);
  connect(quitButton, &QPushButton::clicked, this, &Server::close);
  connect(tcpServer, &QTcpServer::newConnection, this, &Server::acceptConnection);

  QHBoxLayout *buttonLayout = new QHBoxLayout;
  buttonLayout->addStretch(1);
  buttonLayout->addWidget(quitButton);
  buttonLayout->addStretch(1);
  buttonLayout->addWidget(sendButton);
  buttonLayout->addStretch(1);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(statusLabel);
  mainLayout->addLayout(buttonLayout);
  mainLayout->addWidget(chat);
  mainLayout->addWidget(message);
  setLayout(mainLayout);

  setWindowTitle(tr("Chat Server"));
}

void Server::sessionOpened()
{
  // Save the used configuration
  if (networkSession) {
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
      id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
      id = config.identifier();

    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();
  }

  tcpServer = new QTcpServer(this);
  if (!tcpServer->listen()) {
    QMessageBox::critical(this, tr("Chat Server"),
                          tr("Unable to start the server: %1.")
                          .arg(tcpServer->errorString()));
    close();
    return;
  }

  statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                          "Run the Chat Client example now.")
                       .arg(tcpServer->serverAddress().toString()).arg(tcpServer->serverPort()));
}

void Server::acceptConnection()
{
  clientSocket = tcpServer->nextPendingConnection();
  sendButton->setEnabled(true);

  connect(clientSocket, &QTcpSocket::readyRead, this, &Server::readMessage);
  connect(clientSocket, &QTcpSocket::disconnected, this, &Server::disconnection);
  connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
}

void Server::readMessage()
{
  QDataStream from(clientSocket);
  from.setVersion(QDataStream::Qt_5_2);

  if (blockSize == 0)
  {
    if (clientSocket->bytesAvailable() < (int)sizeof(quint16))
      return;

    from >> blockSize;
  }

  if (clientSocket->bytesAvailable() < blockSize)
    return;

  blockSize = 0;
  QString newMessage;
  from >> newMessage;
  chat->textCursor().insertText("Client: " + newMessage + "\n");
}

void Server::sendMessage()
{
  if (clientSocket)
  {
    sendButton->setEnabled(false);
    QByteArray block;
    QDataStream to(&block, QIODevice::WriteOnly);

    to << (quint16)message->text().length();
    to << message->text();
    clientSocket->write(block);

    chat->textCursor().insertText("Server: " + message->text() + "\n");
    message->clear();

    sendButton->setEnabled(true);
  }
}

void Server::disconnection()
{
  QMessageBox::warning(this, tr("Chat Server"), tr("Disconnetion!"));
  sendButton->setEnabled(false);
}

