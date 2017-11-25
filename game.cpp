#include <iostream>
#include <curses.h>
#include <queue>
#include <unistd.h>  // for sleep()

#include "cell.h"
//TODO: Make cmake file

class Game{
  private:
    std::vector< std::vector<unsigned char> > board;
    std::queue<Cell> liveCells;
    std::queue<Cell> newLiveCells;
  public:
    void setBoard(int, int);
    void printBoard(void);
};

void Game::setBoard(int rows, int cols){
  board.assign(rows, std::vector<unsigned char>(cols, 0));
}

void Game::printBoard(void){
  // TODO: check existence of board
  
  // Make window
  WINDOW * mainwin = initscr();
  if ( mainwin == NULL ) {
    fprintf(stderr, "Error initialising ncurses.\n");
    exit(EXIT_FAILURE);
  }

  // Display board
  addstr("Hello World");
  refresh();
  sleep(3);
  
  // Clean up window  
  delwin(mainwin);
  endwin();
  refresh();
}

int main(){
  Game myGame;
  int rows, cols;

  // Need to check validity of user input
  std::cout << "Enter number of rows: ";
  std::cin >> rows;
  std::cout << "Enter number of cols: ";
  std::cin >> cols;
  myGame.setBoard(rows, cols);
  myGame.printBoard();
}
