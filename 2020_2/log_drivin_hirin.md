# Problem

The rapid flow of rivers is an effective way to move logs in the great Canadian log drive. But as every Canadian knows, it can be a double-edged sword. If logs get stuck on the riverbanks, they'll eventually pile up and cause the river to overflow. Sometimes you need a helping hand to keep the logs moving.

In a given river system there are $N$ lakes and $N−1$ rivers flowing amongst the lakes. For each lake $i$ such that $2≤i≤N$, there's a river flowing from lake $P_i$​ to lake $i$ which is $L_i$​ metres long. There are no rivers flowing into lake $1$. $P_1$​ and $L_1$​ are defined to be equal to $0$, but are irrelevant. It's guaranteed that each lake is accessible from lake $1$ by some sequence of rivers. Each lake with no rivers flowing out of it has a log-processing plant.

Shipments of logs are often transported through these lakes and rivers. Each shipment consists of some number of logs, and is managed by a log driver with some integer carelessness value. A shipment may be transported from a lake by means of a river flowing out of it, to the lake which that river flows into. However, a number of logs will be permanently lost along the way, equal to the log driver's carelessness value multiplied by the length of the river (in metres). We can assume that shipments are always large enough that they don't risk completely running out of logs. Each shipment continues to be transported from lake to lake until reaching a log-processing plant.

Other log drivers available for hire also live by the lakes. There's a log driver living by each lake $i$ with a carelessness of $H_i$​. Whenever a shipment of logs is at lake $i$, the company that owns the shipment may choose to hire the log driver there to take over in place of the shipment's current log driver. The newly-hired log driver will then manage the shipment until it either reaches a log-processing plant, or another log driver is later hired to replace them.

As part of the log-istics team, you need to answer MM questions, the $i$-th of which asks: If you begin with a shipment of logs in lake $X_i$​, being managed by a log driver with a carelessness of $Y_i$​, what's the minimum number of logs which can be lost by the time the shipment reaches any log-processing plant? Please note that each question is independent of the others (for example, the same log driver may be hired as part of the answer to multiple different questions).

Let $V_i$​ be the answer to the $i$-th question. In order to reduce the size of the output, you must calculate a single integer: the product of $(V_{i+1})$ over $i=1..M$. As this product may be very large, you should only compute its value modulo $10^9+7$.

In order to reduce the size of the input, the above values will not all be provided explicitly. Instead, you'll be given the first $K$ values $P_{1..K}​, L_{1..K}​, H_{1..K}​, X_{1..K}​,$ and $Y_{1..K}$​, as well as the five tuples of constants $(A_P,B_P,C_P), (A_L,B_L,C_L,D_L), (A_H,B_H,C_H,D_H),$ and $(A_X,B_X,C_X), (A_Y,B_Y,C_Y,D_Y)$, and must then compute $P_{(K+1)..N}​, L_{(K+1)..N}​, H_{(K+1)..N}​, X_{(K+1)..M}​,$ and $Y_{(K+1)..M}$​ as follows:

$P_i=((A_P∗P_{i−2}+B_P∗P_{i−1}+C_P) \mod (i−1))+1$ for $i>K$  
$L_i=((A_L∗L_{i−2}+B_L∗L_{i−1}+C_L) \mod D_L)+1$ for $i>K$  
$H_i=((A_H∗H_{i−2}+B_H∗H_{i−1}+C_H) \mod D_H)+1$ for $i>K$  
$X_i=((A_X∗X_{i−2}+B_X∗X_{i−1}+C_X) \mod N)+1$ for $i>K$  
$Y_i=((A_Y∗Y_{i−2}+B_Y∗Y_{i−1}+C_Y) \mod D_Y)+1$ for $i>K$

## Input

Input begins with an integer $T$, the number of river systems. For each system, there are 1 lines:  
The first line contains the 3 space-separated integers $N, M,$ and $K$.  
The second line contains the $K$ space-separated integers $P_{1..K}$​.
The third line contains the 3 space-separated integers $A_P​, B_P​,$ and $C_P$​.
The fourth line contains the $K$ space-separated integers $L_{1..K}$​.
The fifth line contains the 4 space-separated integers $A_L​, B_L​, C_L​,$ and $D_L$​.
The sixth line contains the $K$ space-separated integers $H_{1..K}$​.
The seventh line contains the 4 space-separated integers $A_H​, B_H​, C_H​,$ and $D_H$​.
The eighth line contains the $K$ space-separated integers $X_{1..K}$​.
The ninth line contains the 3 space-separated integers $A_X​, B_X​,$ and $C_X$​.
The tenth line contains the $K$ space-separated integers $Y_{1..K}$​.
The eleventh line contains the 4 space-separated integers $A_Y​, B_Y​, C_Y​,$ and $D_Y$.
