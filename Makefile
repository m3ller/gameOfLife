game.o: cell.cpp game.cpp
	g++ --std=c++11 cell.cpp game.cpp -lncurses -o game.o
