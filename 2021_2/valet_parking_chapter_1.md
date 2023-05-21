# Problem

When not out fighting crime, Shaun works valet at the Fairmont hotel. Recently, he has been using his new weapon – the ten rings – to secretly help him park cars among $T$ valet-designated garages.

The layout of a garage is a grid $G$ of $R$ rows (numbered from $1$ to $R$ from top to bottom) and $C$ columns (numbered from $1$ to $C$ from left to right) of parking spaces. Initially, each space in row $i$ and column $j$ contains a car if $G_{i,j}=G_{i,j}​=$ "X", or is otherwise empty (if $G_{i,j}=G_{i,j}​=$ ".").

Shaun has been tasked to clear out a path for easy garage access, requiring cars to be rearranged such that a certain row $K$ contains no cars in any of its $C$ spaces. To that end, the magic of the ten rings supports the following 3 types of moves:

1. Levitate any car out of the garage and onto the street, leaving its space empty (and the position of all other cars unchanged).
1. Shift all the cars in the garage upwards. For each car in the garage, it moves from its current parking space to the space just above it, unless there's either no such space (due to the car being in row $1$) or that space is occupied by a car which is remaining stationary, in which case this car itself remains stationary.
1. Shift all the cars in the garage downwards (similarly to #2).

For example, a sequence of two moves of type #2 is illustrated below:

```text
  X..   XXX   XXX
  .XX   ..X   XXX
  ..X   XXX   ..X
  XXX   ...   ...
```

Please help Shaun determine the minimum number of moves required to clear all the spaces in row $K$.

#Input

Input begins with an integer $T$, the number of garages in which Shaun must clear a path. For each garage, there is first a line containing 3 space-separated integers $R, C,$ and $K$. Then, $R$ lines follow, the $i$-th of which contains the $C$ characters $G_{i,1..C}​.
