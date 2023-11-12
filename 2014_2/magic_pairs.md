# Problem

The princess of the kingdom of Hackadia has been kidnapped by an evil dragon. As always the prince Z.A.Y. is going to try to rescue her. The evil dragon is keeping the princess prisoner in his deepest dungeon, and the prince has to solve a puzzle to get her out safely.

There are two straight boards in front of the dungeon, both divided into a large number of sections. Each section contains a sparkling gemstone. Each stone has a color. We will denote these colors with numbers.

Let's say these boards $Board_1$ and $Board_2$ contain $N$ and $M$ sections respectively. Let's call a pair of integers $x, y$ a magic pair if they have the following properties:

1. $0 ≤ x < N$
1. $0 ≤ y < M$
1. The set of different colors in $Board_1[0...x]$ equals the set of different colors in $Board_2[0...y]$

The prince has asked you to find out how many magic pairs exist for the given two boards, so he can free the princess and become the hero. He will take all the glory from this, so you will have to make do with points in this competition as payment for your help.

Since the numbers $N$ and $M$ might be very large, the colors of the gemstones will be supplied through a pseudo random generator. This works as follows:  
$Board_1[0] = x1$  
$Board_2[0] = x2$  
$Board_1[i] = (a1 \times Board_1[(i-1) \mod N] + b1 \times Board_2[(i-1) \mod M] + c1) \mod r1$, for $0 < i < N$  
$Board_2[i] = (a2 \times Board_1[(i-1) \mod N] + b2 \times Board_2[(i-1) \mod M] + c2) \mod r2$, for $0 < i < M$

## Input

The first line of the input consists of a single integer $T$, the number of test cases.  
Each test case starts with a line containing the integers $N$, $M$  
The second line of each test case contains five integers $x1, a1, b1, c1, r1$  
The third line of each test case contains five integers $x2, a2, b2, c2, r2$
