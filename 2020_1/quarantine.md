# Problem

Let's give it up for all the health care professionals working on the front lines in the face of the COVID-19 pandemic. Many of them can be found at the Stanford-Sunnyvale Teaching Hospital (SSTH), a facility that's working tirelessly to keep the disease under control. The hospital is already following standard infection prevention and control practices, but Dr. Gregory Klaus, M.D. (one of SSTH's most brilliant doctors) is hoping to further reduce transmissions by making some renovations to the building layout.

A certain floor of the SSTH facility features $N$ rooms and $N−1$ hallways (each running directly between a pair of rooms), such that every room is reachable from every other room through a sequence of hallways. In computer science terms, the floor is organized like a tree rooted at room $1$. Specifically, for each room $i$ aside from the first $(2≤i≤N)$, there's a hallway running between it and room $E_i$​ that can be traversed in either direction.

Each room $i$ contains either a patient that has been diagnosed with COVID-19 (denoted by $S_i$​ = "#"), or otherwise an uninfected patient (denoted by $S_i$​ = "*").

With the help of the hospital's construction team, Dr. Klaus plans to renovate the floor as follows: close down one existing hallway and then construct a new one between two rooms, such that all rooms on the floor still end up reachable from all other rooms. In doing so, he would like to maximize the number of unordered pairs of uninfected patients who can safely reach each other in the resulting layout. An uninfected patient can safely reach another uninfected patient if their rooms are connected by a sequence of hallways which doesn't pass through any rooms with infected patients. It's possible that Dr. Klaus may elect to close down a hallway and then reconstruct a hallway between that same pair of rooms — the renovation budget needs to go somewhere...

Klaus has just two questions: what is the maximum attainable number of such safely-reachable uninfected patient pairs, and what is the number of distinct ordered pairs of hallway closures/constructions yielding that result?

In order to reduce the size of the input, the values $E_{2..N}$​ will not all be provided explicitly. Instead, you'll be given the first KK values $E_{2..(K+1)}$​, as well as the 3 constants $A, B,$ and $C$, and must then compute the remaining values $E_{(K+2)..N}$​ as follows:

$E_i=((A∗E_{i−2}+B∗E_{i−1}+C) \mod (i−1))+1$

## Input

Input begins with an integer $T$, the number of hospital floors.  
For each floor, there are 4 lines.
The first line contains the 2 space-separated integers $N$ and $K$.
The second line contains the length-$N$ string $S_{1..N}$​.
The third line contains the $K$ space-separated integers $E_{2..K+1}$​.
The fourth line contains the 3 space-separated integers $A, B,$ and $C$.
