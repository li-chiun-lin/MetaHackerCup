# Problem

You're playing a game against an opponent on a grid of cells with ***N*** rows and ***N*** columns. All of the cells are initially empty, and both players normally take turns placing symbols in empty cells (with one player placing **X**s and the other placing **O**s) until a row and/or column becomes entirely filled with one player's symbols (at which point the game ends with that player winning) or all of the cells have been filled without either player winning (in which case the game ends in a draw). Note that a player filling an entire diagonal with their symbols does not cause them to win.

This particular game is in the process of being played, with you placing **X**s and your opponent placing **O**s. The current state of the cell in the iiith row from the top and jjjth column from the left is one of the following:

- If *C<sub>i,j</sub>*  = ".", the cell is still empty
- If *C<sub>i,j</sub>* = "X", an **X** has been placed in the cell
- Otherwise, if *C<sub>i,j</sub>* ​= "O", an **O** has been placed in the cell

In the game's current state, both players have made an equal number of turns (in other words, the number of **X**s is the same as the number of **O**s), neither player has won yet, and the game has not yet ended in a draw (meaning that at least one cell is still empty).

Your opponent has just turned their back, giving you the opportunity to immediately place as many additional **X**s on the board as you'd like, in any set of empty cells. Determine the minimum number of additional **X**s you must place such that placing them would cause you to immediately win (due to a row and/or a column becoming entirely filled with **X**s), if this is possible at all.

If it is possible, ***you should also determine the number of different sets of cells in which that minimum number of **X**s could be placed***. Two sets of cells are considered to be different if either of them includes at least one cell which the other doesn't.

## Sample input

```text
8
2
XO
..
2
X.
.O
3
...
...
...
3
.OX
X..
..O
3
OXO
X.X
OXO
3
.XO
O.X
XO.
4
X...
.O.O
.XX.
O.XO
5
OX.OO
X.XXX
OXOOO
OXOOO
XXXX.
```

## Sample output

```text
Case #1: 1 1
Case #2: 1 2
Case #3: 3 6
Case #4: 2 2
Case #5: 1 1
Case #6: Impossible
Case #7: 2 2
Case #8: 1 2
```
