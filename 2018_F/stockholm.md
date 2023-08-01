# Problem

Melody is visiting the beautiful city of Stockholm, Sweden! Stockholm has a number of waterways flowing through it, dividing the city up into a number of islands. Like most visitors, Melody was surprised to learn that there are in fact an infinite number of waterways and an infinite number of islands!

The waterways flow between an infinite number of junctions, which are numbered with non-negative integers starting from $0$. There's an infinitely-long waterway flowing into junction $0$, and then for each junction $j$, there are two waterways flowing out of it into junctions $2j+1$ and $2j+2$. This results in each junction having exactly three incident waterways.

An island is a connected region of land. Each waterway is adjacent to two different islands (one on each side of it), and has a bridge connecting those two islands together. Each junction is adjacent to three different islands (the distinct islands adjacent to its incident waterways).

Melody is currently aboard a friend's boat parked at some junction $A$, but she wants to visit another friend's boat which is parked at a different junction $B$. She'll begin by getting out of the first boat onto any of the three islands of her choice which are adjacent to junction $A$. She'll then walk on land until she arrives at any of the three islands which are adjacent to junction $B$, potentially crossing some bridges between islands along the way. Finally, she'll board the second boat from that island.

Melody's not a big fan of walking on Stockholm's rather unevenly cobbled bridges, so she'd like to cross as few of them as possible along the way. Help her determine the minimum number of bridges which she must cross to walk from junction $A$ to junction $B$!

## Input

Input begins with an integer $T$, the number of times Melody needs to travel between two junctions.  
For each trip, there is a single line containing the space-separated integers $A$ and $B$.
