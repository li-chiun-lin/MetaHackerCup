# Problem

Melody is preparing a cake for a very special occasion. She's starting off with a square cake, though she'd like it cut down into a more unique shape. When viewed from above, it can be represented as a square on a 2D plane, with opposite corners at coordinates $(0,0)$ and $(S,S)$.

Out of countless contenders, Melody has interviewed $N$ certified cake-cutting consultants, asking how the cake should be cut down. The $i$-th consultant, who has a competence value of $C_i$​, has proposed that two cuts should be performed: the first being a line segment between coordinates $(X_{i,1},Y_{i,1})$ and $(X_{i,2},Y_{i,2})$, and the second between $(X_{i,3},Y_{i,3})$ and $(X_{i,4},Y_{i,4})$. Each of these four points is exactly on a side of the cake (but not on a corner), the two points describing each line segment are not on the same side of the cake, and the two line segments do not share any points in common (in other words, they don't intersect nor have any equal endpoints). Therefore, the two cuts would split the cake into three non-empty polygonal sections. Of those, the middle section (the one between the two cuts) would become their proposed cake shape, with the other two sections discarded.

Melody wants to hire one or more of the consultants to form a committee, whose members will then deliberate on the final shape of the cake. That is, she calls for a completely competent consulting committee capable of coming to a consensus on a commendable cake-cutting configuration. Clearly.

She wants the sum of the hired consultants' competence values to be as large as possible, no matter how many of them she has to hire. However, she won't allow a pair of consultants to both be part of the committee if their cake-cutting proposals fundamentally differ, which is the case if their proposed cake shapes do not share any points in common (in other words, if those two polygons are entirely disjoint, including at their edges and vertices).

Help Melody determine the maximum combined competence of consultants who can form the committee, such that no two of them have fundamentally differing cake-cutting proposals.

## Input

Input begins with an integer $T$, the number of special occasions.  
For each occasion, there are $N+1$ lines.  
The first line contains 2 space-separated integers, $S$ and $N$.  
$N$ lines follow, the $i$-th of which contains the 9 space-separated integers $C_i​, X_{i,1}​, Y_{i,1}​, X_{i,2}​, Y_{i,2}​, X_{i,3}​, Y_{i,3}​,$ and $X_{i,4}​, Y_{i,4}$​.
