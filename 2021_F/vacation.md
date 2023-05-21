# Problem

Melody is planning her Christmas vacation in the Metalverse, an ore-rich VR experience consisting of $T$ virtual worlds.

A given world has $N$ cities with $N−1$ roads running between them. The $i$-th road allows Melody to drive between cities $P_i$​ and $i+1$ in either direction (with $1≤P_i≤i$). City $i$ also contains $C_i$​ ore-naments which Melody can collect as souvenirs while she's there.

Melody's vacation consists of starting in any city of her choice, and then repeatedly performing either of the following actions:

1. Drive along a road to another city, unless her previous action was to drive from that city
1. Teleport to any other city

Melody may visit a city multiple times, but may only collect its ore-naments once. She may stop her vacation at any point.

Please help Melody evaluate, for each world, the minimum number of times she must teleport to collect at least $K$ ore-naments, if it's possible at all.

## Input

Input begins with an integer $T$, the number of virtual worlds to be evaluated.  
For each world, there is first a line containing 2 space-separated integers, $N$ and $K$.  
Then, there is a line containing $N$ space-separated integers, $C_{1..N}$​.  
Then, there is a line containing $N−1$ space-separated integers, $P_{1..(N−1)}$​.
