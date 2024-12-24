# Problem

As chef de cuisine of Snacker Cup, you've been tasked to create the perfect chicken tender. Of course, a perfect tender is one that fits all the way into a BBQ sauce cup. You just made a chicken tender in the shape of a convex polygon with $N$ vertices $(x_1,y_1),...,(x_N,y_N)$. Can you rotate the tender so that it can reach the bottom of a sauce cup of width $W$ and depth $D$?

Formally, the sauce cup is an open-topped rectangle made of three line segments connecting the points $(0,D)$, $(0,0)$, $(W,0)$, and $(W,D)$ in order. Is there some way to rotate and translate the given polygon such that:

- All vertices of the polygon lie on or above the $x$-axis,
- some vertex of the polygon lies on the $x$-axis between $x=0$ and $x=W$ (inclusive),
- some point of the polygon lies strictly within the bounds of the sauce cup, and
- no point on the sauce cup lies strictly within the bounds of the polygon.

However, no matter how you rotate the second tender, it'll never reach the bottom of the cup.

## Input Format

Input begins with an integer $T$, the number of test cases.
The first line of each case contains the integers $N$, $W$, and $D$.
Then, $N$ lines follow, the $i$-th of which contains the integers $x_i$​ and $y_i$​.

Vertices are given in counter-clockwise order, and all vertices lie on the convex hull of the polygon. No three vertices are collinear.
