# Problem

Gauss would like to heat up some pizza on his special grill. The grill grates occupy an infinite 2D plane and consist of a metal pin at every lattice point $(x,y)∈Z^2$. However, the burner below is round, so the grill only delivers heat at every lattice point within (or exactly on the border of) the circle of radius $R$ centered at $(0,0)$.

Gauss would like to simultaneously heat up $N$ slices of pizza, the $i$-th of which is a triangle with integral vertices $(X_i,A,Y_i,A)$, $(X_i,B,Y_i,B)$, and $(X_i,C,Y_i,C)$. Each slice is either:

- fully inside the circle (with all three vertices either inside or on the circle boundary), or
- partially intersecting the circle such that:
  - at least 1 vertex of the slice is strictly inside the circle, and
  - the portion of the slice outside the circle (if any) must be a single connected region.

Slices may touch one another at edges and vertices, but will not intersect with a positive area.

For each slice, the heat it receives is the number of lattice points simultaneously inside (or on the border of) both the triangle and circle. Note that a lattice point may be repeatedly counted for multiple slices meeting at an edge or vertex.

Please help Gauss calcuate the sum of heats received across all slices, modulo $1,000,000,007$.

## Input Format

Input begins with an integer $T$, the number of test cases.
The first line of each case contains the integers $N$ and $R$.
$N$ lines follow, the $i$-th containing the integers $X_{i,A}$​, $Y_{i,A}$​, $X_{i,B}$​, $Y_{i,B}$​, $X_{i,C}$​, and $Y_{i,C}$​.
