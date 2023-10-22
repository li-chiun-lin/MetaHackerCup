# Problem

Atari 2600? More like Atari 2600 BCE!

The classic board game Go is a two-player game played on an $R×C$ board. One player places white stones while the other places black stones. On a player's turn, they may place a stone in any empty space. A curiosity of Go is that stones are placed on the intersections of grid lines rather than between the lines.

An orthogonally contiguous set of stones of the same color is called a group. A group of stones is captured (and removed from the board) once no stones in the group has an adjacent empty space.

You're playing as Black and it's your turn. Given a valid board (i.e. no groups have $0$ adjacent empty spaces), what’s the maximum number of white stones you can capture with a single black stone?

The Go board is represented as a character array $A$ where $A_{i,j}$​ is one of:

- B for a black stone
- W for a white stone
- . for an empty space

## Input Format

Input begins with an integer $T$, the number of test cases.  
Each case begins with a line containing two integers $R$ and $C$.  
Then, $R$ lines follow, the $i$-th of which contains $C$ characters $A_{i,1}$​ through $A_{i,C}$​.
