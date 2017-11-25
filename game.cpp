#include <iostream>
#include <curses.h>
#include <queue>
#include <unistd.h>  // for sleep()

#include "cell.h"
//TODO: Make cmake file

class Game{
  private:
    WINDOW * mainwin;
    std::vector< std::vector<unsigned char> > board;
    std::queue<Cell> liveCells;
    std::queue<Cell> newLiveCells;
  public:
    Game(void);
    ~Game(void);
    void setBoard(int, int);
    void printBoard(void);
};

Game::Game(void){
  // Construct window to display game board
  this->mainwin = initscr(); 
}

Game::~Game(void){
  // Destroy window displaying game board
  delwin(this->mainwin);
  endwin();
  refresh();
}


void Game::setBoard(int rows, int cols){
  this->board.assign(rows, std::vector<unsigned char>(cols, 0));
}

void Game::printBoard(void){
  // TODO: check existence of board
  
  // Check window
  if ( mainwin == NULL ) {
    fprintf(stderr, "Error initialising ncurses.\n");
    exit(EXIT_FAILURE);
  }

  // Display board
  addstr("Hello World");
  refresh();
  sleep(3);
  
}

int main(){
  Game myGame;
  int rows, cols;

  //TODO: Need to check validity of user input
  std::cout << "Enter number of rows: ";
  std::cin >> rows;
  std::cout << "Enter number of cols: ";
  std::cin >> cols;
  myGame.setBoard(rows, cols);
  myGame.printBoard();
}
