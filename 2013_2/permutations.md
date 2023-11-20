# Problem

In this problem you need to count number of possible permutations $p$ of the first $N$ integers, given $N-1$ constraints of the form $p_i < p_j$.

## Input

The first line contains an integer $T$, followed by $T$ test cases.  
Each test case begins with an integer $N$, which is the number of integers in the permutation.  
The next $N - 1$ lines each contain a single constraint in the following format: "$i$ sign $j$", where $0 ≤ i, j ≤ N - 1$ and sign is either "<" or ">", which denotes whether the $i$-th element of the permutation should be less than or greater than the $j$-th element.
