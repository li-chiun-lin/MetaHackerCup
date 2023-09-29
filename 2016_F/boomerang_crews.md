# Problem

It's time to settle things once and for all. Your boomerang crew has decided to challenge their rivals to a boomerang crew battle!

Your crew has $N$ members with strengths $A_{1..N}$, while the opposing crew has $M$ members with strengths $B_{1..M}$. The crew battle will proceed as follows:

1. Each crew will arrange its members in a line, in some order.
1. A throwing contest will take place between the first person in your line, and the first person in your opponents' line.
1. Whoever loses the contest (see below for details) will leave their line permanently, while the winner will stay at the front of their line.
1. If one of the lines has become empty, that crew loses and the crew battle concludes.
1. Otherwise, back to step 2.

However, you're not about to play fair with your enemies — you've got the following 3 things going for you:

1. You will decide the initial ordering of members for both crews (in step 1 of the crew battle).
1. When a member of your crew with strength $S$ competes in a throwing contest, they'll throw their boomerang a distance of $S$ feet. On the other hand, due to a bit of subtle poisoning you've done in advance, your enemies will get tired after each throw. In particular, when a member of the rival crew with strength $S$ competes in a throwing contest, such that they've already competed in (and won) $C$ throwing contests previously, they'll throw their boomerang a distance of $\max \{S - C \times D, 1 \}$ feet (where $D$ is a set constant).
1. In each throwing contest, your crew's member will win if their throw distance is greater than or equal to their opponent's.

Despite these advantages, it's possible that you'll still be unable to emerge victorious. However, whether or not you do, you'd like to maximize the number of throwing contests that members of your crew win over the course of the crew battle (given that you choose optimal initial orderings for both lines).

## Input

Input begins with an integer $T$, the number of battles. For each battle, there are three lines.  
The first line contains the space-separated integers $N$, $M$, and $D$.  
The second line contains the $N$ space-separated integers $A_1$ to $A_N$.  
The third line contains the $M$ space-separated integers $B_1$ to $B_M$.
