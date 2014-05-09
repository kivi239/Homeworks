#pragma once
#include <QString>

///Class for tic-tac-toe functionality
class TicTacToeFunc
{
public:
  TicTacToeFunc();
  ~TicTacToeFunc();

  ///enum for cells
  enum States
  {
    stateFree,
    stateX,
    stateO
  };
  ///Method which returns state of cell
  States getCell(int x, int y);
  void makeMove(int x, int y);

  ///enum which shows current state of game
  enum CurrentState
  {
    inProcess,
    winX,
    winO
  };
  CurrentState getState();
  void updateState();
  ///Method which returns true if all cells are filled or if someone wins
  bool isFinished();
  void changeSize(int newSize);
  int getSize();

private:
  enum Moves
  {
    moveX,
    moveO
  };


  States **field;
  Moves move;
  CurrentState state;

  Moves nextMove();
  ///Method which returns state of cell after player m makes his move
  States changeState(Moves m);
  int size;
  int winSize;
};
