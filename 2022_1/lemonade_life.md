# Problem

There's a famous saying about what to do when life gives you lemons. As a traveling lemonade salesman who's never been given any lemons, you sadly can't relate. You must shamefully concoct your lemonade from store-bought powder with your back turned to the world, lest someone see your dirty secret.

Your sales route can be mapped out on a Cartesian plane with $N$ houses, the $i$-th of which is at coordinates $(X_i, Y_i)$. Your journey starts at house $1$, the leftmost house, and ends at house $N$, the rightmost house. Along the way, you may stop at zero or more other houses to sell lemonade.

You may only stop at a house $h$ if:

- standing at house $h$, there exists some direction you can face in which all other houses are strictly more behind you than they are in front of you (formally, if there exists a half-plane containing only house $h$), and
- house $h$ is at most Euclidean distance $D$ from the previous house you were at.

Your brand image is hurt if you go too long without selling lemonade. The brand damage incurred by traveling from one house to another is the larger of $K$ and the squared Euclidean distance between them. Formally, if your journey consists of $M$ $(2 \le M \le N)$ houses with the $i$-th being house $H_i$​ $(H_1 = 1, H_M = N)$, the total brand damage is:

$\sum_{i=1}^{M-1} \max(K, (X_{H_i} - X_{H_{i + 1}})^2 + (Y_{H_i} - Y_{H_{i + 1}})^2)$

Is it possible to make the journey? If so, what is the minimum possible total brand damage to do so? Note that the answer may be large, but will fit in a 64-bit integer.

## Input

Input begins with a single integer $T$, the number of test cases.  
For each test case, there is first a line containing three space-separated integers $N$, $K$, and $D$.  
Then, $N$ lines follow, the $i$-th of which contains two space-separated integers $X_i$​ and $Y_i$​.
