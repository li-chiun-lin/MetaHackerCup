# Problem

Today you've found yourself standing on an infinite 2D plane at coordinates $(X_0, Y_0)$. There are also $N$ targets on this plane, with the $i$-th one at coordinates $(X_i, Y_i)$.

You have a boomerang which you can throw in a straight line in any direction from your initial location. After you throw it, you may instantaneously run to any location on the plane. After the boomerang has travelled a distance of exactly $D$ along its initial trajectory, it will return directly to you — that is, to your chosen final location. Note that you cannot move around once the boomerang has started its return trip — its path will always consist of 2 line segments (the first of which has a length of exactly $D$). The boomerang and the targets have infinitesimal size.

Let $A$ be the number of targets which your boomerang hits (directly passes through) during the first segment of its flight, and $B$ be the number of targets which it hits during the second segment. Your throw is then awarded a score of $A \times B$. What's the maximum score you can achieve? Note that, if there is a target at the exact location at which the two segments meet (at a distance of $D$ from your initial location), then it counts towards both $A$ and $B$!

## Input

Input begins with an integer $T$, the number of planes.  
For each plane, there is first a line containing the space-separated integers $X_0$ and $Y_0$.  
The next line contains the integer $D$, and the one after contains the integer $N$.  
Then, $N$ lines follow, the $i$-th of which contains the space-separated integers $X_i$ and $Y_i$.
