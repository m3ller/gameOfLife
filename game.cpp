#include <iostream>
#include <ncurses.h>
#include <queue>
#include <unistd.h>

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
  //c1.setState(true);
  //liveCells.push(c1);
  return 0;
}

int main(){
  Game myGame;
  myGame.test();
  std::cout << "Hello Mello" << std::flush;
  sleep(2);
  std::cout << "\rNight, Dude!" << std::endl;
}
