# Problem

After running tests on samples of ore, mining engineers must plot out the economics of extraction, transportation, and treatment in long range terms. Feasibility reports are then drafted for executive decision.

In a given Ontario town, all the extracted ore is shipped using the town's transportation network, known as its Bulk Transportation Chain (BTC). The BTC is a network of NN ore processing plants, numbered from $1$ to $N$, with $N−1$ roads running amongst them. The $i$-th road allows ore to be shipped in either direction between plants $A_i$​ and $B_i$​, and has the capacity for at most $C_i$​ kilograms of ore to be shipped through it per minute. It is possible to reach any plant from any other plant by following a sequence of roads.

The shipping capacity for an unordered pair of processing plants is the maximum weight of ore that may be shipped between them (in either direction) per minute. This is equal to the minimum capacity of any road on the shortest sequence of roads connecting them (such a sequence is unique per pair of plants).

Mining is a dirty business, and not just among blue-collar workers. Executives of a new mining project are plotting to sabotage their rival company's presence in a given town by disrupting its transportation operations. They hope to blockade a single one of the $N−1$ roads within the town's BTC network, preventing any ore from being shipped along it and therefore reducing its capacity to $0$. They would like to negatively impact the shipping capacities between various pairs of processing plants as much as possible, but have yet to decide which road would best accomplish their goal, so they'll consider each of them in turn.

Let $S_i$​ be the sum of shipping capacities, in kilograms, across all $N∗(N−1)/2$ unordered pairs of processing plants if the $i$-th road were to be blockaded. In order to reduce the size of the output, you must calculate a single integer: the product of $S_{1..(N−1)}$​. As this product may be very large, you should only compute its value modulo $10^9 + 7$.

## Input
Input begins with an integer $T$, the number of towns that the execs are scoping out.  
For each town, there is first a line containing a single integer $N$.  
Then, $N−1$ lines will follow, the $i$-th of which contains the 3 space-separated integers $A_i$​, $B_i$​, and $C_i$​.
