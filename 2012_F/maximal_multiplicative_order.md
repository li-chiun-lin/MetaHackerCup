# Problem

Let's start with some notations and definitions. Let $m$ be the fixed positive integer.

1. Let a be an integer that coprime to $m$, that is, $\gcd(a, m) = 1$. The minimal positive integer $k$ such that $m$ divides $a^k − 1$ is called the multiplicative order of a modulo $m$ and denoted as $ord_m(a)$. It can be proven that $ord_m(a)$ exists for every $a$ that coprime to $m$.
2. Denote by $L(m)$ the maximal possible multiplicative order of some number modulo $m$. That is, $L(m) = \max{ord_m(a) : 1 ≤ a ≤ m, \gcd(a, m)=1}$.
3. Denote by $N(m)$ the number of positive integers $a ≤ m$ such that $ord_m(a) = L(m)$.

Now your task is to find for the given positive integers $L$ and $R$ such that $L ≤ R$ the product

$N(L) \times N(L+1) \times ... \times N(R) \mod 10^9 + 7$.

## Input

The first line contains a positive integer $T$, the number of test cases. $T$ test cases follow.  
The only line of each test case contains two space separated positive integers $L$ and $R$.
