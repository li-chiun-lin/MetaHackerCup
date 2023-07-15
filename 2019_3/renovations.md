# Problem

A family of four moles lives in an underground burrow. Each of them has an important role to play! Daddy Mole is in charge of renovating the burrow. Mommy Mole fixes up Daddy Mole's inevitable mistakes. And Brother Mole and Sister Mole mostly lie around playing video games.

Their burrow consists of $N$ little underground rooms, numbered from $1$ to $N$. Room $1$ is connected to the surface, and for each other room $i$ (such that $2 ≤ i ≤ N$), the room initially "above" room $i$ is room $P_i$, meaning that there's a tunnel leading downwards from room $P_i$ to room $i$, which may be traversed in either direction. It's guaranteed that it's possible to reach each room from room $1$ by travelling through a sequence of tunnels.

Daddy Mole will renovate the burrow $K$ times in a row. For each renovation in turn, he'll independently randomly select a room $i$ aside from room $1$ (such that $2 ≤ i ≤ N$), with each such room having an equal $1 / (N - 1)$ probability of being chosen each time. He'll then "improve" the burrow's architectural design by simply caving in the tunnel connecting node $i$ and the room currently above it, causing that tunnel to no longer exist. Mommy Mole will then immediately salvage the situation by creating a new tunnel leading downwards from room $1$ to room $i$ (such that the room above $i$ will now be room $1$). This may result in Mommy Mole recreating exactly the same tunnel that Daddy Mole had just caved in. Note that, in the resulting burrow, each room will always once again be reachable from room $1$.

After these $K$ random renovations have been completed, Brother Mole (who hangs out in room $A$) will go visit Sister Mole in her room (room $B$) to show off his latest video game high score. He'll travel along the unique sequence of tunnels which will get him there without passing through any rooms multiple times, at a speed of $1$ tunnel per minute. What's the expected amount of time this will take him?

Let this expected time (in minutes) be represented as a quotient of integers $p/q$ in lowest terms. Output the value of this quotient modulo $1,000,000,007$ — in other words, output the unique integer $x$ such that $0 ≤ x < 1,000,000,007$ and $p = x \times q \mod 1,000,000,007$.

## Input

Input begins with an integer $T$, the number of burrows.  
For each burrow, there is first a line containing the space-separated integers $N, K, A,$ and $B$.  
Then, $N - 1$ lines follow, the $i$-th of which contains the integer $P_{i+1}$ (starting with $P_2$).
