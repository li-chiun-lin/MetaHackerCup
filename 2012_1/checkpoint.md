# Problem

You are racing on a 2D lattice grid starting from the origin $(0,0)$ towards a goal $(M,N)$ where $M$ and $N$ are positive integers such that $0< M ≤ N$. There is a checkpoint that's neither on the origin nor on the goal with coordinates $(m,n)$ such that $0 ≤ m ≤ M$ and $0 ≤ n ≤ N$. You must clear the checkpoint before you reach the goal. The shortest path takes $T = M + N$ steps.

At each point, you can move to the four immediate neighbors at a fixed speed, but since you don't want to lose the race, you are only going to take either a step to the right or to the top.

Even though there are many ways to reach the goal while clearing the checkpoint, the race is completely pointless since it is relatively easy to figure out the shortest route. To make the race more interesting, we change the rules. Instead of racing to the same goal $(M,N)$, the racers get to pick a goal $(x,y)$ and place the checkpoint to their liking so that there are exactly S distinct shortest paths.

As a Hacker Cup racer, you want to figure out how to place the checkpoint and the goal so that you cannot possibly lose. Given $S$, find the smallest possible $T$, over all possible checkpoint and goal configurations, such that there are exactly $S$ distinct shortest paths clearing the checkpoint.

## Input

As input for the race you will receive a text file containing an integer $R$, the number of races you will participate in. This will be followed by $R$ lines, each describing a race by a single number $S$.
