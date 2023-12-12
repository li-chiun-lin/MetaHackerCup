# Problem

Bejeweled™ is a classic puzzle game where the player tries to match three-in-a-row in a 2D grid by swapping adjacent tile pairs. You may remember Hacker Cup's spinoff by the name of Isblinged™. The all new sequel, Isblinged 2, is also played on a grid of $R$ rows by $C$ columns of tiles where the tile at $(i,j)$ is of an integer type $G_{i,j}$​.

At any time, the score of the grid is the number of subarrays of $3$ equal tiles in either a single row or column (i.e. either a $3×1$ or $1×3$ submatrix). Note that different subarrays can overlap, and will each count toward the score. The score of the initial grid is guaranteed to be $0$.

You will make exactly $2$ moves, where each involves swapping a pair of adjacent tiles (either in the same row or column). What is the maximum score that can be achieved after the $2$ moves?

## Input

Input begins with an integer $T$, the number of test cases.  
For each case, there is first a line containing two space-separated integers, $R$ and $C$.  
Then, $R$ lines follow, the $i$-th of which contains $C$ space-separated integers $G_{i,1..C}$​.
