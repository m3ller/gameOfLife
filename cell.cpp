#include "cell.h"

Cell::Cell(void){}

void Cell::setState(bool isAlive){
  this->state = isAlive; 
}

bool Cell::getState(void){
  return this->state;
}
