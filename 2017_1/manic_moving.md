# Problem

Thanks to his tireless hard work, Wilson has been promoted and now gets to drive his moving company's trucks! No, he can't believe it either.

The moving company services a region that has $N$ towns, with $M$ roads running amongst them. The $i$-th road connects two different towns $A_i$ and $B_i$, requires $G_i$ litres of gas to drive along, and can be traversed in either direction. There may be multiple roads running directly between any given pair of towns.

Today, Wilson has been scheduled to transport $K$ families' belongings. The $i$-th family is moving from town $S_i$ to a different town $D_i$. Wilson and his truck will be starting off the day at the company headquarters in town $1$. For each family, he'll need to drive to their starting town by following a sequence of roads, load his truck there, and at some point later, arrive at their destination town to unload their belongings. His truck is large enough to fit at most 2 families' sets of belongings at a time, meaning that he doesn't necessarily need to deliver each load immediately after picking it up.

However, Wilson has been instructed that the $K$ families must be helped strictly in order. In particular, if $i < j$, then the $i$-th family's belongings must be loaded before the $j$-th family's belongings are loaded, and the $i$-th family's belongings must be delivered before the $j$-th family's belongings are delivered.

Although Wilson's wages are higher than ever, he does have to pay for the truck's gas out of his own pocket, so it's in his best interest to get the job done while burning through as little of it as possible. Of course, he'll still need to be careful to follow his company's strict rules regarding the relative order of the families' loads and unloads, to avoid getting fired. That being said, it's a possibility for it to be impossible to even complete all of the requested moves, in which case Wilson will simply call it a day and stay home instead.

## Input

Input begins with an integer $T$, the number of sets of families Wilson needs to move.  
For each case, there is first a line containing three space-separated integers, $N$, $M$, and $K$.  
Then, $M$ lines follow, the $i$-th of which contains 3 space-separated integers, $A_i$, $B_i$, and $G_i$.  
Then, $K$ lines follow, the $i$-th of which contains 2 space-separated integers, $S_i$ and $D_i$.
