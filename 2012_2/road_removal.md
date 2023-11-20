# Problem

You are given a network with $N$ cities and $M$ bidirectional roads connecting these cities. The first $K$ cities are important. You need to remove the minimum number of roads such that in the remaining network there are no cycles that contain important cities. A cycle is a sequence of at least three different cities such that each pair of neighboring cities are connected by a road and the first and the last city in the sequence are also connected by a road.

## Input

The first line contains the number of test cases $T$.  
Each case begins with a line containing integers $N, M$ and $K$, which represent the number of cities, the number of roads and the number of important cities, respectively. The cities are numbered from $0$ to $N-1$, and the important cities are numbered from $0$ to $K-1$. The following $M$ lines contain two integers $a[i]$ and $b[i]$, $0 ≤ i < M$, that represent two different cities connected by a road.

It is guaranteed that $0 ≤ a[i], b[i] < N$ and $a[i] ≠ b[i]$. There will be at most one road between two cities.
