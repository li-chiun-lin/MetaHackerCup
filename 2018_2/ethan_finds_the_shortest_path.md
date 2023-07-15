# Problem

Ethan is doing his third programming assignment: finding the shortest path between two nodes in a graph.

Given an undirected, weighted graph with $N$ nodes (numbered from $1$ to $N$), having no self-loops or duplicate edges, Ethan must compute the length of the shortest path from node $1$ to node $N$. Ethan has implemented an algorithm to solve this problem, described by the following pseudocode:

1. Set $i$ to be equal to $1$, and $d$ to be equal to $0$
1. If $i$ is equal to $N$, output $d$ and stop
1. Find the edge incident to node $i$ that has the smallest weight (if no edges are incident to $i$ or if there are multiple such edges tied with the smallest weight, then crash instead)
1. Increase $d$ by the weight of this edge, and set $i$ to be equal to the other node incident to this edge
1. Return to Step 2

Since you were nice to Ethan on his second assignment, and since that encouragement clearly hasn't helped improve the quality of his code, you'd like to find a graph that shows as clearly as possible why this solution is incorrect.

You're given the number of nodes in the graph $N$, as well as the maximum allowable edge weight $K$ (each edge's weight must be an integer in the interval $[1, K]$). Under these constraints you want to maximize the absolute difference between Ethan's output and the actual shortest distance between nodes $1$ and $N$. However, you don't want Ethan's algorithm to either crash or run forever. Note that node $N$ must actually be reachable from node $1$ in the graph, though the graph may be otherwise disconnected. You can output any valid graph which gets the job done.

## Input

Input begins with an integer $T$, the number of graphs.  
For each graph, there is a line containing the space-separated integers $N$ and $K$.

## Output

For the $i$-th graph, first output a line containing "Case #$i$: " followed by the maximum possible absolute difference between Ethan's algorithm's output and the correct answer.  
Then, output a line containing as single integer $E$, the number of edges in your chosen graph which yields the above maximum absolute difference.  
Then, output $E$ lines, the $j$-th of which contains three integers $U_j$, $V_j$, and $W_j$ denoting that there is an edge between nodes $U_j$ and $V_j$ with weight $W_j$.

Note that there must be no self-loops (no edge may connect a node to itself), and no two edges may connect the same unordered pair of nodes.
