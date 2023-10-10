# Problem

Mr. Fox is going on a trip to Scotland to witness its many beautiful lochs! He's heard that skimboarding is a fun pastime, somewhat similar to surfing, and he'd like to give it a try while he's there.

He soon finds himself on a flat beach by the side of a loch. The beach can be represented by an infinite 2D plane, with $N$ axis-aligned rectangular pools of shallow water on it. The $i$-th pool has a pair of opposite corners at coordinates $(x_1, y_1)$ and $(x_2, y_2)$. All of the pools can arbitrarily overlap with one another, the result being that there's shallow water everywhere within the union of the pools' rectangles (including right on its edges), and no water anywhere else (Mr. Fox isn't brave enough to venture into the loch itself yet!).

Mr. Fox would like to get a running start and then launch himself across the water at some location, skimboarding across the pools in a straight line until he hits a point with no water. In other words, his skimboarding debut will consist of a line segment contained within the union of the pools' rectangles (inclusive of borders). What's the maximum length this line segment can have?

## Input

Input begins with an integer $T$, the number of places Mr. Fox goes skimboarding.  
For each place, there is first a line containing the integer $N$.  
Then $N$ lines follow, the $i$-th of which contains the space-separated integers $x_1, y_1, x_2,$ and $y_2$.
