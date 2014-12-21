#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "network.h"
#include "randomgenerator.h"
#include "notrandomgenerator.h"

class Test : public QObject
{
  Q_OBJECT
public:
  explicit Test(QObject *parent = 0);

private slots:
  void noInfections()
  {
    std::vector<int> infections;
    bool **matrix = new bool*[1];
    matrix[0] = new bool[1];
    matrix[0][0] = false;
    std::vector<double> probs;
    probs.push_back(0.5);
    Generator *generator = new RandomGenerator();
    Network network(infections, probs, matrix, generator);

    delete[] matrix[0];
    delete[] matrix;
    QVERIFY(network.status() == "");
    network.makeMove();
    QVERIFY(network.status() == "");
  }

  void allInfected()
  {
    std::vector<int> infections;
    infections.push_back(0);
    bool **matrix = new bool*[3];
    for (int i = 0; i < 3; i++)
      matrix[i] = new bool[3];
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        matrix[i][j] = false;
    matrix[0][1] = true;
    matrix[1][2] = true;
    std::vector<double> probs;
    probs.push_back(1);
    probs.push_back(1);
    probs.push_back(1);
    Generator *generator = new RandomGenerator();
    Network network(infections, probs, matrix, generator);
    network.makeMove();
    network.makeMove();
    QVERIFY(network.status() == "1, 2, 3");
    for (int i = 0; i < 3; i++)
      delete[] matrix[i];
    delete[] matrix;
  }

  void canBeInfected()
  {
    std::vector<int> infections;
    infections.push_back(0);
    bool **matrix = new bool*[3];
    for (int i = 0; i < 3; i++)
      matrix[i] = new bool[3];
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        matrix[i][j] = false;
    matrix[0][1] = true;
    matrix[0][2] = true;
    std::vector<double> probs;
    probs.push_back(0.5);
    probs.push_back(0.8);
    probs.push_back(0.5);
    Generator *generator = new NotRandomGenerator();

    Network network(infections, probs, matrix, generator);
    network.makeMove();
    QVERIFY(network.status() == "1, 2");
    for (int i = 0; i < 3; i++)
      delete[] matrix[i];
    delete[] matrix;
  }

};

