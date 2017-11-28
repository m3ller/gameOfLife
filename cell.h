#include <iostream>
class Cell{
  private:
    int row;
    int col;
    bool state = false;  // Alive = 1; Dead = 0

  public:
    Cell(int, int);
    void setState(bool);
    bool getState(void);
    int getRow(void) const;
    int getCol(void) const;
};

