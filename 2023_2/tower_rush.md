# Problem

Alice and Bob are playing Tower Rush, a two-phase game involving $N$ types of blocks, numbered from $1$ to $N$. Blocks of type $i$ have height $H_i$​, and no two types of blocks have the same height.

Phase 1 of the game consists of $K≥2$ alternating turns, with Alice going first. On each player's turn, they will choose a block type that has not yet been chosen. Note that if $K$ is odd, this phase would end with Alice having chosen one more type of block than Bob. From this point on, players have access to infinitely many blocks of each of the types they chose.

Phase 2 consists of an indefinite number of alternating turns, with Bob going first. Each player starts with a tower of height $0$. On each player's turn, they may pick a block of any type $i$ available to them, and extend their tower height by $H_i$​. They may also choose to skip their turn, leaving their tower unchanged.

In a break from tradition, Alice and Bob want to work together to see if it's possible for Alice to build a tower that's exactly $D$ units taller than Bob's. In how many different ways can phase 1 be played out such that it will be possible for Alice to get her tower to be exactly $D$ units taller than Bob's in phase 2? Two ways are considered different if there exists an $i$ such that different block types are chosen on turn $i$ between the two ways.

As this value may be large, output it modulo $1,000,000,007$.

## Input Format

Input begins with an integer $T$, the number of test cases.  
For each case, the first line contains the integers $N, K,$ and $D$.  
Then, there is a line containing the $N$ integers $H_1​, ..., H_N$​.
