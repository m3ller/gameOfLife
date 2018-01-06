#include <algorithm>
#include <curses.h>
#include <iostream>
#include <forward_list>
#include <list>
#include <unistd.h>  // for sleep()

#include "cell.h"
//TODO: Make cmake file
//TODO: outline game board.  so user knows when cells are at the edge

class Game{
  private:
    WINDOW * mainwin;
    int n_rows;
    int n_cols;
    //std::vector< std::vector<unsigned char> > board;
    std::vector< std::vector<int> > board;
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
  //this->board.assign(n_rows, std::vector<unsigned char>(n_cols, 0));
  this->board.assign(n_rows, std::vector<int>(n_cols, 0));
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
  this->liveCells.emplace_after(it, Cell(row, col, true));      
  //this->board[row][col] = 1;
}

//TODO: way for user to dynamically input cells.
void Game::initializeBoard(void){
  // Set up a default start board
  // Blinker
  /*this->addCell(1, 0);
  this->addCell(1, 1);
  this->addCell(2, 0);
  this->addCell(2, 1);
  this->addCell(3, 2);
  this->addCell(3, 3);
  this->addCell(4, 2);
  this->addCell(4, 3);*/

  // Glider
  this->addCell(5, 0);
  this->addCell(6, 1);
  this->addCell(6, 2);
  this->addCell(5, 2);
  this->addCell(4, 2);
}

void Game::updateBoard(void){
  // Update board with values
  auto it = this->liveCells.before_begin();

  std::list<Cell> neighbours;
  auto it_neigh = neighbours.begin();

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
        this->board[i][j]++;
        //bool state = false;
        if (i==row and j==col){
          neighbours.emplace_front(Cell(i, j, true));
        }else{
          neighbours.emplace_back(Cell(i, j, false));
        }
        //++it_neigh;
      }
    }
    ++it;
  }

  // Find cells
  std::forward_list<Cell> tempLiveCells;
  it = tempLiveCells.before_begin();
  it_neigh = neighbours.begin();
  while(it_neigh != neighbours.cend()){
    int row = (*it_neigh).getRow();
    int col = (*it_neigh).getCol();
    /*if(this->board[row][col] >= 3 and this->board[row][col] < 5){
      tempLiveCells.emplace_after(it, Cell(row,col));
      it++;
    }*/
    if ((*it_neigh).getState() == true){
      if(this->board[row][col] == 3 or this->board[row][col] == 4){ 
        //it = tempLiveCells.insert_after(it, Cell(row,col,true));
        it = tempLiveCells.insert_after(it, Cell(row,col,true));
      }
    }else{
      if(this->board[row][col] ==3){ 
        //it = tempLiveCells.insert_after(it, Cell(row,col,true));
        it = tempLiveCells.insert_after(it, Cell(row,col,true));
      }
    }
    this->board[row][col] = 0;
    it_neigh++;
  }
  this->liveCells.swap(tempLiveCells);
   
}

void Game::displayBoard(void){
  // TODO: check existence of board
  
  // Check window existence
  if ( mainwin == NULL ) {
    fprintf(stderr, "Error initialising ncurses.\n");
    exit(EXIT_FAILURE);
  }

  // Display board
  clear();
  for(Cell& cell: this->liveCells){
    mvaddstr(cell.getRow(), cell.getCol(), "o");
  }
  refresh();
  sleep(1);
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
  while(true){
    myGame.updateBoard();
    myGame.displayBoard();
  }
}
