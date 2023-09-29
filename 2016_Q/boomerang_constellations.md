# Problem

The night sky can be modeled as an infinite 2D plane. There are $N$ stars at distinct positions on this plane, the $i$-th of which is at coordinates $(X_i, Y_i)$.

A boomerang constellation is a pair of distinct equal-length line segments which share a single endpoint, such that both endpoints of each segment coincide with a star's location.

Two boomerang constellations are distinct if they're not made up of the same unordered pair of line segments. How many distinct boomerang constellations can you spot?

## Input

Input begins with an integer $T$, the number of nights on which you look out at the sky.  
For each night, there is first a line containing the integer $N$.  
Then, $N$ lines follow, the $i$-th of which contains the space-separated integers $X_i$ and $Y_i$.
