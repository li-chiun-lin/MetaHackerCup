# Problem

Ethan is doing his second programming assignment: implementing pre-order tree traversal.

Ethan has a binary tree with $N$ nodes (numbered $1$ to $N$), rooted at node $1$. Each node $i$'s left child is node $A_i$ (with $A_i = 0$ indicating no left child), and similarly its right child is $B_i$ (with $B_i = 0$ indicating no right child). Each node $i$ is also assigned an integral label $L_i$.

Given such a tree, Ethan must compute its pre-order traversal (expressed as a sequence of node labels). The pre-order traversal of a tree involves taking its root node, then concatenating the pre-order traversal of the root's left sub-tree (if any), and then concatenating the pre-order traversal of the root's right sub-tree (if any).

Ethan has attempted to solve this problem, but unfortunately he got his computer science terms mixed up, and now his algorithm finds the tree's post-order traversal instead! The post-order traversal of a tree involves taking the post-order traversal of the root's left sub-tree (if any), and then concatenating the post-order traversal of the root's right sub-tree (if any), and finally concatenating the root node at the end.

Since you were mean to Ethan on his first assignment, you'd like to cheer him up by making his algorithm work out after all. Though the tree's shape must stay as is, you can choose a set of labels $L_{1..N}$ for its nodes such that Ethan's algorithm will still produce the correct answer — in other words, such that the sequence of node labels in the tree's pre-order traversal is equal to the sequence of node labels in its post-order traversal. Your only two restrictions are that each node label must be between $1$ and $K$ (inclusive), and that every integer between $1$ and $K$ (inclusive) must be used as the label of at least one node. You'd like to find any way of validly labelling the nodes, or determine that no way exists.

## Input

Input begins with an integer $T$, the number of trees.  
For each tree, there is first a line containing the space-separated integers $N$ and $K$.  
Then, $N$ lines follow. The $i$-th of these lines contains the space-separated integers $A_i$ and $B_i$.
