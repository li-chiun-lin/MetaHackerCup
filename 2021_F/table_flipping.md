# Problem

Tabitha is tired of tricky Hacker Cup problems, and is hosting a table flipping after-party for the finalists to let out some steam. Her party will be held with finalists distributed across $T$ rooms.

A given room has $N$ tables, with one finalist at each table. Each table $i$ is represented as an axis-aligned rectangle of positive area on a 2D plane, with bottom-left vertex at $(X_i,Y_i)$, a width of $W_i$​, and a height of $H_i$​. No two tables overlap (intersect with positive area).

Finalists will take turns flipping their tables in one of the 4 cardinal directions by reflecting the rectangle across an edge. Table $i$ must be flipped in direction $D_i$​ ("U" if the table is to be flipped over its upper edge, "D" for its lower edge, "L" for its left edge, or "R" for its right edge). Finalists must flip their tables one-by-one, i.e., no two tables may be flipped at the exact same time.

Every finalist knows which direction each table must be flipped, and do not wish to interfere with each other. Tabitha would like to know if there exists some permutation in which the tables can be flipped, such that at no time do any two tables overlap (intersect with positive area).

## Input

Input begins with a single integer $T$, the number of rooms.  
For each room, there is first a line containing a single integer $N$.  
Then, $N$ lines follow, the $i$-th of which contains 4 space-separated integers, $X_i​, Y_i​, W_i​,$ and $H_i$​, followed by a space-separated character $D_i$​.
