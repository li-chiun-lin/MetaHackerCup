# Problem

Alice and Bob are spending the day in the local library, learning about 2-player zero-sum games. One of the books they're reading, "Grundy Numbers For Fun And Profit" by Nim Nimberly, has an interactive insert with a bunch of graphs and instructions for a game where the players take turns colouring each graph's vertices.

Each game starts with a directed graph that has $2 \times N$ vertices, numbered from $1$ to $2 \times N$, all of which are initially uncoloured, and $M$ edges. The $i$-th edge goes from vertex $A_i$ to vertex $B_i$. No two edges connect the same pair of vertices in the same direction, and no edge connects a vertex to itself.

Alice goes first and colours vertices 1 and 2. She must colour one of these two vertices black, and the other one white. Bob then takes his turn and similarly colours vertices 3 and 4, one of them black and the other one white. This continues with Alice colouring vertices 5 and 6, Bob colouring 7 and 8, and so on until every vertex is coloured. At the end of the game, Alice wins if there are no edges going from a black vertex to a white one. Bob wins if such an edge exists.

Who will win if Alice and Bob play optimally?

## Input

Input begins with an integer T, the number of graphs.  
For each graph, there is first a line containing the space-separated integers $N$ and $M$.  
Then $M$ lines follow, the $i$-th of which contains the space-separated integers $A_i$ and $B_i$.
