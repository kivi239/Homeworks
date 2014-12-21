#pragma once

class Computer
{
public:
  Computer(double p = 0);
  /**
   * @brief setProbability set the probability of being infected
   * @param p probability
   */
  //void setProbability(double p);
  /**
   * @brief getProbability get the probability of being infected
   * @return probability
   */
  double getProbability();
  /**
   * @brief setInfected makes computer infected or not infected
   * @param isInfected
   */
  void setInfected(bool isInfected);
  /**
   * @brief isInfected shows is this computer infected or not
   * @return is it infected or not
   */
  bool isInfected();

private:
  double probability;
  bool infected;
};
