# Problem

In their spare time, bunnies enjoy playing their own version of hopscotch on an $R×C$ grid of burrows. The burrow at row $i$ (numbered from $1$ to $R$) and column $j$ (numbered from $1$ to $C$) is denoted as burrow $(i,j)$.

Each burrow $(i,j)$ is owned by some bunny $B_{i,j}$​. Note that multiple burrows may belong to the same bunny, and some bunnies may not own any burrows.

In this game, a hop is only valid if it's between burrows of different owners. Hopping from burrow $(i_1,j_1)$ to burrow $(i_2,j_2)$ earns a score of $\max⁡(∣i_2−i_1∣,∣j_2−j_1∣)$.

Consider all ordered pairs of hops between different-owner burrows. If we sort their scores in non-decreasing order, what is the $K$-th ($1$-indexed) smallest score?

## Input Format

Input begins with an integer $T$, the number of test cases.
Each case starts with a line containing the integers $R$, $C$, and $K$.
Then, $R$ lines follow, the $i$-th of which contains $C$ integers $B_{i,1},...,B_{i,C}$​
