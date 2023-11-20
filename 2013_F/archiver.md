# Problem

You are writing a new revolutionary archiver. The archive is essentially a pair of non-decreasing sequences of integers of equal length $K: 0≤x_1≤...≤x_k$ and $0≤y_1≤...≤y_k$.

The decompression algorithm proceeds as follows:

1. Sequence $(0,0), (x_1,y_1), ... (x_k,y_k), (x_k, 0), (0, 0)$ defines a polygon $P$.
1. Starting from the point $(0,0)$, increase either $x$ or $y$ coordinate by $1$ without moving outside of $P$. If both moves are available, you should increase $y$. After each step write $0$ to output if incremented $x$ or $1$ otherwise.
1. Repeat step 2 until you end up in point $(x_k,y_k)$.

Your task is to write a compression rate calculator, that is given binary string $s$ find the smallest value of $K$ for which there exists archive that decompresses to $s$.

## Input

The first line contains a single integer $T$. $T$ test cases follow, where each test case consists of one binary string.
