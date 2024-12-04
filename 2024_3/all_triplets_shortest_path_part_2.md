# Problem

Your friends, __Dijkstra__, __Dikjstra__, __Djikstra__, __Djkistra__, __Dkijstra__, and __Dkjistra__, recently learned about graph theory. They all claim to have invented a new algorithm to find the shortest path between all pairs of nodes in an undirected tree with $N$ nodes (numbered from $1$ to $N$).
Their algorithms all run on a matrix $dist$. Initially, $dist[u][v]=dist[v][u]=1$ if there exists an edge $u↔v$, $0$ if $u=v$, and $N$ otherwise.
__Dijkstra__'s code is as follows:

```cpp
for (int i = 1; i <= N; i++)
  for (int j = 1; j <= N; j++)
    for (int k = 1; k <= N; k++)
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
```

__Dikjstra__'s code is as follows:

```cpp
for (int i = 1; i <= N; i++)
  for (int k = 1; k <= N; k++)
    for (int j = 1; j <= N; j++)
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
```

__Djikstra__'s code is as follows:

```cpp
for (int j = 1; j <= N; j++)
  for (int i = 1; i <= N; i++)
    for (int k = 1; k <= N; k++)
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
```

...and so forth, with their names bearing an uncanny resemblance to the order of the loops.
But do any of them actually work? That’s up to you, the coding grandmaster, to find out!  You'll run one of these algorithms on a tree where the $i$-th edge is $U_i↔V_i$​. You're given a 3-letter string $S$, corresponding to letters $2..4$ of the name of the person whose code should be run on your tree.
Output "Lucky" if the code correctly populates $dist[u][v]$ with the shortest path length between all pairs of nodes $u$ and $v$ after it finishes execution, otherwise output "Wrong".

## Input Format

Input begins with an integer $T$, the number of test cases.
The first line of each test case contains the string $S$.
The next line contains a single integer $N$.
$N−1$ lines follow, the $i$-th of which contains two integers $U_i$​ and $V_i$​.
