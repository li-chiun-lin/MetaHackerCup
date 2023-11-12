# Problem

The kingdom of Hackadia has $N$ cities that are connected by $M$ bidirectional roads. Cities are enumerated from $0$ to $N - 1$. To attract tourists, the government has decided to open up some restaurant chains throughout the kingdom. Each restaurant chain will serve some subset of cities, and will have exactly one restaurant in each city of the chosen subset. Thus, each city will have some restaurant chains, and it is possible to have all possible restaurant chains in some city or not to have any restaurant chains in some city.

To ensure that tourists do not face a drastic change in the food scenario when traveling from one city to another, the government has decided that the following condition must be satisfied for each pair of cities $(u, v)$ :

"the number of restaurant chains open in city $u$ but not in city $v$" plus "the number of restaurant chains open in city $v$ but not in city $u$" should always be equal to the shortest distance between city $u$ and city $v$.

It is guaranteed that every two cities are connected by some sequence of bidirectional roads, and the shortest distance between city $u$ and city $v$ is the number of roads on the shortest path connecting $u$ and $v$.

Your job is to help the government determine the minimal number of restaurant chains, such that there exist some assignment of the restaurant chains among the cities that satisfy the above condition. If such assignment is not possible print $-1$.

## Input

The first line of the input will be the number of test cases $T$.  
Each of the test cases start with a line containing the numbers $N$ and $M$, representing the number of cities and the number of roads respectively.  
The next $M$ lines of each testcase contain a pairs of integers, representing the cities connected by a bidirectional road in Hackadia.  
Each testcase will be followed by an empty line.
