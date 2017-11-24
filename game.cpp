#include <iostream>
#include <ncurses.h>
#include <queue>
#include <unistd.h>  // for sleep()

#include "cell.h"
//TODO: Make cmake file

class Game{
  std::queue<Cell> liveCells;
  std::queue<Cell> newLiveCells;
  public:
    int test();
};

int Game::test(){
  Cell c1;
  c1.setState(true);
  //liveCells.push(c1);
  return 0;
}

int main(){
  Game myGame;
  myGame.test();
}
