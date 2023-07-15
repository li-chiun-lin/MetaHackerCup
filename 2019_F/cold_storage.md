# Problem

Fred works the night shift in a refrigerator storage warehouse. It's not very exciting work, but Fred has ways to pass the time when nobody's around. For example, lifting fridges turns out to be an amazing bodybuilding method!

The warehouse consists of $N$ sections in a row, numbered from $1$ to $N$. In each section $i$, there are initially $F_i$ fridges, all arranged in a single stack. The sections are intended to be separate from one another, and only accessible from the outside. To that end, each pair of adjacent sections are separated by a wall, for a total of $N-1$ walls. However, these walls don't stretch all the way to the ceiling, and aren't necessarily all of the same height. The wall between sections $i$ and $i+1$ has a height of $H_i$ fridge-heights (Fred has come to measure everything relative to fridge dimensions). Fred's favourite pastime involves climbing over these walls to get between the warehouse's sections!

Fred will begin by entering the warehouse in some section, carrying in some number of new fridges from the outside (yes, he's become strong enough to carry multiple fridges in his arms at once). When he's currently in a certain section $s$ and is carrying $f$ fridges, he may perform any of the following actions:

- Pick up a fridge from section s's stack of fridges, if it's non-empty. This decreases the number of fridges in that stack by $1$, and increases $f$ by $1$.
- Add a fridge that he's carrying onto section $s$'s stack of fridges, if he's carrying at least one fridge. This decreases $f$ by $1$, and increases the number of fridges in that stack by $1$.
- Climb onto section $s$'s stack of fridges and jump over a wall into an adjacent section, if the number of fridges in that stack is at least as large as the height of that wall (in fridge-heights). This decreases or increases $s$ by $1$.

Fred's goal is to visit all $N$ sections at least once each. He just needs to decide which section he should initially enter and how many additional fridges he should bring from the outside. He has $M$ such possible starting situations in mind, the $i$-th of which involves him beginning in section $X_i$ while carrying $Y_i$ fridges. For each hypothetical starting situation, please help Fred determine whether or not he will be able to visit all $N$ sections!

## Input

Input begins with an integer $T$, the number of warehouses Fred works at.  
For each warehouse, there is first a line containing the space-separated integers $N$ and $M$.  
Then follows a line with the $N$ space-separated integers $F_1$ through $F_N$.  
Then follows a line with the $N - 1$ space-separated integers $H_1$ through $H_{N-1}$.  
Then, $M$ lines follow, the $i$-th of which contains the space-separated integers $X_i$ and $Y_i$.
