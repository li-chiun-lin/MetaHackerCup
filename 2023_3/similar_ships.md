# Problem

The Flying Dutchman is making a killing giving out haunted house tours of his ghost ship. The ship has $N$ cabins, numbered from $1$ to $N$, connected by corridors in the shape of an unrooted tree $t_1$​. For each $i=2..N$, there is a corridor that connects cabin $i$ to cabin $P_i$​.

Mr. Krabs noticed this business opportunity, and wants to make his own ship, also with $N$ cabins, connected as a yet-to-be-determined tree $t_2$​. To avoid any lawsuits from the Dutchman, he would like to make his ship as different as possible.

In particular, let $S(t)$ be the multiset of all subtrees of tree $t$, where a subtree is any non-empty subset of cabins that are connected. For two multisets of trees $S_1$​ and $S_2$​, let $similarity(S_1,S_2)$ be the number of trees in $S_2$​ that are isomorphic to at least one tree in $S_1$​. Note that $similarity(S_1,S_2)$ and $similarity(S_2,S_1)$ are not necessarily equal.

Help Mr. Krabs find the minimum possible value of $similarity(S(t_1),S(t_2))$ over all trees $t_2$​ of size $N$. As this value may be large, output it modulo $1,000,000,007$.

## Input Format

Input begins with an integer $T$, the number of test cases. Each case has two lines. The first contains the integer $N$, and the second contains the $N−1$ integers $P_2$​ through $P_N$​.
