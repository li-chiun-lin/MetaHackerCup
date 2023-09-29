# Problem

You've got yourself an unrooted tree with $N$ nodes — that is, a connected, undirected graph with $N$ nodes numbered from $1$ to $$, and $N - 1$ edges. The $i$-th edge connects nodes $A_i$ and $B_i$.

You'd like to spend as little money as possible to label each node with a number from $1$ to $K$, inclusive. It costs $C_{i,j}$ dollars to label the $i$-th node with the number $j$.

Additionally, after the whole tree has been labelled, you must pay $P$ more dollars for each node which has at least one pair of neighbours that share the same label as each other. In other words, for each node $u$, you must pay $P$ dollars if there exist two other nodes $v$ and $w$ which are both adjacent to node $u$, such that the labels on nodes $v$ and $w$ are equal (note that node $u$'s label is irrelevant). You only pay the penalty of $P$ dollars once for a given central node $u$, even if it has multiple pairs of neighbours which satisfy the above condition.

What's the minimum cost (in dollars) to label all $N$ nodes?

## Input

Input begins with an integer $T$, the number of trees.  
For each tree, there is first a line containing the space-separated integers $N$, $K$, and $P$.  
Then, $N$ lines follow, the $i$-th of which contains the space-separated integers $C_{i,1}$ through $C_{i,K}$ in order.  
Then, $N - 1$ lines follow, the $i$-th of which contains the space-separated integers $A_i$ and $B_i$
