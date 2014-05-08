#pragma once
#include <QString>

///Class for tic-tac-toe functionality
class TicTacToeFunc
{
public:
  TicTacToeFunc();
  ~TicTacToeFunc();

  ///Method which returns state of cell
  QString getCell(int x, int y);
  void makeMove(int x, int y);
  ///Property which returns state of a game (In progress, X wins or O wins)
  QString result();
  void updateState();
  ///Method which returns true if all cells are filled or if someone wins
  bool isFinished();

private:
  ///enum for cells
  enum States
  {
    stateFree,
    stateX,
    stateO
  };

  enum Moves
  {
    moveX,
    moveO
  };

  ///enum which shows current state of game
  enum CurrentState
  {
    inProcess,
    winX,
    winO
  };

  States field[3][3];
  Moves move;
  CurrentState state;

  Moves nextMove();
  ///Method which returns state of cell after player m makes his move
  States changeState(Moves m);
};
