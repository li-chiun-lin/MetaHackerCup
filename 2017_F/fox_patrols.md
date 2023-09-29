# Problem

A certain well-hidden valley is home to a thriving population of mysterious creatures — Foxen! However, keeping the valley safe from outsiders (such as humans) is a necessity. To that end, a group of Foxen have been sent out to patrol the border.

On their patrol route, the Foxen know that they're going to pass by an interesting, rectangular forest. When viewed from above, the forest can be modeled as a grid of cells with $R$ rows and $C$ columns. The rows are numbered from $1$ to $R$ from North to South, while the columns are numbered from $1$ to $C$ from West to East. One tree is growing in the center of each cell, and each tree's height (in metres) is some positive integer no larger than $H$.

If the Foxen were to look at the forest from the North side, all of the trees in any given column of cells would obscure each other and blend together. In fact, the Foxen would really only be able make out the overall shape of the forest's "skyline" when viewed from that direction. This Northern skyline can be expressed as a sequence of $C$ positive integers, with the $i$-th one being the largest of the $R$ tree heights in the $i$-th column.

Similarly, if they were to look at the forest from the West side, they would only be able to make out the shape of its skyline from that direction. This Western skyline is a sequence of $R$ positive integers, with the $i$-th one being the largest of the $C$ tree heights in the $i$-th row.

On their way to the forest, the Foxen find themselves wondering about what it might look like. They've done their research and are aware of its dimensions $R$ and $C$, as well as the maximum possible height of its trees $H$, but they don't know the actual heights of any of its trees. They'd like to determine how many different, distinct-looking forests they might end up finding. A forest is a set of heights for all $R \times C$ trees, and two forests are considered to be distinct-looking from one another if their Northern skyline sequences differ and/or their Western skyline sequences differ.

Please help the Foxen determine the number of possible different, distinct-looking forests! As this quantity may be quite large, they're only interested in its value when taken modulo $1,000,000,007$.

## Input

Input begins with an integer $T$, the number of different forests visited by the Foxen.  
For each forest, there is a single line containing the three space-separated integers $R$, $C$, and $H$.
