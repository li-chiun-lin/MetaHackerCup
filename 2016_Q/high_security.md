# Problem

A top-secret algorithmic research facility has decided to up its security by hiring guards to keep watch over the premises. After all, they don't want anyone sneaking in and learning the answers to questions such as "does P = NP?" and "what are the solutions to the 2016 Facebook Hacker Cup problems?".

When viewed from above, the facility can be modeled as a grid $G$ with $2$ rows and $N$ columns. The $j$-th cell in the $i$-th row is either empty (represented by $G_{i,j} =$ ".") or occupied by a building ($G_{i,j} =$ "X"), and the grid includes at least one empty cell.

Guards may be potentially stationed in any of the empty cells. A guard can see not only their own cell, but also all contiguous empty cells in each of the 4 compass directions (up, down, left, and right) until the edge of the grid or a building. For example, in the grid below, the guard ("G") can see every cell marked with an asterisk ("*"):

```text
.*.X.X..
*G*****X
```

What is the minimum number of guards required such that every empty cell in the grid can be seen by at least one of them?

## Input

Input begins with an integer T, the number of facilities that need guarding. For each facility, there is first a line containing the integer N. The next line contains the grid cells G1,1 to G1,N in order. The third line contains the grid cells G2,1 to G2,N in order.
