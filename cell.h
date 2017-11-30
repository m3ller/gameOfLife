#include <iostream>
class Cell{
  private:
    int row;
    int col;
    bool state;  // Alive = 1; Dead = 0

  public:
    Cell(int row, int col, bool isAlive = false);
    void setState(bool);
    bool getState(void);
    int getRow(void) const;
    int getCol(void) const;
};

