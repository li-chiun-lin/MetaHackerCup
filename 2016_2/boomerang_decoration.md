# Problem

As an experienced boomerangist, you take great pride in your trusty boomerang, and you'd like to be able to show it off! Unfortunately, it doesn't look quite right yet...

Like all boomerangs, yours is symmetrical in shape, with two $N$ millimetre-long halves. However, what's not necessarily symmetrical is its paint job — each millimetre-long section of each half has been painted some color. There are 26 possible colors, represented by uppercase letters ("A" to "Z"), and the $i$-th section of the left half (counting from the left end) has color $A_i$, while the $i$-th section of the right half (counting from the right end) has color $B_i$. You'd like your boomerang to be completely symmetrical (which is the case when the ith section in the left half has the same color as the $i$-th section in the right half, for all $1 ≤ i ≤ N$) as soon as possible!

To that end, you're enlisting the help of your two best friends, Jack and Jill, to repaint the left half of your boomerang until it matches the right half. Every second, Jack may paint over a "prefix" of the left half with a solid color, while Jill may simultaneously paint over a disjoint "suffix". In other words, every second, Jack and Jill will each select a color (from "A" to "Z"), Jack will select a value $x$ $(0 ≤ x ≤ N)$, and Jill will select a value $y$ $(0 ≤ y ≤ N - x)$. Then, Jack will repaint the first $x$ sections of the left half of the boomerang with his color, while Jill will repaint the last $y4 sections of the left half of the boomerang with her color. Painting over a section completely overwrites its previous color.

What's the minimum amount of time (in seconds) it can take Jack and Jill to make your boomerang completely symmetrical?

## Input

Input begins with an integer $T$, the number of boomerangs you want to decorate.  
For each boomerang, there is first a line containing the integer $N$, then two lines that each contain a string of length $N$.  
The $i$-th character of the second line is $A_i$.  
The $i$-th character of the third line is $B_i$.
