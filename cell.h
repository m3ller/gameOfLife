#include <iostream>
class Cell{
  private:
    bool state = false;  // Alive = 1; Dead = 0

  public:
    Cell();
    void setState(bool);
    bool getState(void);
};

