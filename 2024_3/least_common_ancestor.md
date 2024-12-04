# Problem

Staring at your family tree, you’d like to figure out who your least common ancestor is. That is, out of all the names of all your ancestors, which name appears the fewest times? While you’re at it, which name is the least common amongst all of your descendants? And why stop there? Why not figure out these values for everybody in your family tree?
Your family tree has $N$ people, numbered from $1$ to $N$. The $i$-th person has name $S_i$​, and parent $P_i$​. Person $1$ is the root of the tree and $P_1$​ is always $-1$.
Let $U$ be the list of unique names that appear in $S$, in lexicographically increasing order.
For each person $i$, let $A_i$​ be the ($1$-indexed) index of the name in $U$ that is least common among all ancestors of person $i$, and $D_i$​ be the index of the name in $U$ that is least common among all descendants of person $i$. If there’s a tie for the least common name, we choose the name with the lowest index in $U$. If the person has no ancestors or no descendants, then $A_i$​ or $D_i$​ is $0$, respectively.
To reduce the output size, output a hash of the arrays $A$ and $D$, computed as follows:

```text
  hash := 0
  for i := 1 to N:
      hash := hash * (|U| + 1) + A[i]
      hash := hash * (|U| + 1) + D[i]
      hash := hash mod 998,244,353
```

## Input Format

Input begins with an integer $T$, the number of test cases.
The first line of each case contains the integer $N$.
Then, $N$ lines follow, the $i$-th of which contains the integer $P_i$​ and the string $S_i$​.
