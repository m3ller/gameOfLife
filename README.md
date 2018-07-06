# gameOfLife
Making Conway's Game of Life, a game where one watches colonies of cells evolve by following a simple set of rules. Cells in the game come to life, live, or die with each time-step of the game.

The game is displayed on the terminal.

## Code overview
The gameboard is essentially a sparse matrix. Rather than storing and tracking the entire matrix, I am only tracking the live cells at each iteration and applying the rules on them accordingly. After each iteration, the board is updated and displayed on the terminal.
