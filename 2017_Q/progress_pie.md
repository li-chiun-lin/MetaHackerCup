# Problem

Some progress bars fill you with anticipation. Some are finished before you know it and make you wonder why there was a progress bar at all.

Some progress bars progress at a pleasant, steady rate. Some are chaotic, lurching forward and then pausing for long periods. Some seem to slow down as they go, never quite reaching $100\%$.

Some progress bars are in fact not bars at all, but circles.

On your screen is a progress pie, a sort of progress bar that shows its progress as a sector of a circle. Envision your screen as a square on the plane with its bottom-left corner at $(0, 0)$, and its upper-right corner at $(100, 100)$. Every point on the screen is either white or black. Initially, the progress is $0\%$, and all points on the screen are white. When the progress percentage, $P$, is greater than 0%, a sector of angle $(P\% * 360)$ degrees is colored black, anchored by the line segment from the center of the square to the center of the top side, and proceeding clockwise.

While you wait for the progress pie to fill in, you find yourself thinking about whether certain points would be white or black at different amounts of progress.

## Input

Input begins with an integer $T$, the number of points you're curious about. For each point, there is a line containing three space-separated integers, $P$, the amount of progress as a percentage, and $X$ and $Y$, the coordinates of the point.
