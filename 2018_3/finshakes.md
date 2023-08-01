# Problem

You know what a finshake is, right? It's just like a handshake. Except performed by fish rather than humans.

There are $N$ pools of water in a row, numbered from $1$ to $N$ in order. Pool $i$'s water level is at an elevation of $H_i$ metres. There are $N - 1$ equally-tall walls, one between each pair of adjacent pools, with the top of each wall at an elevation of $W$ metres. All of the water levels are lower than the tops of the walls (in other words, $H_i < W$ for each $i$).

There are also $M$ fish throughout the pools. The $i$-th fish initially lives in pool $P_i$, and has a jumping height of $J_i$ metres. It can jump over a wall from any given pool $a$ to an adjacent pool $b$ (such that $|a - b| = 1$) if and only if $J_i > W - H_a$. Multiple fish may live in the same pool.

Each of the $M$ fish will spend some time jumping over walls amongst the pools, before each choosing a final pool to settle in. After all of the fish have settled down, for each unique unordered pair of fish who have ended up in the same pool as one another, they will give each other a finshake. Assuming the fish all work together, what's the maximum number of finshakes which can occur once they've all settled down in their chosen pools?

## Input

Input begins with an integer $T$, the number of rows of pools.  
For each row of pools, there is first a line containing the space-separated integers $N$, $M$, and $W$.  
Then follows a line containing the $N$ space-separated integers $H_1$ through $H_N$.  
Then $M$ lines follow, the $i$-th of which contains the space-separated integers $P_i$ and $J_i$.
