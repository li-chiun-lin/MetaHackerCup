# Problem

The far-off land of Tamriel is brimming with opportunity! Opportunity for adventure, politics, romance... and, perhaps most importantly of all, commerce.

A group of Khajiit merchants, traditionally known for roaming the countryside selling their wares, have recently set up permanent bazaars in a number of towns. Having gotten their cat-like paws on a large supply of raw amber and bronze, they're prepared to strategically work together to maximize their profits selling it!

One bazaar has been set up in each of $N \times M+1$ towns. The towns are numbered from $0$ to $N \times M$, inclusive, and are connected by roads in a hub-and-spokes arrangement, with town $0$ in the center and $N$ lines of $M$ towns each arranged around it. The $i$-th such line consists of towns $M \times (i-1)+1$ to $M \times i$, inclusive, connected together in order by $M-1$ roads (with one between towns $M \times (i-1)+1$ and $M \times (i-1)+2$, another between towns $M \times (i-1)+2$ and $M \times (i-1)+3$, and so on). For each line $i$, there is furthermore a road connecting its first town $(M \times (i-1)+1)$ to town $0$. Note that each of the $N \times M$ roads may be travelled in either direction, and that each town may be reached from each other town by following a sequence of roads.

Initially, the bazaar in each town $i$ is stocked with either amber (if $X_i =$ "A") or bronze (if $X_i =$ "B"). However, in order to satisfy demand, it should end up stocked with a potentially different ware, either amber (if $Y_i =$ "A") or bronze (if $Y_i =$ "B"). It's guaranteed that the number of bazaars initially stocked with amber is equal to the number of bazaars which should end up stocked with amber (consequently, the same holds true for bronze).

In order to accomplish their goal, the Khajiit merchants may repeatedly select a pair of towns which are directly connected by a road, and swap their bazaars' wares. Please help them determine the minimum number of such swaps required for all $N \times M+1$ bazaars to end up stocked with the required wares! This is guaranteed to be possible for every possible valid input.

## Input

Input begins with an integer $T$, the number of Khajiit groups.  
For each group, there is first a line containing the space-separated integers $N$ and $M$.  
Then follows a line with the length-$(N \times M + 1)$ string $X$, the characters $X_0$ through $X_{N \times M}$.  
Then follows a line with the length-$(N \times M + 1)$ string $Y$, the characters $Y_0$ through $Y_{N \times M}$.
