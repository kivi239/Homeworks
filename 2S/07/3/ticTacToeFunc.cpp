#include "ticTacToeFunc.h"
#include <cstdio>

TicTacToeFunc::TicTacToeFunc()
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      field[i][j] = stateFree;
  move = moveX;
  state = inProcess;
}

TicTacToeFunc::~TicTacToeFunc() {}

QString TicTacToeFunc::getCell(int x, int y)
{
  if (field[x][y] == stateFree)
    return " ";
  else if (field[x][y] == stateX)
    return "X";
  else
    return "O";
}

void TicTacToeFunc::updateState()
{
  if (state != inProcess)
    return;
  for (int i = 0; i < 3; i++)
  {
    if (field[i][0] != stateFree && field[i][0] == field[i][1] && field[i][1] == field[i][2])
    {
      if (field[i][0] == stateX)
        state = winX;
      else
        state = winO;
      return;
    }

    if (field[0][i] != stateFree && field[0][i] == field[1][i] && field[1][i] == field[2][i])
    {
      if (field[0][i] == stateX)
        state = winX;
      else
        state = winO;
      return;
    }
  }

  if (field[0][0] != stateFree && field[0][0] == field[1][1] && field[1][1] == field[2][2])
  {
    if (field[0][0] == stateX)
      state = winX;
    else
      state = winO;
  }

  if (field[0][2] != stateFree && field[0][2] == field[1][1] && field[1][1] == field[2][0])
  {
    if (field[0][2] == stateX)
      state = winX;
  else
      state = winO;
  }
}

TicTacToeFunc::Moves TicTacToeFunc::nextMove()
{
  if (move == moveX)
    return moveO;
  return moveX;
}

TicTacToeFunc::States TicTacToeFunc::changeState(Moves m)
{
  if (m == moveX)
    return stateX;
  return stateO;
}

void TicTacToeFunc::makeMove(int x, int y)
{
  if (isFinished())
    return;
  field[x][y] = changeState(move);
  updateState();
  move = nextMove();
}

QString TicTacToeFunc::result()
{
  if (state == inProcess)
    return "   Draw!   ";
  if (state == winX)
    return " X wins!!! ";
  return " O wins!!! ";
}

bool TicTacToeFunc::isFinished()
{
  if (state == winX || state == winO)
    return true;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (field[i][j] == stateFree)
        return false;
  return true;
}
