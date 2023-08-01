# Problem

What day is it today? Wasn't there something you were supposed to remember? Eh, it was probably nothing...

...

Wait! Oh no! It's your anniversary today! And you don't have a gift for your spouse!

Only one thing can save you now: online shopping. Logging onto your favourite shopping site, the top automated suggestion looks perfect (or at least passable) — a graph. Your spouse probably loves graphs, right? More importantly, it can be delivered directly to your house within half an hour.

The graph comes with $N$ nodes, the $i$-th of which is labelled with a non-zero integer $L_i$. Unfortunately, no edges are included by default — you have to pay extra for those. You'd better purchase one or more edges so that it looks like you put extensive thought into your gift. Purchasing an undirected edge between two different nodes $i$ and $j$ costs $L_i \times L_j$ dollars (note that this cost may be negative, in which case you actually receive money for "purchasing" that edge). You won't purchase more than one edge between any unordered pair of nodes, and you won't purchase any self-loops (edges connecting a node directly to itself).

In order to make the graph appealing to your spouse, you've decided that it should have the following two properties:

- Each node should be adjacent to at least one other node.
- Each node with a positive label should be adjacent to at most one node with a negative label.

Any such graph should make a fine gift, so... you might as well go with the cheapest option, right? You'd like to determine the minimum possible total cost of edges to purchase which result in a graph with both properties described above. Note that this total "cost" may be negative.

## Input

Input begins with an integer $T$, the number of test cases.  
For each test case, there is first a line containing the integer $N$.  
Then one more line follows containing the $N$ space-separated integers $L_1$ through $L_N$.
