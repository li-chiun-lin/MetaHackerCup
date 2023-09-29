# Problem

This weekend, the long-awaited BIT (Boomerang Invitational Tournament) will be taking place! $N$ of the finest boomerangists will be competing in a randomly-seeded single-elimination bracket.

For those unfamiliar with this tournament format, the process can be modelled as follows:

1. The $N$ competitors are arranged in a queue (an ordered list), in some order
1. If the queue currently contains only 1 competitor, the tournament ends with them as the champion
1. Otherwise, the first 2 competitors in the front of the queue are removed, and they play a match against one another
1. The winner of that match is re-inserted into the queue, at the back
1. Repeat from step 2

The one-on-one matches in this tournament are, of course, boomerang duels to the death. If the $i$-th and $j$-th competitors face off against one another, the $i$-th competitor will win if $W_{i,j} = 1$. Otherwise, if $W_{i,j} = 0$, the $j$-th competitor will win. Note that, for all $(1 ≤ i, j ≤ N), W_{i,j} = 0$ or $1$, and $W_{i,i} = 0$ (no one will play against themselves anyway), and $W_{i,j} ≠ W_{j,i}$ (if $i ≠ j$). Those are the only constraints. It's possible that, for example, competitor $A$ can beat $B$, $B$ can beat $C$, and $C$ can beat $A$.

Once the tournament is over, each boomerangist is given a placing (even if they didn't survive the competition). A given competitor $c$'s placing is an integer one greater than the number of competitors who won strictly more matches than $c$ did.

For each boomerangist, you'd like to know both the best (smallest) and the worst (largest) placing they could possibly end up with, given that the initial ordering of the competitors (in step 1 of the tournament) is unknown.

## Input

Input begins with an integer $T$, the number of tournaments.  
For each tournament, there is first a line containing the integer $N$.  
Then follow $N$ lines, the $i$-th of which contains the space-separated integers $W_{i,1}$ through $W_{i,N}$.
