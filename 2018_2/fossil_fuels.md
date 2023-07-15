# Problem

The Earth is gripped by an energy crisis. There's simply not enough to go around! Desperate to unlock additional sources of energy, James has decided to direct his attention downwards. Perhaps enough fossils can be found underground and harvested for just a bit more fuel?

James has surveyed a linear stretch of ground, and has fortunately discovered $N$ fossils beneath the surface! From a cross-sectional view, the $i$-th fossil is at position $P_i$ metres along the stretch of ground, at a depth of $D_i$ metres below the surface. No two fossils are in exactly the same spot (at both the same position and depth).

The next question is, of course, how the fossils might be unearthed most efficiently. James plans to dig one or more vertical mine shafts in order to access all $N$ fossils. A mine shaft is defined by a position $p$ and a depth $d$. Such a mine shaft can be represented as a vertical line segment at position $p$ metres along the stretch of ground, running from the surface to a point $d$ metres below the surface. James can dig such a shaft at a cost of $S + d$ dollars, where $S$ is a constant. Once it has been dug, it's possible to reach fossils from the shaft by descending to the correct depth and then digging horizontally through the earth at no additional cost, up to a distance of at most $M$ metres away from the shaft, where $M$ is another constant. In other words, each fossil $i$ is accessible from the shaft if $_D_i ≤ d$ and $|P_i - p| ≤ M$. Note that a mine shaft is permitted to pass directly through a fossil (such that $p = P_i$ for some $i$).

Help James determine the minimum total cost of mine shafts which he must dig, such that each of the $N$ fossils will end up being accessible from at least one of the shafts.

In order to reduce the size of the input data, the sequences $P_{1..N}$ and $D_{1..N}$ will be derived from a series of temporary sequences $A_{1..(2K)}$, the $i$-th of of which has a length of $L_i$. $P_{1..N}$ can be constructed by concatenating together $A_{1..K}$, while $D_{1..N}$ can be constructed by concatenating together $A_{(K+1)..(2K)}$. It's guaranteed that the sum of $L_{1..K}$ is equal to $N$, as is the sum of $L_{(K+1)..(2K)}$. For each sequence $A_i$, you're given $A_{i,1}$, and $A_{i,2..L_i}$ may then be generated as follows using given constants $X_i$, $Y_i$, and $Z_i$ (please watch out for integer overflow during this process):

$A_{i,j} = ((X_i \times A_{i,j-1} + Y_i) \mod Z_i) + 1$ (for $j = 2..L_i$)

## Input

Input begins with an integer $T$, the number of sets of fossils.  
For each set of fossils, there is first a line containing the space-separated integers $N, S, M,$ and $K$.  
Then, $2K$ lines follow. The $i$-th of these contains the space-separated integers $L_i, A_{i,1}, X_i, Y_i,$ and $Z_i$.
