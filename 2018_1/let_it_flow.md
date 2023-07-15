# Problem

You've been hired for a boring plumbing installation job. You'll be installing pipes into a house which can be modeled as a grid with $3$ rows and $N$ columns. The $j$-th cell in the $i$-th row of the grid is described by the character $G_{i,j}$, and is either empty (if $G_{i,j} = .$) or is blocked by a wall (if $G_{i,j} = \#$). There's already a pipe incoming into the left edge of the top-left cell, and another pipe leaving from the right edge of the bottom-right cell.

Your job is to install one or more additional pipes in empty cells throughout the house, such that water can successfully flow through them from the top-left pipe all the way to the bottom-right one. You have access to a whole lot of pipes, but unfortunately they're all of a single type — elbow-shaped. When you install such a pipe in a cell, it allows water to flow in from one edge of the cell, make a 90-degree turn either clockwise or counter-clockwise, and flow out from another edge of the cell.

Pipes may only be installed into empty cells, and no cell may contain multiple pipes. So as to not waste equipment, each pipe installed must end up actually contributing to the flow of water -- in other words, you may not install a pipe if it could be removed without disrupting the flow of water from the top-left pipe to the bottom-right one.

To make the job less boring, you're interested in counting the number of different valid sets of pipes which you might choose to install. As this number may be large, you only want to compute its value modulo $1,000,000,007$. Two sets of pipes are considered to be different if one of them includes a pipe in a cell which is left empty in the other, or if at least one pipe is installed in a different rotation between them.

## Input

Input begins with an integer $T$, the number of houses.  
For each house, there is first a line containing the integer $N$.  
Then, $3$ lines follow, each containing a string of length $N$ containing only the characters $.$ and $\#$. The $j$-th character of the $i$-th line is $G_{i,j}$.
