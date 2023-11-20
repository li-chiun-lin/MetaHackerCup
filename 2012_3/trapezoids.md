# Problem

Consider two horizontal lines and a set of $N$ trapezoids. A trapezoid $T[i]$ between these lines has two vertices situated on the upper line and the other two vertices on the lower line. We will denote by $a[i], b[i], c[i]$ and $d[i]$ the upper left, upper right, lower left and respectively lower right vertices of the trapezoid $T[i]$. Assume that no two trapezoids share a common vertex (meaning that all $a[i]$ and $b[i]$ coordinates on the upper line are different, and the same holds for the bottom line and coordinates $c[i]$ and $d[i]$). A trapezoid set is called disconnected if one can separate the trapezoids in two or more groups such that no two trapezoids from different groups intersect. Determine the smallest number of trapezoids to remove, such that the remaining trapezoids form a disconnected set. If the solution does not exist, output $-1$.

## Input

The first line of the input file contains an integer $T$, and this is followed by $T$ test cases. Each test case is given in the compressed format.

The first line of each test case contains the number of trapezoids $N$, an integer $K$, and integer parameters $X, A, B, M, p, q$. In the next $K$ lines are given integer numbers $aa[i], bb[i], cc[i], dd[i]$. The following code is used for generating the next random number using linear congruential generator with the starting value $X$ and parameters $A$, $B$ and modulo $M$:

```cpp
long long prior = X;
long long next() {
  prior = (A * prior + B) % M;
  return prior;
}
```

The following code is used for extending the auxiliary sequences $aa, bb, cc$ and $dd$:

```cpp
for (int i = K; i < N; i++) {
    aa [i] = aa [i - K] + next() % (2 * p) - p;
    bb [i] = aa [i] + 1 + next() % (2 * (bb [i % K] - aa [i % K]));
    cc [i] = cc [i - K] + next() % (2 * q) - q;
    dd [i] = cc [i] + 1 + next() % (2 * (dd [i % K] - cc [i % K]));
}
```

The final coordinates of the trapezoids are given by:

```cpp
for (int i = 0; i < N; i++) {
    a [i] = aa [i] * 1000000 + i;
    b [i] = bb [i] * 1000000 + i;
    c [i] = cc [i] * 1000000 + i;
    d [i] = dd [i] * 1000000 + i;
}
```

Note that above code generates trapezoids that satisfy all conditions of the problem, and '%' denotes the remainder of division.
