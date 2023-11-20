# Problem

Let $d(N)$ be the number of positive divisors of positive integer $N$. Consider the infinite sequence $x(n) = d(n)^a / n^b, n = 1, 2, 3, …$ where $a$ and $b$ are fixed positive integers. It can be shown that this sequence tends to zero. Hence it attains its maximum. Denote it by $p/q$ where $p$ and $q$ are co-prime positive integers. Your task is for given $a$ and $b$ find $p$ and $q$ modulo $M = 10^9+7$. But to keep input and output small you will be given tuples $(b1, b2, a1, a2, c)$ and need to calculate the sum of $(p \mod M)$ for all pairs $(a, b)$ such that $b1 ≤ b ≤ b2$, $a1 ≤ a ≤ a2$ and $a ≤ c \times b$, and the same sum for $q$-values.

## Input

The first line contains a positive integer $T$, the number of test cases. $T$ test cases follow.  
The only line of each test case contains five space separated positive integers $b1, b2, a1, a2$ and $c$.
