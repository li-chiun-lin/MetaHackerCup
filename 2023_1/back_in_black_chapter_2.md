# Problem

A friend who works at Metal Platforms Inc just lent you a curious puzzle, offering you tickets to a metal concert if you can solve it.

The puzzle consists of $N$ buttons in a row, numbered from $1$ to $N$. The initial state of button $i$ is white if $S_i=1$, or black if $S_i=0$. Pressing a button $k$ toggles the state of itself as well as every $k$-th button. Your friend challenges you to return the puzzle to him with all buttons back in black.

Life is hard enough without siblings pushing your buttons. Unfortunately, your brother has taken the puzzle and will push $Q$ buttons sequentially, the $i$-th being button $B_i$​.

After your brother pushes each button, you'd like to add to your answer the minimum number of button presses required to turn all the buttons black.

## Input Format

Input begins with a single integer $T$, the number of test cases.  
For each case, there is first a line containing a single integer $N$.  
Then, there is a line containing a bitstring $S$ of length $N$.  
Then, there is a line containing a single integer $Q$.  
$Q$ lines follow, the $i$-th of which contains a single integer $B_i$​.
