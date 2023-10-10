# Problem

Mr. Fox has just won the lottery! As a result, he's treated himself to some gifts — a few socks, a few rocks, a few blocks... oh, and the entire Panama canal system.

The system has $K$ canals, the $i$-th of which consists of a line of $N_i$ equally-sized sections. The $j$-th section of the $i$-th canal initially contains $W_{i,j}$ gallons of water. There's also an initially closed lock (a retractable wall) between each pair of adjacent sections (that is, between sections $1$ and $2$, sections $2$ and $3$, and so on). As such, there are $N_i-1$ such locks in the $i$-th canal.

The canals are all linked to each other by an additional central hub section (also of equal size to the other sections), which initially contains $H$ gallons of water. This section is adjacent to the $1$-st section of each of the canals, separated by a special initially closed lock. As such, there are $K$ such central locks.

Mr. Fox is relaxing in a yacht (oh, right, he also bought himself one of those) floating in the central hub section. Just for fun, he'd like to raise the water level in this section as high as possible. To do so, he may give any (potentially empty) sequence of commands to his Panama employees, one per minute. Each command consists of selecting a single lock anywhere in the canal system and toggling it from being closed to being open (or vice versa). In the following minute, the water will level out (as water tends to do) by flowing through open locks such that, for any pair of adjacent sections which are separated by an open lock, they will end up with equal amounts of water. Mr. Fox does need to obey the Panama canal system's safety regulations, however, which impose one restriction on his commands: whenever one of the $K$ central locks adjacent to the central hub section is opened, it must be closed a minute later and then never re-opened.

Mr. Fox loves watching water flow through his locks, especially when it allows his yacht to magically rise up. Wheeeee! By commanding his employees carefully, how much water can Mr. Fox get into the central hub section?

## Input

Input begins with an integer $T$, the number of canal systems Mr. Fox owns.  
For each system, there is first a line containing the space-separated integers $K$ and $H$.  
Then, $K$ lines follow, the $i$-th of which contains the integer $N_i$ followed by the space-separated integers $W_{i,1} ... W_{i,N_i}$.
