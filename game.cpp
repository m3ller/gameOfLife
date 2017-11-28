#include <algorithm>
#include <curses.h>
#include <iostream>
#include <forward_list>
#include <unistd.h>  // for sleep()

#include "cell.h"
//TODO: Make cmake file

class Game{
  private:
    WINDOW * mainwin;
    int n_rows;
    int n_cols;
    std::vector< std::vector<unsigned char> > board;
    std::forward_list<Cell> liveCells;  // Change to a list.  Don't need queue
    //std::forward_list<Cell> newLiveCells;
  public:
    Game(int, int);
    ~Game(void);
    void initializeBoard(void);
    void updateBoard(void);
    void displayBoard(void);
    void addCell(int, int);
};

Game::Game(int n_rows, int n_cols){
  // Construct window to display game board
  this->mainwin = initscr(); 
  this->board.assign(n_rows, std::vector<unsigned char>(n_cols, 0));
  this->n_rows = n_rows;
  this->n_cols = n_cols;
}

Game::~Game(void){
  // Destroy window displaying game board
  delwin(this->mainwin);
  endwin();
  refresh();
}

void Game::addCell(int row, int col){
  //TODO: This looks like an odd way to add cells
  auto it = this->liveCells.before_begin();
  this->liveCells.emplace_after(it, Cell(row, col));      
  this->board[row][col] = 1;
}

void Game::initializeBoard(void){
  // Set up a default start board
  this->addCell(0, 0);
  this->addCell(2, 0);
  this->addCell(1, 2);
  this->addCell(0, 2);
}

void Game::updateBoard(void){
  // Update board with values
  auto it = this->liveCells.begin();

  std::forward_list<Cell> neighbours;  // Change to a list.  Don't need queue
  auto it_neigh = neighbours.before_begin();

  while(it != this->liveCells.cend()){
    Cell cell = *it;
    int row = cell.getRow();
    int col = cell.getCol();

    int minrow = std::max(0, row-1);
    int maxrow = std::min(this->n_rows-1, row+1);
    int mincol = std::max(0, col-1);
    int maxcol = std::min(this->n_cols-1, col+1);
  
    for(int i = minrow; i <= maxrow; i++){
      for(int j = mincol; j<= maxcol; j++){
        if(i==row and j==col){
          continue;
        }
        neighbours.emplace_after(it_neigh, Cell(i, j));
        this->board[i][j] += 1;
      }
    }
    it++;
    it_neigh++;
  }

  // Find cells
  it_neigh = neighbours.begin();
  while(it_neigh != neighbours.cend()){
    int row = (*it_neigh).getRow();
    int col = (*it_neigh).getCol();
    if(this->board[row][col] >= 3 and this->board[row][col] < 5){
      this->liveCells.emplace_after(this->liveCells.cbegin(), Cell(row,col));
    }
    it_neigh++;
  }
  
  // Update new live cells
  //this->liveCells.swap(this->newLiveCells);
  //TODO: clear up newLiveCells
   
}

void Game::displayBoard(void){
  // TODO: check existence of board
  
  // Check window existence
  if ( mainwin == NULL ) {
    fprintf(stderr, "Error initialising ncurses.\n");
    exit(EXIT_FAILURE);
  }

  // Display board
  // TODO: check that liveCells isn't empty
  auto it = liveCells.cbegin();
  do{
    Cell cell = *it;
    mvaddstr(cell.getRow(), cell.getCol(), "o");
    it++;
  }while(it != liveCells.cend());

  refresh();
  sleep(3);
}

int main(){
  //TODO: Need to check validity of user input
  int n_rows, n_cols;
  std::cout << "Enter number of rows: ";
  std::cin >> n_rows;
  std::cout << "Enter number of cols: ";
  std::cin >> n_cols;

  Game myGame(n_rows, n_cols);
  myGame.initializeBoard();
  myGame.displayBoard();
  myGame.updateBoard();
  myGame.displayBoard();
}
