# Problem

Boss Rob planted $N$ happy little hazel trees in his yard (represented on a Cartesian plane). The $i$-th tree is at integer coordinates $(X_i,Y_i)$. It's harvesting season, and Rob would like to set up some nets around the trees to collect the hazelnuts that fall.

Each net must be an axis-aligned rectangle with integer vertices (on lattice points). Rob needs at least $11$ unit of space between nets so he can walk between them and collect the nuts. That is, nets cannot intersect, touch, or be nested. Each tree must lie strictly inside its net, i.e. must be at least $11$ unit away from the net's edge.

Boss Rob can set up any number of nets, but would like to know the minimum total area of net required to cover all $N$ trees.

## Input

Input begins with an integer $T$, the number of cases.  
For each case, there is first a line containing a single integer $N$.  
Then, $N$ lines follow, the $i$-th of which contains two space-separated integers $X_i$​ and $Y_i$​.
