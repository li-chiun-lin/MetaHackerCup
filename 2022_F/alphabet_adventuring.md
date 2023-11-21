# Problem

Alphonse is assembling an alphabet tree and arranging some adventures along the way.
An alphabet tree is an unrooted tree with $N$ nodes (numbered from $1$ to $N$) and $N−1$ edges. Initially, the $i$-th edge connects nodes $A_i$​ and $B_i$​ in both directions, and is labeled with a uppercase letter $C_i$​. Two edges incident to a common node are always labeled with different letters.

Alphonse has $Q$ events to process, the $i$-th of which is one of two types:

- $1$ $U_i$​ $L_i$​: Add a new node to the tree by connecting it to node $U_i$​ with a new edge labeled with uppercase letter $L_i$​. Newly added nodes are numbered with integers starting from $N+1$ in the order they're added.
- $2$ $U_i$​ $K_i$​ $S_i$​: Print the final node Alphonse will end up at if he:
  - Starts a journey at node $U_i$​.
  - Repeatedly traverses a previously untraversed edge (on this journey). If his current node has multiple untraversed edges, he picks the edge labeled with the letter that comes earliest in the string $S_i$.
  - Ends the journey once there are no more untraversed edges at the current node, or $K_i$​ edges have been traversed on the journey.

Please help Alphonse determine where each journey will take him.

## Input

Input begins with a single integer $T$, the number of test cases.  
For each test case, there is first a line containing a single integer $N$.  
Then, $N−1$ lines follow, the $i$-th of which contains space-separated integers $A_i$​ and $B_i$​, followed by a space, followed by $C_i$​.  
Then, there is a line containing the single integer $Q$.  
Then, $Q$ lines follow, the $i$-th of which is either $1$ $U_i$​ $L_i$​ or $2$ $U_i$​ $K_i$​ $S_i$​.
