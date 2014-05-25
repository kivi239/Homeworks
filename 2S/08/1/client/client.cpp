#include <QtWidgets>
#include <QtNetwork>
#include "client.h"

Client::Client(QWidget *parent) : QWidget(parent), network(0), blockSize(0)
{
  hostLabel = new QLabel(tr("Server name IP-address:"));
  portLabel = new QLabel(tr("Server port:"));
  
  hostAddress = new QComboBox;
  hostAddress->setEditable(true);
  
  portLineEdit = new QLineEdit(this);
  portLineEdit->setValidator(new QIntValidator(1, 65535, this));

  chat = new QTextEdit;
  chat->setReadOnly(true);

  message = new QLineEdit;

  statusLabel = new QLabel;

  sendButton = new QPushButton(tr("Send!"));
  sendButton->setEnabled(false);

  quitButton = new QPushButton(tr("Quit"));

  connectButton = new QPushButton(tr("Connect!"));

  QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
  for (int i = 0; i < ipAddressesList.size(); ++i) 
    hostAddress->addItem(ipAddressesList.at(i).toString());

  serverSocket = new QTcpSocket;

  connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
  connect(sendButton, &QPushButton::clicked, this, &Client::sendMessage);
  connect(connectButton, &QPushButton::clicked, this, &Client::connectToServer);

  connect(serverSocket, &QTcpSocket::readyRead, this, &Client::readMessage);
  connect(serverSocket, &QTcpSocket::disconnected, this, &Client::disconnectFromServer);
  connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
  QHBoxLayout *messageLayout = new QHBoxLayout;
  messageLayout->addWidget(message);
  messageLayout->addWidget(sendButton);

  QHBoxLayout *buttonLayout = new QHBoxLayout;
  buttonLayout->addStretch(1);
  buttonLayout->addWidget(connectButton);
  buttonLayout->addStretch(1);
  buttonLayout->addWidget(quitButton);
  buttonLayout->addStretch(1);

  QGridLayout *connectLayout = new QGridLayout;
  connectLayout->addWidget(hostLabel, 0, 0);
  connectLayout->addWidget(hostAddress, 0, 1);
  connectLayout->addWidget(portLabel, 1, 0);
  connectLayout->addWidget(portLineEdit, 1, 1);
  connectLayout->addWidget(statusLabel, 2, 0, 1, 2);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addLayout(connectLayout);
  mainLayout->addWidget(chat);
  mainLayout->addLayout(messageLayout);
  mainLayout->addLayout(buttonLayout);
  setLayout(mainLayout);

  portLineEdit->setFocus();
  QNetworkConfigurationManager manager;
  if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
  {
    QSettings settings(QSettings::UserScope, QLatin1String("qtproject"));
    settings.beginGroup(QLatin1String("qtnetwork"));
    const QString id = settings.value(QLatin1String("defaultnetworkconfiguration")).toString();
    settings.endGroup();

    QNetworkConfiguration config = manager.configurationFromIdentifier(id);
    if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered)
      config = manager.defaultConfiguration();

    network = new QNetworkSession(config, this);
    connect(network, &QNetworkSession::opened, this, &Client::sessionOpened);

    statusLabel->setText(tr("Opening network session."));
    network->open();
  }
}

void Client::sessionOpened()
{
  QNetworkConfiguration config = network->configuration();
  QString id;
  if (config.type() == QNetworkConfiguration::UserChoice)
    id = network->sessionProperty(QLatin1String("User")).toString();
  else
    id = config.identifier();

  QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
  settings.beginGroup(QLatin1String("QtNetwork"));
  settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
  settings.endGroup();

  statusLabel = new QLabel(tr("This app requires tha you run the Chat server as well."));
  sendButton->setEnabled(true);
}

void Client::sendMessage()
{
  sendButton->setEnabled(false);
  QByteArray block;
  QDataStream to(&block, QIODevice::WriteOnly);

  to << (quint16)message->text().length();
  to << message->text();
  serverSocket->write(block);

  chat->textCursor().insertText("You: " + message->text() + "\n");
  message->clear();
  sendButton->setEnabled(true);
}

void Client::readMessage()
{
  QDataStream from(serverSocket);
  from.setVersion(QDataStream::Qt_5_2);

  if (blockSize == 0)
  {
    if (serverSocket->bytesAvailable() < (int)sizeof(quint16))
      return;

    from >> blockSize;
  }

  if (serverSocket->bytesAvailable() < blockSize)
    return;

  blockSize = 0;
  QString newMessage;
  from >> newMessage;
  chat->textCursor().insertText("Server: " + newMessage + "\n");
}

void Client::displayError(QAbstractSocket::SocketError error)
{
  serverSocket->close();
  switch (error) {
  case QAbstractSocket::HostNotFoundError:
    QMessageBox::information(this, tr("Chat Client"),
                               tr("The host was not found. Please check the "
                                  "host and port settings."));
    break;
  case QAbstractSocket::ConnectionRefusedError:
    QMessageBox::information(this, tr("Chat Client"),
                               tr("The connection was refused by the peer. "
                                  "Make sure the fortune server is running, "
                                  "and check that the host name and port "
                                  "settings are correct."));
    break;
  default:
    QMessageBox::information(this, tr("Chat Client"),
                             tr("The following error occurred: %1.")
                             .arg(serverSocket->errorString()));
  }

  portLineEdit->setEnabled(true);
  hostAddress->setEnabled(true);
}

void Client::connectToServer()
{
  serverSocket->connectToHost(hostAddress->currentText(), portLineEdit->text().toInt());

  if (serverSocket->waitForConnected(3000))
  {
    chat->clear();
    chat->textCursor().insertText("Server connected!\n");
    sendButton->setEnabled(true);
    connectButton->setDisabled(true);
    hostAddress->setDisabled(true);
    portLineEdit->setDisabled(true);
  }
  else
  {
    hostAddress->setEnabled(true);
    portLineEdit->setEnabled(true);
  }
}

void Client::disconnectFromServer()
{
  sendButton->setEnabled(true);
  connectButton->setDisabled(true);
  hostAddress->setDisabled(true);
  portLineEdit->setDisabled(true);

  QMessageBox::warning(this, tr("Chat client"), tr("Disconnection!"));
}
