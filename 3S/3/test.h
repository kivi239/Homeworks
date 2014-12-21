#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include <vector>
#include "graph.h"
#include <QDebug>

class Test : public QObject
{
  Q_OBJECT
public:
  explicit Test(QObject *parent = 0);

private slots:

  void emptyGraph()
  {
    std::vector<std::vector<int> > g;
    std::vector<int> emptyVector;
    for (int i = 0; i < 5; i++)
      g.push_back(emptyVector);
    std::vector<bool> pos;
    for (int i = 0; i < 5; i++)
      pos.push_back(false);
    Graph graph(5, g, pos);
    QVERIFY(graph.canDestroy());
  }

  void twoRobots()
  {
    std::vector<std::vector<int> > g;
    std::vector<int> emptyVector;
    for (int i = 0; i < 5; i++)
      g.push_back(emptyVector);
    g[0].push_back(1);
    g[1].push_back(0);
    g[1].push_back(2);
    g[2].push_back(1);
    std::vector<bool> pos;
    for (int i = 0; i < 5; i++)
      pos.push_back(false);
    pos[0] = true;
    pos[2] = true;
    Graph graph(5, g, pos);
    QVERIFY(graph.canDestroy());
  }

  void threeRobots()
  {
    std::vector<std::vector<int> > g;
    std::vector<int> emptyVector;
    for (int i = 0; i < 5; i++)
      g.push_back(emptyVector);
    g[0].push_back(1);
    g[1].push_back(0);
    g[1].push_back(2);
    g[2].push_back(1);
    g[2].push_back(3);
    g[3].push_back(4);
    g[4].push_back(3);

    std::vector<bool> pos;
    for (int i = 0; i < 5; i++)
      pos.push_back(false);
    pos[0] = true;
    pos[2] = true;
    pos[4] = true;
    Graph graph(5, g, pos);
    QVERIFY(graph.canDestroy());
  }

  void neighborRobots()
  {
    std::vector<std::vector<int> > g;
    std::vector<int> emptyVector;
    for (int i = 0; i < 5; i++)
      g.push_back(emptyVector);
    g[0].push_back(1);
    g[1].push_back(0);
    g[1].push_back(2);
    g[2].push_back(1);
    std::vector<bool> pos;
    for (int i = 0; i < 5; i++)
      pos.push_back(false);
    pos[0] = true;
    pos[1] = true;
    Graph graph(5, g, pos);
    QVERIFY(!graph.canDestroy());
  }



};

