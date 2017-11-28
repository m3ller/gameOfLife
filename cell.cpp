#include "cell.h"

Cell::Cell(int row, int col){
  this->row = row;
  this->col = col;
}

void Cell::setState(bool isAlive){
  this->state = isAlive; 
}

bool Cell::getState(void){
  return this->state;
}

int Cell::getRow(void) const{
  return this->row;
}

int Cell::getCol(void) const{
  return this->col;
}
