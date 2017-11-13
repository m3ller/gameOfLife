#include <iostream>
#include <queue>

#include "cell.h"
//TODO: Make cmake file

class Game{
  std::queue<Cell> liveCells;
  //deadNeighbours
  //newLiveCells
  //newDeadNeighbours
  public:
    int test();
};

int Game::test(){
  Cell c1;
  c1.setState(true);
  liveCells.push(c1);
  return 0;
}

int main(){
  Game myGame;
  myGame.test();
}
