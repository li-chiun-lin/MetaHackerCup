# Problem

Little Scott recently learned how to perform arithmetic operations modulo some prime number $P$. As a training set he picked two sequences $a$ of length $N$ and $b$ of length $M$, generated in the following way:

- $a_1=A1$
- $a_2=A2$
- $a_i=(a_{i-2} \times A3 + a_{i-1} \times A4 + A5) \mod P$, for $i=3...N$
- $b_1=B1$
- $b_2=B2$
- $b_j=(b_{j-2} \times B3 + b_{j-1} \times B4 + B5) \mod P$, for $j=3...M$

Now he wants to find the number of pairs $(i, j)$, where $1 ≤ i ≤ N$ and $1 ≤ j ≤ M$, such that $(a_i \times b_j) \mod P < L$, for given number $L$. He asked you to do the same to help him check his answers.

## Input

The first line of input file consists of a single number $T$, the number of test cases. Each test consists of three lines.  
The first line of a test case contains two integers: prime number $P$ and positive integer $L$.  
The second line consists of six non-negative integers $N, A1, A2, A3, A4, A5$.  
Likewise, the third line contains six non-negative integers $M, B1, B2, B3, B4, B5$.
