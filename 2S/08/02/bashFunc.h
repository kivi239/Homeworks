#pragma once

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QtWebKit/QWebElement>
#include <QWebFrame>
#include <QWebPage>
#include <QWebView>
#include <QDomDocument>
#include <QString>

class BashFunc
{
public:
  BashFunc()
  {
  }

  ~BashFunc();

public slots:
  void processReply(bool ok)
  {
    QWebElementCollection elements = view->page()->mainFrame()->findAllElements("div[class=quote]");

    int cnt = 0;
    foreach (QWebElement const &element, elements)
    {
      quotes[cnt++] = element;
      QWebElement tmp = element.findFirst("a[class=up]");
      qDebug() << tmp.attribute("href");
      if (cnt == 10)
        break;
    }
  }

private:
  QWebView *view;
  QWebElement quotes[size];
};
