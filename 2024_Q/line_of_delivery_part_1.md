# Problem

Candice is playing a solitaire game of curling on a 1-dimensional sheet of ice, using stones of negligible size. She will throw $N$ stones (numbered $1$ to $N$) from position $0$, targeting a position $G$ units to the right. In curling, though we say a stone is “thrown”, it’s actually slid along the ice.

The $i$-th stone will be thrown with energy $E_i$​, and will travel $E_i$​ units to the right unless it collides with another stone, in which case it will transfer its remaining energy to the stone it hits. Formally, we repeat this process until all stones are stationary:

- If the moving stone is at the same position as a stationary stone, the moving stone stops, and the stone it hits is now the moving stone with the remaining energy of the previous moving stone.
- Otherwise, the moving stone moves $1$ unit to the right and its energy is reduced by $1$. If the moving stone now has energy $0$, it becomes stationary.

After all of the stones are thrown, which stone is closest to the goal position GG, and how far away from the goal is it?

## Input Format

Input begins with an integer $T$, the number of test cases.
Each case starts with a line that contains the integers $N$ and $G$.
Then $N$ lines follow, the $i$-th of which contains $E_i$​.
