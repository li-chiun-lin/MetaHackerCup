# Problem

Wilson, everyone's favorite recurring programming contest character, has finally decided that it's time to retire. Why? After several more job changes and miraculous promotions, not only has he become incredibly wealthy, but he's ended up stuck in a boring administrative role, which was the last thing he wanted!

Wilson is currently employed as the head of accounting at a pie delivery company, and has been given one last assignment to complete before his retirement — computing delivery truck gas usage. He wishes he could just drive one of the trucks instead...

The pie delivery company services a network of $N + 1$ towns, which rather looks like a pie itself (or perhaps like an umbrella...). $N$ of the towns form a circle around the outside of the region, and are numbered from $1$ to $N$ in clockwise order. They are connected to one another by $N$ roads, each of which can be driven along in either direction. The $i$-th of these roads requires $O_i$ litres of gas to drive along, and runs between towns $i$ and $i + 1$ (unless $i = N$, in which case it instead runs between towns $N$ and $1$).

The remaining town, numbered $N + 1$, lies in the center of the region. There are $N$ roads connecting it to the other towns, each of which can be driven along in either direction. The $i$-th of these roads requires $R_i$ litres of gas to drive along, and runs between towns $N + 1$ and $i$.

A total of $N \times (N + 1) / 2$ pie deliveries are scheduled to be carried out, one for each distinct pair of towns. In particular, for every town $i$, $i - 1$ deliveries will originate from it, with the $j$-th of them having town $j$ as its destination. The truck drivers will have to pay the gas expenses out of their own pockets, of course, so for each delivery, the truck driver will choose a sequence of roads to follow from the initial town to the destination such that the total amount of gas required for their trip is minimized. Wilson's task is to tally up the total amount of gas which will be used across all $N \times (N + 1) / 2$ of the deliveries. He's been instructed to only determine the value of this sum modulo $1,000,000,007$.

You're given $O_1$, and $O_{2..N}$ may then be calculated as follows using given constants $A_o$, $B_o$, $C_o$, and $D_o$.

$O_i = ((A_o \times O_{i-1} + B_o) \mod C_o + D_o$

You're given $R_1$, and $R_{2..N}$ may then be calculated as follows using given constants $A_r$, $B_r$, $C_r$, and $D_r$.

$R_i = ((A_r \times R_{i-1} + B_r) \mod C_r + D_r$

## Input

Input begins with an integer $T$, the number of different regions of towns.  
For each region, there is first a line containing the integer $N$.  
Then there is a line with five space-separated integers, $O_1, A_o, B_o, C_o,$ and $D_o$.  
Then there is a line with five space-separated integers, $R_1, A_r, B_r, C_r,$ and $D_r$.
