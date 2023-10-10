# Problem

Today, Mr. Fox is taking it easy by playing with some blocks in a 2D world. Each block is an inch-by-inch square, and there are $N$ stacks of blocks in a row, with the $i$-th stack having $H_i$ blocks. For example, if $N=6$ and $H=\{3, 1, 5, 4, 1, 6\}$, then the collection of blocks looks like this (where an "X" denotes a block):

```text
.....X
..X..X
..XX.X
X.XX.X
X.XX.X
XXXXXX
```

Ever curious, Mr. Fox would like to answer $Q$ questions about his blocks (without actually modifying them), the $i$-th one being as follows:

"If I were to consider only the stacks from $A_i$ to $B_i$ inclusive, getting rid of all of the other blocks, how many square inches of water would my block structure be able to hold?"

As one might imagine, a given square inch can hold water if it doesn't contain a block itself, but there is a block both somewhere to its left and somewhere to its right at the same height. For example, if you were to take $A_i=2$ and $B_i=6$, you would be left with the following block structure to consider (where an "*" denotes an inch-by-inch square which can hold water):

```text
.....X
..X**X
..XX*X
X.XX*X
X.XX*X
XXXXXX
```

## Input

Input begins with an integer $T$, the number of block structures Mr. Fox has.  
For each structure, there is first a line containing the space-separated integers $N$ and $Q$.  
The next line contains the space-separated integers $H_i$.  
Then follow $Q$ lines, the $i$-th of which contains the space-separated integers $A_i$ and $B_i$.
