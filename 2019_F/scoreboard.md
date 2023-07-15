# Problem

The 2019 Hacker Cup Finals have just concluded! There were $N$ participants (numbered $1$ to $N$), including yourself (competing as participant $1$), and $M$ problems (numbered $1$ to $M$).

Participant $i$ solved problem $j$ if $S_{i,j} =$ "Y", and otherwise they didn't solve it (if $S_{i,j} =$ "N"). Problem $i$'s point value is $2i$, and each participant's score is the sum of the point values of the problems that they solved. No two participants solved exactly the same set of problems, which also means that all participants have distinct scores.

Before the final results get announced, you have an opportunity to rearrange the $M$ columns of the scoreboard $S$ into any permutation of problems $1$ to $M$. For example, if you swap columns $1$ and $2$, then everybody who had originally solved problem $1$ will now be considered to have solved problem $2$ (thus earning $4$ points for it rather than $2$), and vice versa.

Of course, you'd like to use this opportunity to your benefit — it would be irresponsible to just let it pass by! However, it would be too suspicious if you simply made yourself win the whole competition. As such, you'd like to cause yourself to end up in 2nd place, such that you (participant $1$) have exactly the second-highest score out of all $N$ participants. Now you just need to determine whether or not this is achievable...

## Input

Input begins with an integer $T$, the number of scoreboards.  
For each scoreboard, there is first a line containing the space-separated integers $N$ and $M$.  
Then, $N$ lines follow, the $i$-th of which contains a length-$M$ string, the characters $S_{i,1}$ through $S_{i,M}$.
