# Problem

Cyrus has come across a curious sight — an undirected, weighted graph with $N∗M$ nodes and $N∗M+N$ edges. Each edge initially has a weight of $1$.

What makes this graph so curious is its shape. The nodes are arranged in $N$ "circles" of $M$ nodes each. Nodes $0..(M−1)$ are in the first circle, nodes $M..(2∗M−1)$ are in the second, and so on. In each circle, the nodes are arranged in clockwise order (ordered by increasing node number).

The first $N∗M$ edges lie within circles, with $M$ edges per circle. Edges $0..(M−1)$ lie within the first circle, edges $M..(2∗M−1)$ lie within the second, and so on. In each circle, its first (lowest-numbered) edge connects the circle's first and second nodes, its second edge connects its second and third nodes, and so on, with its final edge connecting its final and first nodes.

There are $N$ more edges (edges $(N∗M)..(N∗M+N−1)$) connecting the $N$ circles into what might be considered an additional circle. Each circle $i$ has two "connection points", the first of which is its $(X_i+1)$-st node (that is, node $M∗i+X_i$​), and the second of which is its $(Y_i+1)$-st node (node $M∗i+Y_i$​). $X_i$​ and $Y_i$​ are not necessarily distinct. The $i$-th of the NN final edges connects the second connection point of circle $i$ and the first connection point of circle ($(i+1) \mod N)$). That is, there's an edge between nodes $M∗0+Y_0$​ and $M∗1+X_1$​, another between $M∗1+Y_1$​ and $M∗2+X_2$​, and so on, with the final edge connecting nodes $M∗(N−1)+Y_{N−1}$​ and $M∗0+X_0$​.

Cyrus was hoping to practice computing the minimum spanning tree of this graph, but it's starting to change before his very eyes! $E$ events are about to occur on the graph, one after another. Event $i$ will cause the weight of edge $I_i$​ to become $W_i$​. When an edge's weight changes, it will remain at its new value for future events (until changed again).

Let $V_i$​ be the weight of the graph's minimum spanning tree after the first $i$ events. Help Cyrus compute the product of $V_{1..E}$​. As this product may be very large, you should only compute its value modulo $10^9+7$.

In order to reduce the size of the input, the above values will not all be provided explicitly. Instead, you'll be given the first $K$ values $X_{0..(K−1)}​, Y_{0..(K−1)}​, I_{0..(K−1)}​,$ and $W_{0..(K−1)}$​, as well as the four triples of constants $(A_X,B_X,C_X), (A_Y,B_Y,C_Y), (A_I,B_I,C_I),$ and $(A_W,B_W,C_W)$, and must then compute $X_{K..(N−1)}​, Y_{K..(N−1)}​, I_{K..(E−1)}​,$ and $W_{K..(E−1)}$​ as follows:

$X_i=(A_X∗X_{i−2}+B_X∗X_{i−1}+C_X) \mod M$ for $i≥K$  
$Y_i=(A_Y∗Y_{i−2}+B_Y∗Y_{i−1}+C_Y) \mod M$ for $i≥K$  
$I_i=(A_I∗I_{i−2}+B_I∗I_{i−1}+C_I) \mod (N∗M+N)$ for $i≥K$  
$W_i=(A_W∗W_{i−2}+B_W∗W_{i−1}+C_W) \mod (10^9+7)$ for $i≥K$

## Input

Input begins with an integer $T$, the number of graphs. For each graph, there are 9 lines:  
The first line contains the 4 space-separated integers $N, M, E,$ and $K$.  
The second line contains the $K$ space-separated integers $X_{0..K−1}$​.  
The third line contains the 3 space-separated integers $A_X​, B_X​,$ and $C_X$​.  
The fourth line contains the $K$ space-separated integers $Y_{0..K−1}$​.  
The fifth line contains the 3 space-separated integers $A_Y​, B_Y​,$ and $C_Y$​.  
The sixth line contains the $K$ space-separated integers $I_{0..K−1}$​.  
The seventh line contains the 3 space-separated integers $A_I​, B_I​,$ and $C_I$​.  
The eighth line contains the $K$ space-separated integers $W_{0..K−1}$​.  
The ninth line contains the 3 space-separated integers $A_W​, B_W​,$ and $C_W$​.
