# Problem

You're playing a game against an opponent on a grid of cells with $N$ rows and $N$ columns. All of the cells are initially empty, and both players normally take turns placing symbols in empty cells (with one player placing $X$s and the other placing $O$s) until a row and/or column becomes entirely filled with one player's symbols (at which point the game ends with that player winning) or all of the cells have been filled without either player winning (in which case the game ends in a draw). Note that a player filling an entire diagonal with their symbols does not cause them to win.

This particular game is in the process of being played, with you placing $X$s and your opponent placing $O$s. The current state of the cell in the iiith row from the top and jjjth column from the left is one of the following:

- If $C_{i,j} =$ ".", the cell is still empty
- If $C_{i,j} =$ "$X$", an $X$ has been placed in the cell
- Otherwise, if $C_{i,j} ​=$ "$O$", an $O$ has been placed in the cell

In the game's current state, both players have made an equal number of turns (in other words, the number of $X$s is the same as the number of $O$s), neither player has won yet, and the game has not yet ended in a draw (meaning that at least one cell is still empty).

Your opponent has just turned their back, giving you the opportunity to immediately place as many additional $X$s on the board as you'd like, in any set of empty cells. Determine the minimum number of additional $X$s you must place such that placing them would cause you to immediately win (due to a row and/or a column becoming entirely filled with $X$s), if this is possible at all.

If it is possible, you should also determine the number of different sets of cells in which that minimum number of $X$s could be placed. Two sets of cells are considered to be different if either of them includes at least one cell which the other doesn't.

## Input

Input begins with an integer $T$, the number of games you play against your opponent.  
For each game, there is first a line containing the integer $N$.  
Then, $N$ lines follow, the $i$-th of which contains the $N$ characters $C_{i,1..N}$​.
