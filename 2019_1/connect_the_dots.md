# Problem

There are $N$ dots on a 2D grid, the $i$-th of which is a point at coordinates $(X_i, Y_i)$. All coordinates are positive integers, and all $N$ dots' positions are distinct.

You'd like to draw $N$ line segments, each of which is either horizontal or vertical, to "connect" each of the dots to one of the grid's axes. In particular, for each dot $i$, you'll draw either a horizontal line segment connecting it to the y-axis (with endpoints $(0, Y_i)$ and $(X_i, Y_i)$), or a vertical line segment connecting it to the x-axis (with endpoints $(X_i, 0)$ and $(X_i, Y_i)$). Each line segment only counts as "connecting" the single dot located at its endpoint, even if it happens to pass through other dots along the way.

No horizontal line segment is allowed to intersect with any vertical line segment. Line segments are not considered to intersect at either of their endpoints — for example, it's permitted for a horizontal line segment to pass through the endpoint of a vertical one, or vice versa. Horizontal line segments are allowed to overlap with other horizontal ones, as are vertical line segments with other vertical ones.

The cost of drawing a non-empty set of horizontal line segments is equal to the length of the longest one (in dollars), while the cost of drawing no horizontal line segments is $0. The cost of drawing a set of vertical line segments is similarly equal to the length of the longest one (if any), and the total cost of drawing all $N$ line segments is equal to the cost of drawing the set of horizontal ones plus the cost of drawing the set of vertical ones.

You can choose to draw at most $H$ horizontal line segments, and at most $V$ vertical ones. What's the minimum total cost required to connect all $N$ dots to the grid's axes, without using too many of either type of line segment or causing any horizontal line segments to intersect with vertical ones, if that can be done at all?

In order to reduce the size of the input, the dots' coordinates will not all be provided explicitly. Instead, you'll be given $X_1, X_2, Y_1, Y_2$, as well as 8 constants $A_x, B_x, C_x, D_x, A_y, B_y, C_y,$ and $D_y$, and you must then compute $X_{3..N}$ and $Y_{3..N}$ as follows (bearing in mind that intermediate values may not fit within 32-bit integers):

$X_i = ((A_x \times X_{i-2} + B_x \times X_{i-1} + C_x) \mod D_x) + 1$, for $i = 3..N$  
$Y_i = ((A_y \times Y_{i-2} + B_y \times Y_{i-1} + C_y) \mod D_y) + 1$, for $i = 3..N$

## Input

Input begins with an integer $T$, the number of grids. For each room, there are three lines.  
The first line contains the space-separated integers $N$, $H$, and $V$.  
The second line contains the space-separated integers $X_1, X_2, A_x, B_x, C_x,$ and $D_x$.  
The third line contains the space-separated integers $Y_1, Y_2, A_y, B_y, C_y,$ and $D_y$.
