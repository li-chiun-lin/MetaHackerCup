# Problem

With a successful commission under his belt, Carlos has really made a splash with his consulting firm, Carlos Structures Industries. His next customer is Texas Instruments, the well-known manufacturer of graphing calculators.

"In today's competitive environment, you need an edge. I can make sure that your newest graphing calculator is chock-full of the best modern graphs."

Carlos's pitch seems to have worked as Texas Instruments has ordered an undirected, weighted graph. Their R&D department has come up with a list of requirements that will ensure the graph is a hit with Gen Z schoolchildren.

To start with, the graph must have $N$ nodes numbered $1$ to $N$. It must have no self-loops and at most one edge connecting each unordered pair of nodes. The weight of each edge must be an integer between $1$ and $1,000,000$, inclusive. The graph does not need to be connected.

The graph must also satisfy $M$ customer requirements, the $i$-th of which states that the shortest distance between two different nodes $X_i$ and $Y_i$ must be equal to $Z_i$. No two requirements pertain to the same unordered pair of nodes.

Carlos's goal is to find any valid graph consistent with all of these requirements if possible, or to determine that no such graph exists.

## Input

Input begins with an integer $T$, the number of graphs that Texas Instruments has commissioned.  
For each graph, there is first a line containing the space-separated integers $N$ and $M$.  
Then, $M$ lines follow, the $i$-th of which contains the space-separated integers $X_i$, $Y_i$, and $Z_i$.

## Output

For the $i$-th graph, print a line containing "Case #$i$: " followed by either an integer $E$ and then a description of a valid graph if possible, or the string "Impossible" if no valid graph exists.

A graph description contains $E$ lines, where $E$ is the number of edges in your graph. The $i$-th line contains the space-separated integers $A_i$, $B_i$, and $W_i$ indicating that there is an edge between nodes $A_i$ and $B_i$ with weight $W_i$. Please keep in mind that your graph must satisfy all of the requirements stated above (both the fundamental requirements dictated by Texas Instruments, and the $M$ customer ones).
