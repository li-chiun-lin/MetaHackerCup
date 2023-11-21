# Problem

Ishiko is opening a bracelet shop. Each bracelet she plans to sell is expressed as a ring of $N$ colored beads, with exactly $K$ green beads made of emerald, and $N−K$ remaining beads of all unique colors (neither green nor the same as any other bead in the bracelet). Ishiko has an infinite number of beads available for each of these $N−K+1$ different colors.

Ishiko wants to exhibit one copy of every possible distinct bracelet. Two bracelets are considered distinct if one is not a cyclic rotation of the other.

A vendor takes orders for triangular display cases of arbitrary positive integer heights. A case of height $H$ has $H$ rows, where the $i$-th row has $2 \times i−1$ slots, each slot capable of holding one bracelet.

How many display cases (of possibly differing heights) will Ishiko need to buy to exhibit one copy of every possible bracelet without leaving any empty slots in the display cases?

## Input

Input begins with an integer $T$, the number of cases.  
For each case, there is a line containing two space-separated integers, $N$ and $K$.
