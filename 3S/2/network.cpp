#include "network.h"
#include <algorithm>
#include <ctime>
#include <sstream>

Network::Network(std::vector<int> infections, std::vector<double> probabilities,
                 bool **adjaency, Generator *generator) : generator(generator)
{
  srand(time(NULL));
  countOfComputers = probabilities.size();
  matrix = new bool*[countOfComputers];
  for (int i = 0; i < countOfComputers; i++)
    matrix[i] = new bool[countOfComputers];
  for (int i = 0; i < countOfComputers; i++)
    for (int j = 0; j < countOfComputers; j++)
      matrix[i][j] = adjaency[i][j];

  for (int i = 0; i < countOfComputers; i++)
  {
    Computer comp(probabilities[i]);
    computers.push_back(comp);
  }

  for (int i = 0; i < (int)infections.size(); i++)
    computers[infections[i]].setInfected(true);
}

Network::~Network()
{
  for (int i = 0; i < countOfComputers; i++)
    delete[] matrix[i];
  delete[] matrix;
  computers.clear();
  delete generator;
}

std::string intToStr(int num)
{
  std::stringstream stream;
  stream << num;
  std::string ans;
  stream >> ans;
  return ans;
}

std::string Network::status()
{
  std::string ans;
  int lastInfected = -1;
  for (int i = 0; i < countOfComputers; i++)
    if (computers[i].isInfected())
      lastInfected = i;
  for (int i = 0; i < lastInfected; i++)
    if (computers[i].isInfected())
      ans += intToStr(i + 1) + ", ";
  if (lastInfected != -1)
    ans += intToStr(lastInfected + 1);
  return ans;
}

bool Network::willBeInfected(int id)
{
  return generator->getRandom() <= computers[id].getProbability();
}

void Network::makeMove()
{
  std::vector<bool> newInfections;
  for (int i = 0; i < countOfComputers; i++)
    newInfections.push_back(computers[i].isInfected());
  for (int i = 0; i < countOfComputers; i++)
    if (computers[i].isInfected())
    for (int j = 0; j < countOfComputers; j++)
    {
      if (!matrix[i][j])
        continue;
      newInfections[j] = newInfections[j] || willBeInfected(j);
    }
  for (int i = 0; i < countOfComputers; i++)
    computers[i].setInfected(newInfections[i]);
}
