#include "cell.h"

void Cell::setState(bool newState){
  state = newState; 
  std::cout << "New state: " << state << std::endl;
}
