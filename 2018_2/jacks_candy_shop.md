# Problem

Jack is a little boy with big dreams: to own the biggest candy shop in the world! He's off to a modest start with $N$ candies for sale, numbered from $0$ to $N - 1$. The price of candy $i$ is $i$ dollars. In his shop's front window, Jack has arranged his candies in the shape of a tree rooted at candy $0$, with the parent of each other candy $i$ $(1 ≤ i < N)$ being candy $P_i$.

$M$ other kids in Jack's neighbourhood have agreed to come by and be his first customers! Jack has assigned them customer numbers from $0$ to $M - 1$. Unfortunately, these kids are a bit picky when it comes to sweets. Customer $i$ only likes candies within the subtree rooted at candy $C_i$. This means that they're only willing to purchase a candy if it's either candy $C_i$, or one of its children, or one of its childrens' children, and so on. They also have amazing self-restraint — each customer will limit themselves to buying at most one candy.

For each of the $M$ customers, Jack may either sell them any single candy of his choice within the customer's required subtree, or no candy at all. Each of the $N$ candies may be sold to at most one customer. Jack is willing to do whatever it takes to achieve his dreams, even if it means extorting as much cash as possible from fellow children. As such, he'd like to choose candies to sell such that the sum of their prices is maximized. Can you help him determine this maximum sum of candy prices?

In order to reduce the size of the input data, $C_{0..M-1}$ may be generated as follows using given constants $A$ and $B$:

$C_i = (A \times i + B) \mod N$ (for $i = 0 .. M - 1$)

## Input

Input begins with an integer $T$, the number of trees.  
For each tree, there is first a line containing the space-separated integers $N$, $M$, $A$, and $B$.  
Then $N - 1$ lines follow, the $i$-th of which (1-indexed) contains the single integer $P_i$.
