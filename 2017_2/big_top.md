# Problem

Come one, come all! The most famous circus troupe in all the land is on tour! Having just arrived in a new location, they're eager to set up their big top and showcase world-class acts of acrobatics and comedy for their audience.

Looking at the tent from the side (as a cross section), it will be set up along a one-dimensional strip of ground. $N$ vertical poles will be placed in the ground, one after another, with the $i$-th pole at a position $X_i$ meters to the right of an arbitrary reference point, and reaching a height of $H_i$ meters. No two poles will be at the same position.

After each pole is placed, the shape of the tent will be updated to fit the current set of poles. In particular, the upper outline of the tent will be a function with the following properties:

1. it's defined over all positions from negative infinity to positive infinity
1. its height is always non-negative
1. it's made up entirely of a series of connected line segments, with each one having a slope with absolute value no greater than 1 (meaning that the function is continuous, and its height may never change from left to right at an angle of more than 45 degrees up/down)
1. it doesn't intersect with any of the poles (meaning that, at each pole's position, the function's height must be no smaller than that of the pole)

The cross-sectional area of the tent is the area under this function. Despite their popularity, the circus troupe doesn't exactly have money to spare on tent materials (with most of their budget allocated to feeding their flying elephant star). As such, they'd like to minimize the cross-sectional area of their tent after placing each of the $N$ poles. They'd like you to calculate the sum of these $N$ minimal areas for them.

You're given $X_1$, and $X_{2..N}$ may then be calculated as follows, using given constants $A_x$, $B_x$, and $C_x$ (note that it is guaranteed that $X_{1..N}$ will be distinct):

$X_i = ((A_x \times X_{i-1} + B_x) \mod C_x) + 1$

Similarly, you're given $H_1$, and $H_{2..N}$ may then be calculated as follows, using given constants $A_h$, $B_h$, and $C_h$:

$H_i = ((A_h \times H_{i-1} + B_h) \mod C_h) + 1$

## Input

Input begins with an integer $T$, the number of different tents that the circus troupe will set up.  
For each tent, there is first a line containing the single integer $N$.  
Then there is a line containing the four space-separated integers $X_1$, $A_x$, $B_x$, and $C_x$.  
Then there is a line containing the four space-separated integers $H_1$, $A_h$, $B_h$, and $C_h$.
