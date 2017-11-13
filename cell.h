#include <iostream>
class Cell{
  int row = -1;
  int col = -1;
  bool state = 0;  // alive=1, dead=0

  public:
    void setState(bool);
};

