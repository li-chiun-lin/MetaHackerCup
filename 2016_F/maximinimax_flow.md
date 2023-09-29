# Problem

You're given an undirected, connected graph with $N$ nodes (numbered from $1$ to $N$) and $N$ edges. The $i$-th edge connects distinct nodes $A_i$ and $B_i$, and has a capacity of $C_i$. No two edges directly connect the same pair of nodes.

$M$ operations will be performed on this graph, one after another. The nature of the $i$-th operation is described by the value of $O_i$:

- If $O_i = 1$, then the $i$-th operation is an update, in which the capacity of the $X_i$-th edge is changed to be $Y_i$.

- Otherwise, if $O_i = 2$, then the $i$-th operation is a query, in which you must determine the maximinimax flow in the graph after $Z_i$ edge augmentations.

What do any of those terms mean? Let's define them:

- An edge augmentation is a temporary increase of a certain edge's capacity by 1 for the current query.

- The max flow from node $u$ to a different node $v$ is the usual definition of maximum flow in computer science (hopefully you're familiar with it!), with node $u$ being the source and node $v$ being the sink. Each edge may transport flow in either direction, so it may be thought of as two directed edges (one in each direction), both with the same capacity.

- The minimax flow in the graph is the smallest max flow value across all pairs of distinct nodes. In other words, $ \min \{1 ≤ u, v ≤ N, u ≠ v \} (F(u, v))$, where $F(u, v)$ is the max flow from node $u$ to node $v$.

- The maximinimax flow in the graph after $x$ edge augmentations is the largest possible minimax flow which the graph can have after $x$ optimal edge augmentations are applied. Note that each edge can be augmented any non-negative number of times (as long as the total number of augmentations in the graph is $x$), and that the chosen edge augmentations are temporary — they do not change the graph for future operations.

To reduce the size of the output, you should simply output one integer, the sum of the answers to all of the queries.

## Input

Input begins with an integer $T$, the number of graphs.  
For each graph, there is a first a line containing the space-separated integers $N$ and $M$.  
Then, $N$ lines follow, the $i$-th of which contains the space-separated integers $A_i$, $B_i$, and $C_i$.  
Then, $M$ lines follow, the $i$-th of which contains the space-separated integers $O_i$, $X_i$, and $Y_i$ (if $O_i = 1$) or $O_i$ and $Z_i$ (if $O_i = 2$).
