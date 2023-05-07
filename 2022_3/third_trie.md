# Problem

You have $N$ tries. The $i$-th trie has $M_i$​ nodes and $M_i - 1$ edges, with node $1$ being the root, and node $j$'s parent being $P_{i,j}$​, for $j = 2..M_i$​. Edge $P_{i,j} \to j$ is labeled with a lowercase letter $C_{i,j}$​.

We say a string is in a trie if it can be formed by concatenating the letters along some path starting at the root and ending at some node (either internal or leaf).

For every possible unordered triplet of these $N$ tries, you would like to know: how many strings exist which are in at least one of the three tries?

Please print the sum of answers over all $N*(N-1)*(N-2)/6$ possible queries.
