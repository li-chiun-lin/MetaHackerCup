# Problem

Let's cut to the chase. You have a deck of $N$ face-up cards, each displaying a not necessarily unique integer between $1$ and $10^9$.

Cutting the deck once consists of taking a stack of between $1$ and $N - 1$ (inclusive) cards from the top and moving it to the bottom in the same order.

Initially, the $i$-th card from the top is $A_i$​. Is it possible to cut the deck exactly $K$ times to reorder the deck such that the $i$-th card from the top is $B_i$​ for all $i$?

## Input

Input begins with an integer $T$, the number of test cases.  
For each test case, there is first a line containing two space-separated integers $N$ and $K$.  
Then, there is a line containing $N$ space-separated integers, $A_1,...,A_N$​.  
Then, there is a line containing $N$ space-separated integers, $B_1,...,B_N$​.
