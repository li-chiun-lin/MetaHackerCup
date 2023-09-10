# Problem

$N$ groups of people are heading to the beach today! The $i$-th group is bringing a circular umbrella with a radius $R_i$ meters.

The beach has $M$ acceptable points at which umbrellas may be screwed into the sand, arranged in a line with 1 meter between each adjacent pair of points. Each group of people will choose one such point at which to position the center of their umbrella.

Of course, it's no good if any pair of umbrellas collide (that is, if the intersection of their circles has a positive area). The $N$ groups will work together to place their umbrellas such that this doesn't happen. However, they're wondering in how many distinct ways that can be accomplished. Two arrangements are considered to be distinct if they involve at least one group placing their umbrella in a different spot. As this quantity may be very large, they're only interested in its value modulo $1,000,000,007$.

Note that it might be impossible for all of the groups to validly place their umbrellas, yielding an answer of $0$.

## Input

Input begins with an integer $T$, the number of days the beach is open.  
For each day, there is first a line containing two space-separated integers, $N$ and $M$.  
Then, $N$ lines follow, the $i$-th of which contains a single integer, $R_i$.
