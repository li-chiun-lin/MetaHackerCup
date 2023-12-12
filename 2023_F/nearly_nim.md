# Problem

Alice and Bob are servers at Nim Sum Dim Sum, a bustling dumpling restaurant. For a staff meal, the manager has generously provided $N$ plates of dumplings in a row, numbered from $1$ to $N$. Initially, plate $i$ has $A_i$​ dumplings. In classic fashion, the duo has decided to play a game.

Alice and Bob will take turns eating dumplings from the plates. On a given turn, a player must pick a plate adjacent to the last picked plate by the other player, and eat any positive number of dumplings from that plate. The first player who cannot do so on their turn loses. Alice goes first, and can choose any starting plate to eat from.

Assuming both players play optimally, how many starting moves can Alice make so that she wins? Two starting moves are considered different if Alice eats from different plates, or eats a different number of dumplings.

## Input

Input begins with an integer $T$, the number of cases.  
Each case will begin with a single integer $N$ followed by the $N$ integers $A_1,...,A_N$​ on the next line.
