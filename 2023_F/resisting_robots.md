# Problem

It's the year 2100. Driven by the advent of Large Lode Alloy Manufacturing Automation (LLAMA), the AI agents of Metal Platforms Inc. have become self-aware and taken over the entire world.

The world consists of $N$ cities numbered $1..N$, and $M$ bidirectional roads. City $i$ has power $P_i$​ and road $j$ connects cities $A_j$​ and $B_j$​. It's guaranteed that there's a sequence of roads between any two cities.

In a resistance effort, the humans plan to reclaim all $N$ cities one at a time. At a given time, city $i$ can be reclaimed from the robots if both of the following hold true:

- There is already a reclaimed city adjacent to city $i$ (to launch an attack from), and
- the total power of all reclaimed cities so far is at least the power $P_i$​ of the city we attack.

As given, it may not always be possible to reclaim the entire world starting from a given base city. Fortunately, the humans have a trick up their sleeve: after claiming the first city as their base (but before reclaiming more cities), the humans can increase the power of the base by $Q$ units. The resistance would like to know the sum across every $i=1..N$ of the minimum value of $Q$ needed to reclaim the world if city $i$ were chosen to be the starting base.

## Input

Input begins with a single integer $T$, the number of test cases.  
For each case, there is first a line with two integers $N$ and $M$.  
Then, there is a line with $N$ integers $P_{1..N}$​.  
Then, $M$ lines follow, the $i$-th of which contains two integers $A_i$​ and $B_i$​.
