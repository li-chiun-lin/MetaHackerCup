# Problem

Cherry the turtle lives in a long, narrow pond. When cross-sectionally viewed from the side, the floor of the pond can be divided into $N$ columns, each flat and 1 metre wide. The $i$-th column from the left is at a depth of $D_i$​ metres below ground level, and all $N$ column depths are distinct. The pond is surrounded by dirt (at ground level), just to the left of column 1 and the right of column $N$. Cherry loves to sit on the floor in the leftmost column and bask as much as possible — but only when it's dry. Fortunately for her, the pond is initially devoid of water.

Unusually enormous drops of rainwater are about to begin falling into the pond, one by one, each onto a random column (drawn uniformly at random from the set of $N$ columns). Each drop contains 1 cross-sectional square metre of water, and obeys the following process:

1. It falls until it hits a flat surface. This surface consists of the highest (least deep) point in its column (which might be either the floor of the pond itself or an existing layer of water atop it), as well as all contiguous equally-deep points to the left and right of it.
1. If that surface is immediately surrounded by any deeper columns to its left and/or right, then the drop's water flows down onto one of them. If there's only one such adjacent deeper column, then the drop flows onto that one. If the columns to the left and right are both deeper than the surface (note that this can only occur if the surface consists of a single column), then the drop's water all flows to the left one. Either way, once the drop flows into a different column, the process repeats back from Step 1.
1. Otherwise, the drop's 1 cross-sectional square metre of water spreads itself out evenly across the entire surface it landed on (which will never cause that surface to "overflow" by becoming strictly higher than the columns to its left or right).

Cherry will be forced to stop basking as soon as a non-zero amount of water comes to rest atop column 1. She doesn't mind if raindrops fall directly on column 1 but then immediately flow away from it.

Determine the expected number of drops which will fall before Cherry is forced to stop basking. This will always occur after a finite number of drops have fallen, and before any water overflows the pond.

Let this expected number of drops be represented as a quotient of integers $p/q$ in lowest terms. Output the value of this quotient modulo $10^9+7$ — in other words, output the unique integer $x$ such that $0≤x<10^9+7$ and $p≡x∗q  \mod 10^9 + 7$.

## Input

Input begins with an integer $T$, the number of ponds.  
For each pond, there are 2 lines.  
The first line contains a single integer $N$.  
The second line contains the $N$ space-separated integers $D_{1..N}$​.
