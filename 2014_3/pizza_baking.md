# Problem

Tony plans to open a pizzeria. After researching the pizza market for a long time, he has come up with a prediction for the number of orders that he is going to receive. Tony will keep his pizzeria open for $K$ hours a day. And he knows that he is going to get orders for $N$ pizzas. Also pizza eaters are very fussy, so the $i$-th pizza must be inserted into an oven at exactly the beginning of the $S_i$-th hour, and taken out of the oven at exactly the end of the $E_i$-th hour.

For this purpose Tony needs to buy some ovens to be able to bake all the ordered pizzas. Each oven is quite large, and can hold several pizzas at the same time. However, due to voltage fluctuations throughout the day, only a certain number of pizzas can be baked simultaneously in each oven at any point of time. Tony has calculated the value $C_i$, for $0 ≤ i < K$, denoting the number of pizzas that can be baked together in an oven during the $i$-th hour. A pizza that has been entered in an oven cannot be taken out of the oven until it has completed its scheduled baking period.

High quality pizza ovens are very costly. Help Tony find out the minimum number of ovens he must buy to complete all orders, and then find an assignment of pizzas to ovens, satisfying all the constraints above. If there are multiple assignments involving the same minimum number of ovens, print the smallest possible assignment according to the ordering defined below.

Here's how you compare two assignments. If $X$ is an assignment of pizzas to ovens, let $X( i )$ denote the set of 0-based pizza indices assigned to oven $i$ (oven indices are also 0-based).

If $S$ and $T$ are two sets of pizza indices, we say that $S < T$, if and only if there exists some index $k$, such that :

- for $0 ≤ i < k$, pizza #$i$ either appears both in $S$ and $T$, or is missing from both $S$ and $T$, and,
- pizza #$k$ is present in $S$, but missing in $T$

If $X$ and $Y$ are two pizza assignments, we say that $X < Y$, if and only if there exists some $k$, such that :

- for $0 ≤ i < k$, $X( i )$ is identical to $Y( i )$, and,
- $X( k ) < Y( k )$, as per the set ordering defined above.

## Input

The first line of the input consists of a single integer $T$, the number of test cases.  
Each test case starts with a line containing the integer $K$, the number of hours the pizzeria will be open.  
The next line of each test case contains $K$ integers, $C_0, C_1, ..., C_{K-1}$, where $C_i$ is the maximum number of pizzas that can be inside any single oven in the $i$-th hour.  
The next line of each test case contains the integer $N$, the number of pizza orders.  
The next $N$ lines of each test case contain a pair of integers, $S_i$ and $E_i$, the start and end times for baking the $i$-th pizza.
