#include "network.h"
#include <algorithm>
#include <ctime>

Network::Network(std::vector<int> infections, std::vector<double> probabilities, bool **adjaency)
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
}

std::string intToStr(int num)
{
  std::string ans = "";
  while (num > 0)
  {
    ans += (num % 10) + '0';
    num /= 10;
  }
  for (int i = 0; i < (int)ans.size() / 2; i++)
    std::swap(ans[i], ans[ans.size() - i - 1]);
  return ans;
}

std::string Network::status()
{
  std::string ans = "";
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
  double probability = (double)(rand() % 100 + 1) / 100;
  return probability < computers[id].getProbability();
}

void Network::makeMove()
{
  bool *newInfections = new bool[countOfComputers];
  for (int i = 0; i < countOfComputers; i++)
    newInfections[i] = computers[i].isInfected();
  for (int i = 0; i < countOfComputers; i++)
    if (computers[i].isInfected())
    for (int j = 0; j < countOfComputers; j++)
    {
      if (!matrix[i][j])
        continue;
      newInfections[j] |= willBeInfected(j);
    }
  for (int i = 0; i < countOfComputers; i++)
    computers[i].setInfected(newInfections[i]);

  delete[] newInfections;
}
