# Problem

As captain of a pirate ship, you just made a big score. To lay low, you had the treasure spread out and buried across $N$ different islands (numbered from $1$ to $N$). Island $i$ has $A_i$​ units of treasure.
The islands are connected by $N−1$ unidirectional rivers. The $i$-th river flows between island $U_i$​ and island $V_i$​. The rivers always flow in such a way to ensure that island $1$ is the furthest upstream, and that you can reach any other island from island $1$ by some sequence of rivers.
The dust has now settled, and you get first dibs as the captain. You'll be making one trip to collect your cut of the loot (leaving the rest for your crew). Due to turbulent waters, you'd like to minimize the flow you face by letting the rapids carry your ship downstream from some starting island $S$.
At each island, you can choose whether to stop and collect all the treasure there. Then, your ship will be carried along an adjacent downstream river, taking you to the next island. You have no control over which river you'll be taken. Your trip ends when there are no more rivers downstream.
To avoid capture by the law, you're considering stopping at at most $K$ islands as a precaution. Let $F(S,K)$ be the minimum guaranteed cut of the treasure you can collect, if you start on island $S$, optimally choose whether to stop at each island, and can stop at at most $K$ islands.
Please output the sum of $F(S,K)$ for $S=1..N$ and $K=1..M$, modulo $998,244,353$.

## Input Format

Input begins with an integer $T$, the number of test cases.
The first line of each case contains the integers $N$ and $M$.
The second line contains the $N$ integers $A_1$​ through $A_N$​.
Then $N−1$ lines follow, the $i$-th of which contains the integers $U_i$​ and $V_i$​.
