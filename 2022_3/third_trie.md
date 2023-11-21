# Problem

You have $N$ tries. The $i$-th trie has $M_i$​ nodes and $M_i - 1$ edges, with node $1$ being the root, and node $j$'s parent being $P_{i,j}$​, for $j = 2..M_i$​. Edge $P_{i,j} \to j$ is labeled with a lowercase letter $C_{i,j}$​.

We say a string is in a trie if it can be formed by concatenating the letters along some path starting at the root and ending at some node (either internal or leaf).

For every possible unordered triplet of these $N$ tries, you would like to know: how many strings exist which are in at least one of the three tries?

Please print the sum of answers over all $N \times (N-1) \times (N-2)/6$ possible queries.

## Input

Input begins with a single integer $T$, the number of test cases.  
For each test case, there is first a line containing a single integer $N$, the number of tries.  
Then, $N$ descriptions of tries follow.  
For the $i$-th trie, there is first a line containing a single integer $M_i$​, followed by $M_{i−1}$ more lines, the $j$-th of which contains the integer $P_{i,j+1}$​, followed by a space, followed by the letter $C_{i,j+1}$​.
