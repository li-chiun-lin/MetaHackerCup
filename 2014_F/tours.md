# Problem

Facebook HQ -- a mysterious place full of magical code and trade secrets. If outsiders were ever to breach the walls of the compound, which are protected by a legion of security foxes, the entire company could well be brought to its knees!

Hmmm. Actually, campus tours are given regularly.

The compound consists of $N$ buildings, with $M$ walkways running amongst them. The $i$-th walkway connects buildings $A_i$ and $B_i$, ($A_i \ne B_i$) and no two buildings are directly connected by more than one walkway. There are no other ways to move from building to building.

Over a period of $D$ days, some events will occur at Facebook HQ. One of two types of events will happen on the $i$-th day, indicated by a character $E_i$. If $E_i =$ 'T', then a tour will take place. Otherwise, $E_i =$ 'S', and a security sweep of one building will take place.

If a tour is given on the ith day, visitors will plan to enter the compound at building $X_i$, and leave from building $Y_i$ ($X_i \ne Y_i$). If it turns out that these two buildings are not actually connected by any sequence of walkways, then the tour will be cancelled, and the unfortunate visitors will be given Facebook T-shirts on the way out. Otherwise, a large number of people will be led from building $X_i$ to building $Y_i$ along various routes. No route will involve travelling along the same walkway multiple times (even in different directions), but a route might revisit the same building repeatedly, including buildings $X_i$ and $Y_i$. Along the way some visitors will inevitably get themselves "lost", and fail to rejoin the tour group. In total, $O_i$ new outsiders will be left behind in each building which could possibly be part of any valid tour route from building $X_i$ and building $Y_i$. Good thing they'll no doubt have brought cameras to amuse themselves with while they wait to be found.

On the other hand, if a security sweep is conducted on the $i$-th day, then the security foxes will carefully search building $Z_i$ for any trespassers remaining from previous tours, and kindly escort them out.

Since Facebook likes data, you've been hired to record how many outsiders were found in each sweep.

## Input

Input begins with an integer $T$, the number of test cases.  
Each test case begins with a line containing three integers, $N, M,$ and $D$.  
The next $M$ lines contain two integers $A_i$ and $B_i$.  
The next $D$ lines contain a character $E_i$, followed by either three integers $X_i, Y_i, O_i$ if $E_i =$ 'T', or a single integer $Z_i$ if $E_i =$ 'S'.
