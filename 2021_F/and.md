# Problem

Andy has no time for ores, he's just here for the ANDs.

Andy has $N$ pairs of integers, with each integer given in binary as a bitstring. The $i$-th pair consists of bitstrings $A_i$​ and $B_i$​. No bitstring has leading zeros (except for the bitstring "0" itself).

Andy may choose at most $K$ of these pairs for swapping. For each chosen pair $i$, he'll swap its bitstrings $A_i$ and $B_i$​.

After all of these swaps, he'll compute $X$ as the bitwise AND of the $N$ bitstrings $A_{1..N}$​, and $Y$ as the bitwise AND of the $N$ bitstrings $B_{1..N}$​, and finally add $X$ and $Y$ together. What's the maximum sum of $X+Y$ that Andy can achieve?

Note that:

- The integer value of a bitstring $S$ is equal to $S_1∗2^{∣S∣−1}+S_2∗2^{∣S∣−2}+...+S_{∣S∣}∗2^0$.
- The bitwise AND of a set of bitstrings $S$ is a bitstring $V$ such that, if leading zeros were appended to bitstrings in $S$ until they all had the same length, then $V$ also has that same length, with $V_i$​ equal to $1$ if and only if all bitstrings in $S$ have a $1$ at index $i$.

## Input

Input begins with an integer $T$, the number of test cases.  
For each test case, there is first a line containing 2 space-separated integers, $N$ and $K$.  
Then, $N$ lines follow, the $i$-th of which contains 2 space-separated bitstrings, $A_i$​ and $B_i$​.
