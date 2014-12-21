#pragma once
#include <vector>
#include "computer.h"
#include <string>

class Network
{
public:
  Network(std::vector<int> infections, std::vector<double> probabilities, bool **adjaency);
  ~Network();

  /**
   * @brief makeMove spread the infection between computers
   */
  void makeMove();
  /**
   * @brief status shows information about infections at the moment
   * @return list of computers which are infected (E.g. "1, 2, 5")
   */
  std::string status();

private:
  bool willBeInfected(int id);
  int countOfComputers;
  std::vector<Computer> computers;
  bool **matrix;
};

