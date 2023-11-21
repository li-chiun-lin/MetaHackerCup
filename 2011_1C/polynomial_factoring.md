# Problem

A polynomial in $x$ of degree $D$ can be written as:

$a_Dx^D + a_{D-1}x^{D-1} + ... + a_1x^1 + a_0$

In some cases, a polynomial of degree $D$ can also be written as the product of two polynomials of degrees $D_1$ and $D_2$, where $D = D_1 + D_2$. For instance,

$4 x^2 + 11 x^1 + 6 = (4 x^1 + 3) \times (1 x^1 + 2)$

In this problem, you will be given two polynomials, denoted $F$ and $G$. Your task is to find a polynomial $H$ such that $G * H = F$, and each $a_i$ is an integer.

## Input

You should first read an integer $N ≤ 60$, the number of test cases.  
Each test case will start by describing $F$ and then describe $G$.  
Each polynomial will start with its degree $0 ≤ D ≤ 20$, which will be followed by $D+1$ integers, denoting $a_0, a_1, ... , a_D$, where $-10000 ≤ a_i ≤ 10000$.  
Each polynomial will have a non-zero coefficient for it's highest order term.
