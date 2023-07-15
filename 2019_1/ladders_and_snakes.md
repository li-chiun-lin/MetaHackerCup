# Problem

$N$ ladders have been set up in a room, which can be represented as a 2D plane when viewed from the side. The room's floor is the horizontal line with y-coordinate $0$, and its ceiling is the horizontal line with y-coordinate $H$. The $i$-th ladder is a vertical line segment between integral coordinates $(X_i, A_i)$ and $(X_i, B_i)$, located within the inclusive bounds of the room (such that $0 ≤ A_i < B_i ≤ H$). Note that each ladder may be touching the floor and/or ceiling, or may be floating in mid-air (don't question it). No two ladders overlap with one another (even at their endpoints).

Sneider the Snake has taken an interest in this room, and may add $0$ or more snakes to it. The $j$-th snake will be a vertical line segment between some coordinates $(x_j, a_j)$ and $(x_j, b_j)$, located strictly inside the bounds of the room (with $x_j$ being any non-negative real number, and $a_j$ and $b_j$ being integers such that $0 < a_j ≤ b_j < H$). A snake may be a length-0 line segment, with its endpoints being equal, in which case it occupies only a single point on the plane. No snake may overlap with any other snake, nor with any ladder (even at an endpoint).

Flynn the Flying Squirrel finds herself on the floor at coordinates $(0, 0)$, and wants to reach coordinates $(0, H)$ on the ceiling. At any point, she may gracefully hover horizontally (left or right) as long as she doesn't overlap with any snake (including exactly at one of its endpoints). She may also move vertically (up or down) as long as she's overlapping with a ladder (including exactly at one of its endpoints). Flynn always moves continuously around the plane (she does not skip from one integral coordinate to the next).

Sneider the Snake doesn't want Flynn to reach her destination, just because he likes being mean. Determine the minimum possible sum of lengths of snakes which Sneider must place such that Flynn will be unable to reach coordinates $(0, H)$ from her initial position $(0, 0)$, if possible.

## Input

Input begins with an integer $T$, the number of rooms.  
For each room, there is first a line containing the space-separated integers $N$ and $H$.  
Then, $N$ lines follow, the $i$-th of which contains the space-separated integers $X_i$, $A_i$, and $B_i$.
