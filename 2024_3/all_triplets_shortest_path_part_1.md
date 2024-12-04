# Problem

Your friend, Dikjstra (sic), recently learned about graph theory. He claims to have invented a new algorithm to find the shortest path between all pairs of nodes in an undirected tree with $N$ nodes (numbered from $1$ to $N$).
The algorithm runs on a matrix $dist$. Initially, $dist[u][v]=dist[v][u]=1$ if there exists an edge $u↔v$, $0$ if $u=v$, and $N$ otherwise.
Dikjstra's code is as follows:

```cpp
for (int i = 1; i <= N; i++)
  for (int k = 1; k <= N; k++)
    for (int j = 1; j <= N; j++)
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
```

But does this actually work? That’s up to you, the legendary coding grandmaster, to find out! You'll run this code on a tree where the $i$-th edge is $U_i↔V_i$​.
Output "Lucky" if the code correctly populates $dist[u][v]$ with the shortest path length between all pairs of nodes $u$ and $v$ after it finishes execution, otherwise output "Wrong".

## Input Format

Input begins with an integer $T$, the number of test cases.
The first line of each case contains a single integer $N$.
$N−1$ lines follow, the $i$-th of which contains two integers $U_i$​ and $V_i$​.
