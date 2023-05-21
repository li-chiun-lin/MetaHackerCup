# Problem

The mining company Facebulk Inc. has just rebranded to Metal Platforms Inc. In order to move fast with stable infrastructure, Metal has contracted the serpentine safety inspector, Solid Snake, to inspect $T$ walls across its mine shafts.

A given wall has $N$ vertical ladders for Solid Snake to inspect. The wall can be represented as a 2D plane, with $y=0$ being the lowest part of the wall, where it touches the ground. The $i$-th ladder is positioned at x-coordinate $i$, with its bottom at y-coordinate $A_i$​ and its top at y-coordinate $B_i$​.

Solid Snake is initially on the ground at coordinates $(0,0)$ and hopes to inspect as many ladders as possible, ensuring they meet Solid Snake's Strict Serpentine Safety Specifications (SSSSSS), before finally returning to any position on the ground.

For example, the fourth sample case is depicted below:
Solid Snake can perform the following actions:

1. If he's on the ground, he can freely move left and right, and can climb onto any ladder $i$ which touches the ground at his current x-coordinate (i.e. $A_i=0$)
1. If he's on a ladder $i$, he can:
    1. Inspect it (if he hasn't already inspected that ladder)
    1. Freely move up and down on that ladder — in other words, decrease his y-coordinate as low as $A_i$​ or increase it as high as $B_i$​ (while keeping his x-coordinate equal to $i$)
    1. Freely move onto the ground if the ladder touches the ground (i.e. $A_i=0$)
    1. Jump horizontally to any other ladder $j$ such that $A_j≤y≤B_j$​, where $y$ is his current y-coordinate (note that he can jump directly to any such ladder, potentially passing by and ignoring other ladders along the way)

Please help Solid Snake determine the maximum number of ladders that he can inspect. Furthermore, determine the minimum number of jumps required for him to inspect that many ladders and then end up back on the ground at the end. Note that Solid Snake is allowed to intermediately return to the ground before he's done with all of his ladder inspections.

## Input

Input begins with an integer $T$, the number of mine shaft walls to be inspected.  
For each wall, there is first a line containing a single integer $N$.  
Then, $N$ lines follow, the $i$-th of which consists of 2 space-separated integers, $A_i$​ and $B_i$​.
