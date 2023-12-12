# Problem

Cactus Park is a famous tourist attraction in Sandlandia. It holds $N$ cactus plants, numbered from $1$ to $N$. The cacti are connected by $M$ bidirectional trails, with trail $i$ connecting cacti $A_i$​ and $B_i$​.

From any cactus, it's always possible to get to any other cactus by taking some sequence of trails. There may be cycles in the park, where a cycle is any sequence of trails that lead from a certain cactus back to itself. The park also has a special property that each trail belongs to at most one simple cycle. In graph theory terms, we can say that the Cactus Park forms a cactus graph.

The park owners want to replace some number of cacti with information kiosks to help guide the tourists. Cutting down cactus $i$ and building a kiosk there costs the park $C_i$​ dollars. The owners want to build enough kiosks so that the shortest path from every remaining cactus to the closest kiosk does not exceed $K$ trails. Please help the owners determine the minimum total cost required to satisfy this requirement.

## Input

Input begins with a single integer $T$, the number of test cases.  
For each case, there is first a line containing three integers $N$, $M$, and $K$.  
Then, there is a line containing $N$ integers $C_{1..N}$​.  
Then, $M$ lines follow, the $i$-th of which contains two integers $A_i$​ and $B_i$​.
