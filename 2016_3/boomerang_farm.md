# Problem

You're a proud boomerang farmer, like your father before you (and his father before him, but quite unlike his grandfather). Your boomerang field can be modelled as a 2D grid of square cells, with $M$ rows and $N$ columns. Each cell contains a boomerang lying flat on the ground, in one of four possible orientations called A, B, C, and D:

```text
    A   B   C   D
   _|   |_   _ _
            |   | 
```

As you can see, there are 2 points at which pairs of boomerangs are touching one another at their endpoints. As all boomerang farmers know, that could stunt the growth of your precious boomerangs!

Fortunately, you can salvage the situation by rotating boomerangs by integer multiples of 90 degrees. In particular, rotating a single boomerang by 90 degrees either clockwise (for example, changing its orientation from A to B) or counter-clockwise (for example, from A to D) takes 1 minute. You may rotate a single boomerang multiple times.

You have $K$ minutes of free time that you can use to fix up your field as well as you can (though you don't have to use all of this time). What's the minimum number of pairs of touching boomerangs that you can end up with at the end of this time?

## Input

Input begins with an integer $T$, the number of fields.  
For each field, there is first a line containing the space-separated integers $M$, $N$, and $K$.  
Then, $M$ lines follow, the $i$-th of which contains a string of length $N$ representing the $i$-th row of the field as described above.
