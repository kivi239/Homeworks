#include "ticTacToeFunc.h"
#include <cstdio>

TicTacToeFunc::TicTacToeFunc()
{
  size = 3;
  winSize = 3;
  field = new States *[size];
  for (int i = 0; i < size; i++)
    field[i] = new States[size];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      field[i][j] = stateFree;
  move = moveX;
  state = inProcess; 
}

TicTacToeFunc::~TicTacToeFunc()
{
  for (int i = 0; i < size; i++)
    delete[] field[i];
  delete[] field;
}

TicTacToeFunc::States TicTacToeFunc::getCell(int x, int y)
{
  return field[x][y];
}

void TicTacToeFunc::updateState()
{
  if (state != inProcess)
    return;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size - winSize + 1; j++)
    {
      bool win = true;
      for (int k = 0; k < winSize - 1; k++)
        if (field[i][j + k] == TicTacToeFunc::stateFree || field[i][j + k] != field[i][j + k + 1])
        {
          win = false;
          break;
        }
      if (!win)
        continue;

      if (field[i][j] == stateX)
        state = winX;
      else
        state = winO;
      return;
    }
  }

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size - winSize + 1; j++)
    {
      bool win = true;
      for (int k = 0; k < winSize - 1; k++)
        if (field[j + k][i] == TicTacToeFunc::stateFree || field[j + k][i] != field[j + k + 1][i])
        {
          win = false;
          break;
        }

      if (!win)
        continue;

      if (field[j][i] == stateX)
        state = winX;
      else
        state = winO;
      return;
  }

  for (int i = 0; i < size - winSize + 1; i++)
    for (int j = 0; j < size - winSize + 1; j++)
    {
      bool win = true;
      for (int k = 0; k < winSize - 1; k++)
        if (field[i + k][j + k] == TicTacToeFunc::stateFree || field[i + k][j + k] != field[i + k + 1][j + k + 1])
        {
          win = false;
          break;
        }
      if (!win)
        continue;

      if (field[i][j] == stateX)
        state = winX;
      else
        state = winO;

      return;
    }

  for (int i = 0; i < size - winSize + 1; i++)
    for (int j = winSize - 1; j < size; j++)
    {
      bool win = true;
      for (int k = 0; k < winSize - 1; k++)
        if (field[i + k][j - k] == TicTacToeFunc::stateFree || field[i + k][j - k] != field[i + k + 1][j - k - 1])
        {
          win = false;
          break;
        }
      if (!win)
        continue;

      if (field[i][j] == stateX)
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

TicTacToeFunc::CurrentState TicTacToeFunc::getState()
{
  return state;
}

bool TicTacToeFunc::isFinished()
{
  if (state == winX || state == winO)
    return true;
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (field[i][j] == stateFree)
        return false;

  return true;
}

void TicTacToeFunc::changeSize(int newSize)
{
  for (int i = 0; i < size; i++)
    delete[] field[i];
  delete[] field;
  field = new States*[newSize];
  for (int i = 0; i < newSize; i++)
    field[i] = new TicTacToeFunc::States[newSize];
  for (int i = 0; i < newSize; i++)
    for (int j = 0; j < newSize; j++)
      field[i][j] = TicTacToeFunc::stateFree;

  size = newSize;
  winSize = 5;
  move = TicTacToeFunc::moveX;
}

int TicTacToeFunc::getSize()
{
  return size;
}
