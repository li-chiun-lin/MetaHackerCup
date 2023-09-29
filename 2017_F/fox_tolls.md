# Problem

A group of $N$ Foxen reside in a peaceful forest community. Each Fox's property consists of a tree stump as well as an underground den. There are $N - 1$ two-way paths on the ground running amongst the tree stumps, with the $i$-th path connecting the stumps belonging to two different Foxen $A_i$ and $B_i$, such that all $N$ stumps can be reached from one another by following a sequence of paths. Similarly, there are $N - 1$ underground tunnels running amongst the dens, with the $i$-th tunnel connecting the dens belonging to Foxen $C_i$ and $D_i$, such that all $N$ dens can be reached from one another. There's additionally a passageway connecting the tree stump and den belonging to the $1$-st Fox, which is the only way in the whole forest to get underground from the surface and vice versa.

At night the Foxen sleep in their dens, but during the daytime, they like to emerge and relax lazily on their tree stumps. Each day, every Fox takes a trip from their den to their tree stump, taking the unique shortest path through the system of tunnels and paths to get there. However, this often requires passing through other Foxen's properties, which they don't appreciate a whole lot. To compensate, the Foxen have started charging each other tolls for said passage. They don't have much of a currency, but Foxen do love crackers, so those will do. Over a given period of $M$ days, on the $i$-th day, two different Foxen $W_i$ and $X_i$ will each charge tolls for one of their pieces of property. If $Y_i =$ "T", then Fox $W_i$ will be charging tolls for passage through their tree stump. Otherwise, if $Y_i =$ "D", then Fox $W_i$ will instead be charging tolls for passage through their den. Similarly, Fox $X_i$ will be charging tolls for passage through either their tree stump (if $Z_i=$ "T") or their den (if $Z_i=$ "D").

Each day, whenever a Fox passes through another Fox's den or stump which is subject to tolls on that day, they'll normally need to pay up with 2 crackers. However, if they've already paid a toll earlier on that same trip, then the property-owning Fox will take pity and only charge them 1 cracker instead of 2. As such, a Fox's daily trip may end up costing them at most 3 crackers. A Fox will never charge themselves a toll, of course. If a pair of Foxen both owe each other crackers, they'll still both pay up as normal, rather than attempting to minimize the number of cracker transactions performed.

The Foxen are having some trouble keeping track of how many crackers they owe one another. On each of the $M$ days, they'd like to count up the total number of crackers which will be charged as part of the tolls for the $N$ trips taken on that day. To avoid dealing with too many large numbers, they'd like to combine these $M$ cracker counts into a single value as follows (where $V_i$ is the $i$-th day's count):

$( ... (((V_1 \times 12,345) + V_2) \times 12,345 + V_3) ... \times 12,345 + V_M) \mod 1,000,000,007$

Please help the Foxen compute this combined value!

## Input

Input begins with an integer $T$, the number of different communities of Foxen.  
For each community of Foxen, there is first a line containing the space-separated integers $N$ and $M$.  
Then $N - 1$ lines follow, the $i$-th of which contains the space-separated integers $A_i$ and $B_i$.  
Then $N - 1$ lines follow, the $i$-th of which contains the space-separated integers $C_i$ and $D_i$.  
Then $M$ lines follow, the $i$-th of which contains the integers $W_i$ and $X_i$ and the characters $Y_i$ and $Z_i$, all separated by spaces.
