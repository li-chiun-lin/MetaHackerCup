# Problem

The ingenuity of the great Canadian log drive is the use of natural rivers to transport logs. But as every Canadian knows, not every body of water is so free-flowing, especially in winter. In slow-moving sections of a river, it's common for the surface of the water to freeze overnight, trapping the logs. The log drivers can break up the ice with their long-handled picks, but we'll give them a helping hand anyway. With dynamite.

Paul is in charge of coordinating the placement of explosive charges. This is the best dynamite-related job in the log drive, not because it's the safest (which it is), but because you get to light the fuse at the end. We can model the relevant section of the river as a number line with $N$ log drivers and $M$ clusters of frozen logs. The $i$-th log driver is at position $P_i$​ (measured in metres), and the $i$-th cluster of logs is at position $Q_i$​. All $N+M$ of these initial positions are distinct.

Every second, each log driver can move one metre to either the left or right, or remain stationary. Multiple log drivers are permitted to occupy the same position. When a log driver occupies the same position as a cluster of frozen logs, they can spend $S$ seconds to set an explosive charge, and can continue moving after that. Due to an error, please note that $S$ is always equal to $0$.

As soon as an explosive charge is in place at every cluster, Paul will begin the detonation process by lighting the universal fuse (don't worry, the fuse is long enough to allow the other log drivers to clear out in time). If Paul commands the log drivers optimally, what's the minimum amount of time after which he can light the fuse?

In order to reduce the size of the input, the positions of the logs and log drivers will not all be provided explicitly. Instead, you'll be given the first $K$ values $P_{1..K}$​ and $Q_{1..K}$​, as well as the two quadruples of constants $(A_P,B_P,C_P,D_P)$ and $(A_Q,B_Q,C_Q,D_Q)$, and must then compute $P_{(K+1)..N}$​ and $Q_{(K+1)..M}$​ as follows:

$P_i=((A_P∗P_{i−2}+B_P∗P_{i−1}+C_P) \mod D_P)+1$ for $i>K$
$Q_i=((A_Q∗Q_{i−2}+B_Q∗Q_{i−1}+C_Q) \mod D_Q)+1$ for $i>K$

## Input

Input begins with an integer $T$, the number of frozen river sections.  
For each section, there are 5 lines.
The first line contains the 4 space-separated integers $N, M, K,$ and $S$.
The second line contains the $K$ space-separated integers $P_{1..K}$​.
The third line contains the 4 space-separated integers $A_P​, B_P​, C_P​,$ and $D_P$​.
The fourth line contains the $K$ space-separated integers $Q_{1..K}$​.
The fifth line contains the 4 space-separated integers $A_Q​, B_Q​, C_Q​,$ and $D_Q$​.
