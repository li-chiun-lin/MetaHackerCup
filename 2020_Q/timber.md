# Problem

Every year, millions of logs are sent floating downstream in the great Canadian log drive. But as every Canadian knows, you can't have a successful log drive without logs. The first step in the logging season is to fell a great number of trees, taking care not to pile the trees up in a way that will make them hard to move.

Eva has been assigned a section of forest with $N$ trees standing in a row. Looking at them from the side and modeling the ground as a number line, the $i$-th tree is at position $P_i$​ (measured in metres) and has a height of $H_i$​ metres. All of the trees are at distinct positions.

Each tree may be cut down such that it falls either to the left or to the right, or it may be left standing (it's important to farm trees sustainably). If the $i$-th tree is cut down to the left, it will form a timber interval of $[P_i−H_i,P_i]$ on the ground, while if it is cut down to the right, it will form a timber interval $[P_i,P_i+H_i]$.

The trees that are cut down will be moved into a nearby river to begin their long journey to the mill. It's hard to move a tree that has another tree on top of it, so Eva will not cut down trees in a way that would cause the intersection of any pair of timber intervals to have positive length. It's fine however, and indeed desirable, for two timber intervals to share an endpoint in common. For example, one tree may be cut down to create a timber interval of $[a,b]$ and another may be cut down to create a timber interval of $[b,c]$. It's also fine for timber intervals to overlap with trees which have not been cut down. Uncut trees are essentially ignored.

A combined timber interval is an interval where each point within it is within at least one timber interval. For example, if you have timber intervals $[a,b]$ and $[b,c]$ (for any $a<b<c$), then $[a,c]$ is a combined timber interval.

Eva would like to form the largest combined timber interval possible, as that represents a series of trees that can all be pushed into the river at once. Determine the maximum possible length that a combined timber interval could have if Eva cuts down trees optimally.

## Input

Input begins with an integer $T$, the number of forest sections that Eva will work in.  
For each section, there is first a line containing the single integer $N$.  
Then, $N$ lines follow, the $i$-th of which contains the space-separated integers $P_i$​ and $H_i$​.
