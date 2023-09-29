# Problem

You're playing a video game that features $N$ different areas, numbered from $1$ to $N$. There are $M$ one-way paths that each connect two areas. The $i$-th path runs from area $A_i$ to a different area $B_i$. No pair of paths directly connect the same pair of areas, and for every area it's impossible to start at that area and follow a non-empty sequence of paths to return to that area. In other words, the game's layout is a directed acyclic graph.

You start in area $1$. $K$ other distinct areas each contain an item to collect — the $i$-th of these is area $I_i$. As soon as you've visited these $K$ areas at least once each, you win! You'd like to do so as fast as possible.

At any point in time, if there are no outgoing paths leading away from your current area, you automatically respawn in area $1$ after a delay of $R$ seconds. Otherwise, you get to choose one such path and attempt to follow it. Unfortunately, this game relies entirely on Random Number Generation to determine whether or not you'll be successful, regardless of your skill. In particular, with probability $P$, you'll successfully travel along your chosen path for $D$ seconds, ending up in a new area. On the other hand, with probability $1 - P$, you'll instead perish and respawn in area $1$ after a delay of $R$ seconds.

What's the minimum expected time for you to collect all $K$ items, given that you play optimally? This is guaranteed to be possible — that is, all $K$ areas that contain items are reachable from area $1$. Your output should have at most $10^{-6}$ absolute or relative error.

## Input

Input begins with an integer $T$, the number of times you play the game.  
For each time, there is first a line containing the space-separated integers $N$, $M$, and $K$.  
The second line contains the space-separated integers $D$ and $R$.  
The third line contains the real value $P$ which is given with at most 4 decimal places.  
The fourth line contains the $K$ space-separated integers $I_1$ to $I_K$.  
Then, $M$ lines follow, the $i$-th of which contains the space-separated integers $A_i$ and $B_i$.
