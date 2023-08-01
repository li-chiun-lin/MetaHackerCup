# Problem

The final exam is here, and it's now or never for Ethan. His current grade is abysmal so he needs a strong showing on this exam to have any chance of passing his introductory computer science class.

The exam has only one question: devise an algorithm to compute the compactness of a grid tree.

Ethan recalls that a "grid tree" is simply an unweighted tree with $2N$ nodes that you can imagine being embedded within a $2 \times N$ grid. The top row of the grid contains the nodes $1 ... N$ from left to right, and the bottom row of the grid contains the nodes $(N + 1) ... 2N$ from left to right. Every edge in a grid tree connects a pair of nodes which are adjacent in the $2 \times N$ grid. Two nodes are considered adjacent if either they're in the same column, or they're directly side-by-side in the same row. There must be exactly $2N-1$ edges that connect the $2N$ nodes to form a single tree. Additionally, the $i$-th node in the grid tree is labelled with an integer $A_i$.

What was "compactness" again? After some intense thought, Ethan comes up with the following pseudocode to compute the compactness, $c$, of a grid tree:

- Set $c$ to be equal to $0$.
- Iterate $i$ upwards from $1$ to $2N - 1$:
  - Iterate $j$ upwards from $i+1$ to $2N$:
    - Increase $c$ by $A_i \times A_j \times ShortestDistance(i, j)$
- Output $c$.

$ShortestDistance(i, j)$ is a function which returns the number of edges on the shortest path from node $i$ to node $j$ in the tree, which Ethan has implemented correctly. In fact, his whole algorithm is quite correct for once. This is exactly how you compute compactness!

There's just one issue — in his code, Ethan has chosen to store $c$ using a rather small integer type, which is at risk of overflowing if $c$ becomes too large!

Ethan is so close! Feeling sorry for him, you'd like to make some last-minute changes to the tree in order to minimize the final value of $c$, and thus minimize the probability that it will overflow in Ethan's program and cost him much-needed marks. You can't change any of the node labels $A_{1..2N}$, but you may choose your own set of $2N - 1$ edges to connect them into a grid tree.

You'd like to determine the minimum possible compactness which Ethan's program can produce given a valid tree of your choice.

## Input

Input begins with an integer $T$, the number of trees. For each tree, there are three lines.  
The first line contains the single integer $N$.  
The second line contains the $N$ space-separated integers $A_{1..N}$.  
The third line contains the $N$ space-separated integers $A_{N+1..2N}$.
