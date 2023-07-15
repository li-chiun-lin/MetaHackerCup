# Problem

The starship Enterprise, bravely captained by Jean-Luc Picard, is on yet another mission to explore strange new worlds, seek out new life and new civilizations, and boldly go where no one has gone before! Equipped with a state-of-the-art warp drive capable of attaining warp factor $11$ and revising the Enterprise's space-time coordinates almost at will (even sending the ship back in time), not much can stand in the explorers' way. Though, they are low on medical supplies, so they will need to first stock up on neurozine gas for anesthetic purposes.

The Enterprise is heading to the Alpha Omicron solar system, which consists of $N$ planets, numbered from $1$ to $N$. It also features $M$ space conduits, the $i$-th of which allows the Enterprise to travel in either direction between two different planets $A_i$ and $B_i$. No two conduits directly link the same unordered pair of planets, and each planet is reachable from each other planet by following a sequence of conduits.

There's a geyser capable of emitting neurozine located on each planet, though all $N$ geysers are initially inactive. A sequence of $K$ events will then take place, one per hour. The event at hour $i$ is described by integers $E_i$ and $V_i$, with $E_i$ indicating the event's type, which is one of the following:

- $E_i = 1$: The $V_i$-th conduit $(1 ≤ V_i ≤ M)$ collapses, and can no longer be used from that moment onwards. Each conduit collapses at most once.
- $E_i = 2$: The geyser on planet $V_i$ $(1 ≤ V_i ≤ N)$ activates, and begins emitting neurozine. Each geyser is activated at most once.
- $E_i = 3$: The geyser on planet $V_i$ $(1 ≤ V_i ≤ N)$ deactivates, and no longer emits neurozine from that moment onwards. Each geyser is deactivated at most once, and is guaranteed to not be deactivated before it has been activated.

The Enterprise will arrive in the Alpha Omicron system at some planet $x$ and just before some hour $y$. When the starship is currently at a certain planet (and a certain time), Captain Picard may issue any of the following commands to his crew:

- Remain at that planet and wait until any future time.
- Travel through an uncollapsed space conduit directly from that planet to another one. Thanks to warp technology, this may be done instantly.
- Collect neurozine from that planet's geyser, if it's currently active. This may be done instantly.
- Remain at that planet while travelling backwards to any past time which is at most $24$ hours earlier than the Enterprise's original arrival time in the solar system (in other words, the Enterprise may end up just before hour $(y - 24)$, but no earlier). However, this may only be done at most once. The Enterprise retains any neurozine that it had collected before this "temporal revision".

Picard wants his crew to collect neurozine from as many different geysers as possible; there's no additional value in collecting neurozine from any given geyser multiple times, including both before and after travelling back in time. However, Picard hasn't yet decided where and when the Enterprise should arrive in the Alpha Omicron system. He has $S$ such possible starting situations in mind, the $i$-th of which would have the Enterprise arrive at planet $X_i$ just before hour $Y_i$. For each hypothetical starting situation, please help Picard determine the maximum number of different geysers from which the Enterprise could then proceed to collect neurozine!

Letting $ans_i$ be the answer for the ith starting situation, you must output the sum of $ans_{1..S}$ in order to minimize the size of the output. Please note that this sum may not fit within a 32-bit integer.

The starting situations must be considered one after another. In order to enforce this, rather than being given $X_{1..S}$ and $Y_{1..S}$ explicitly, you must compute them based on given values $X'_{1..S}$ and $Y'_{1..S}$. For the first starting situation, $X_1 = X'_1$ and $Y_1 = Y'_1$, while for each subsequent starting situation $i$ $(2 ≤ i ≤ S)$, $X_i = X'_i \oplus ans_{i-1}$ and $Y_i = Y'_i \oplus ans_{i-1}$ (where $\oplus$ is the bitwise xor operator, "^" in most programming languages).

## Input

Input begins with an integer $T$, the number of missions.  
For each mission, there is first a line containing the space-separated integers $N, M, K$ and $S$.  
Then, $M$ lines follow, the $i$-th of which contains the space-separated integers $A_i$ and $B_i$.  
Then, $K$ lines follow, the $i$-th of which contains the space-separated integers $E_i$ and $V_i$.  
Then, $S$ lines follow, the $i$-th of which contains the space-separated integers $X'_i$ and $Y'_i$.
