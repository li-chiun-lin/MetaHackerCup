# Problem

After running tests on samples of ore, mining engineers must plot out the economics of extraction, transportation, and treatment in long range terms. Feasibility reports are then drafted for executive decision.

In a given Ontario town, all the extracted ore is shipped using the town's transportation network, known as its Bulk Transportation Chain (BTC). The BTC is a network of $N$ ore processing plants, numbered from $1$ to $N$, with $N−1$ roads running amongst them. The $i$-th road allows ore to be shipped in either direction between plants $A_i$​ and $B_i$. It is possible to reach any plant from any other plant by following a sequence of roads.

Mining is a dirty business, and not just among blue-collar workers. Executives of a new mining project are plotting to sabotage their rival company's presence in a given town by disrupting its transportation operations. However, in trying to actually build the blockade on the aforementioned roads, their plan was foiled.

As it turns out, ore processing plants communicate with one another via radio towers. Plant $i$ within the BTC network operates their radio towers on a frequency of $F_i$​ kilohertz, where $F_i$​ is an integer. On a given radio frequency, all of the plants will be able to communicate freely. Thus if ore transportation is disrupted between any pair of plants on the same frequency, they will notice immediately and alert their headquarters.

Equipped with this new intel, the executives would like to take another crack at disrupting their rival's operations. This time, they would like to blockade as many roads as they can, while ensuring that any pair of plants on the same radio frequency can still transport ore to each other through some sequence of roads. This way, every single plant will remain ignorant to any blockaded roads.

Given this restriction, what is the maximum number of roads that can be blockaded?

## Input

Input begins with an integer $T$, the number of towns that the execs are scoping out.  
For each town, there is first a line containing the single integer $N$.  
Then, $N−1$ lines will follow, the $i$-th of which contains the 2 space-separated integers $A_i$​ and $B_i$​.  
Then, there is a line with $N$ space-separated integers, $F_{1..N}$​.
