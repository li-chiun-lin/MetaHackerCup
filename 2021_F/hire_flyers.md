# Problem

The market is hot for geological talent! Hiring agents are competing to display their job flyers on street intersections across $T$ towns.

A town's streets can be represented as an infinite 2D grid with rows numbered by increasing integers from North to South and columns numbered by increasing integers from West to East.

There are $N$ hiring agents. Agent $i$ starts at the intersection of row $R_i$​ and column $C_i$​, holding $P_i$​ flyers, and facing the cardinal direction $D_i$​ ("N" for North, "S" for South, "E" for East, or "W" for West). Each turn taken by an agent consists of the following:

1. Post one of their own flyers at their current intersection, shredding any competing flyer that may have previously been there.
1. If the agent has more flyers, move to the adjacent intersection in direction $D_i$​.

The agents will take turns posting one flyer at a time. Agent $1$ will take a turn, followed by agent $2$, and so on until agent $N$ takes a turn, at which point agent $1$ will go again (if necessary). Note that there may be multiple agents occupying the same intersection at any point in time.

Let $F_i$​ be the number of flyers placed by agent $i$ which remain will unshredded at the end. Your job is to compute the sum of $i∗F_i$​ over all agents $i$. As this sum may be very large, you should only compute it modulo $10^9 + 7$.

## Input

Input begins with an integer $T$, the number of towns.  
For each town, there is first a line containing a single integer $N$.  
Then, $N$ lines follow, the $i$-th of which consists of 3 space-separated integers $R_i​, C_i​,$ and $P_i$, followed by a space-separated character, $D_i$​.
