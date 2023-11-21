# Problem

Bejeweled™ is a classic puzzle game where the player tries to match three-in-a-row in a 2D grid of tiles by swapping pairs of adjacent tiles.

Isblinged™ is Hacker Cup's spinoff, played on a grid of $R$ rows by $C$ columns of tiles. The tile at $(i,j)$ is of an integer type $G_{i,j}$​. A group refers to three or more tiles of the same type, connected directly or indirectly via the four orthogonal directions (left, right, up, and down). Initially, the given grid $G$ may already contain groups.

The player may swap two orthogonally adjacent tiles of different types. If the swap results in either tile being in a group of three or more tiles, then all tiles in the newly-formed group(s) are cleared.

Please find the sum of tiles that would be cleared over all possible theoretical swaps of ordered pairs of tiles $G_{i_1,j_1}$​​ and $G_{i_2,j_2}$​​ such that $∣i_1−i_2∣+∣j_1−j_2∣=1$ and $G_{i_1,j_1}≠G_{i_2,j_2}$​​.

## Input

Input begins with an integer $T$, the number of cases.  
For each case, there is first a line containing two space-separated integers, $R$ and $C$.  
Then, $R$ lines follow, the $i$-th of which contains $C$ space-separated integers $G_{i,1..C}$​.
