# Problem

The great Canadian log drive is coming to an end, for this season at least. Next year, a new crop of log driving hopefuls will compete for their own spot on the river.

As every Canadian knows, to stay afloat in the forestry industry's competitive job market, you need to familiarize yourself with all kinds of trees. Hoping to land her dream log driving job, Louise was researching online when she stumbled upon an article about binary search trees (BSTs). Determined to become a true expert on all there is to know about trees, she decided to continue reading.

In case you're unfamiliar, Louise learned that a BST is a data structure holding nodes that each store a key (in this case, a non-negative integer). A BST may be empty (that is, holding no nodes), or otherwise consists of a root node that is optionally connected by edges to left and/or right child nodes (which are themselves each the root nodes of "subtree" BSTs, recursively defined in the same fashion). For each node, if its key is $k$, all keys in its left child's subtree (if any) must be less than or equal to $k$, while all keys in its right child's subtree (if any) must be strictly greater than $k$. The height of a non-empty BST is defined as the number of edges on the longest path from its root node to any other node (or 0 if there are no other nodes).

In practice, BSTs start out empty and are constructed by having nodes inserted into them, one by one. When inserting a new key $k$ into an existing BST, one compares the root node with $k$:

- If the root node doesn't exist, then a node with key $k$ is created in its place and the insertion is complete.
- Otherwise, if $k$ is less than or equal to the root node's key, then $k$ is recursively inserted into the left subtree.
- Otherwise, $k$ must be greater than the root node's key, in which case it is recursively inserted into the right subtree.

Intrigued, Louise borrowed a data structures textbook from her local library. Upon flipping to the chapter on BSTs, she came upon the following exercise:

    Given a length-$N$ string $S$ in which each character is either "0" or "*", please answer the following question for each of the $N∗(N+1)/2$ non-empty substrings of $S$.

    For a given substring of length $x$, choose a sequence $K_{1..x}$​ of integer keys. If the substring's $i$-th character is "0", then $K_i=0$. Otherwise, if it's "*", then $K_i$​ may be chosen to be any positive integer. Suppose the chosen sequence was inserted into an initially empty BST, in order from $K_1$​ to $K_x$​. What is the minimum possible height of the resulting BST?

For example, if $S$ = "0\*\*0\*0\*\*", then one of the $8*9/2 = 36$ substrings for which the above question must be answered is "\*\*0\*0\*". For this substring, one possible choice of $K_{1..6}$​ would be $[3,6,0,5,0,3]$, yielding a BST of height 2 (as illustrated above). This is the minimum height that a BST could have for any possible choice of $K_{1..6}$​ for this substring, meaning that 2 is the answer to the question for this substring.

Louise would like your help with computing the sum of the answers to all $N∗(N+1)/2$ of these questions. As this sum may be large, you should only compute its value modulo $10^9+7$. Please help her complete this exercise — the fate of her log driving career rests in your hands!

## Input

Input begins with an integer $T$, the number of exercises.  
For each exercise there is a single line consisting of the string $S_{1..N}$​ as specified above.
