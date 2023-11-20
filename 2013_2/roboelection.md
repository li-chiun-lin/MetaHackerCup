# Problem

In the not so distant future the world is populated by robots and ruled by an evil robot emperor. Every robot in the world can be identified by a unique numeric ID, and the list of all the existing robot IDs is easily accessible to everyone. One day the emperor decided to call for a general election to preserve an illusion of democracy. He set it up in the following way:

- Every robot can cast at most one vote per round of voting and the votes are anonymous.
- The only option on the ballot is the vote for reelection of the emperor.
- If at least $P$ percent of the population cast votes for the emperor he becomes reelected for the next millennium.
- Otherwise the emperor declares the vote void, disassembles $K$ robots with the lowest ID numbers (who he finds to be the most rebellious), and then if there are any functional robots left he restarts the whole process.

All the robots are perfectly logical but also rather lazy and prone to procrastination. That's why after figuring out the plan of the emperor, they will abstain from voting unless they have to vote to survive the election (including this round and all later rounds). If they will die whether or not they vote, they will vote in the hope that the emperor will spare them. (He won't, because he's evil!).

Given  
$N$ - the initial population size,  
$K$ - the number of robots disassembled after an unsuccessful vote and  
$P$ - the required percentage of votes.

Compute the number of times the vote will take place.

## Input

The first line contains the number of test cases $T$.  
Each case is a single line with three space-separated integers $N$ $K$ $P$.
