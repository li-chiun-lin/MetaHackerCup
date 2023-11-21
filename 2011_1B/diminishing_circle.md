# Problem

$N$ people are standing in circle and play following game: they start with the first person, count $K$ people clockwise, then the $K+1$-th person leaves the circle and the process starts all over, using the person clockwise of the last person removed as the starting point.

For example when $N = 9$ and $K = 3$ people would leave in following order: $4, 8, 3, 9, 6, 5, 7, 2$

Given $N$ and $K$, find who wins the game if counting starts with person $1$. Person indices are $1$-based.

The last person who is left is declared the winner.

## Input

The input consists of a single integer $T$, the number of test cases.  
This is followed by $T$ pairs of numbers $N$ and $K$, all separated by whitespace.
