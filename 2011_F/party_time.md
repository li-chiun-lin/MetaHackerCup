# Problem

You're throwing a party for your friends, but since your friends may not all know each other, you're afraid a few of them may not enjoy your party. So to avoid this situation, you decide that you'll also invite some friends of your friends. But who should you invite to throw a great party?

Luckily, you are in possession of data about all the friendships of your friends and their friends. In graph theory terminology, you have a subset $G$ of the social graph, whose vertices correspond to your friends and their friends (excluding yourself), and edges in this graph denote mutual friendships. Furthermore, you have managed to obtain exact estimates of how much food each person in $G$ will consume during the party if he were to be invited.

You want to choose a set of guests from $G$. This set of guests should include all your friends, and the subgraph of $G$ formed by the guests must be connected. You believe that this will ensure that all of your friends will enjoy your party since any two of them will have something to talk about...

In order to save money, you want to pick the set of guests so that the total amount of food needed is as small as possible. If there are several ways of doing this, you prefer one with the fewest number of guests.

The people/vertices in your subset $G$ of the social graph are numbered from $0$ to $N - 1$. Also, for convenience your friends are numbered from $0$ to $F - 1$, where $F$ is the number of your friends that you want to invite. You may also assume that $G$ is connected. Note again that you are not yourself represented in $G$.

## Input

The first line of the input consists of a single number $T$, the number of test cases.  
Each test case starts with a line containing three integers $N$, the number of nodes in $G$, $F$, the number of friends, and $M$, the number of edges in $G$.  
This is followed by $M$ lines each containing two integers.  
The $i$-th of these lines will contain two distinct integers $u$ and $v$ which indicates a mutual friendship between person $u$ and person $v$.  
After this follows a single line containing $N$ space-separated integers with the $i$-th representing the amount of food consumed by person $i$.
