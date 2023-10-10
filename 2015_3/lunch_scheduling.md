# Problem

James and Wilson are the best of buddies. And, conveniently enough, they both work at Corpro Corp! Every day, they have the opportunity to eat lunch together, while talking about how well their favourite sports teams are doing and how strict their managers are. However, their work obligations can often get in the way of that.

At Corpro Corp, each workday is $80,000,000$ milliseconds long, and the company uses the phrase "time $t$" to refer to the moment in time $t$ milliseconds after the start of the workday. All employees arrive at time $0$, and leave at time $80,000,000$.

On a certain day, James gets invited to $J$ optional meetings. The $i$-th of these meetings starts at time $A_i$ and ends at time $B_i$. Similarly, Wilson gets invited to $W$ optional meetings, with the $i$-th one starting at time $C_i$ and ending at time $D_i$. All $J+W$ meetings might arbitrarily overlap with one another.

Both James and Wilson may choose to accept any subset of their invitations, possibly none of them or all of them. The meetings are all conducted virtually, making it possible to attend multiple meetings at the same time — as such, two invitations may be accepted even if their time ranges overlap.

As it turns out, James and Wilson actually hate having lunch together, but they feel obligated to do so if they're able to. Eating lunch takes exactly $L$ milliseconds, and so the two friends will meet up for lunch if there's a consecutive interval of at least $L$ milliseconds within their work hours during which neither of them is taking part in any meetings.

Less surprisingly, James and Wilson hate attending meetings. If James accepts $x$ of his $J$ invitations, and Wilson accepts $y$ of his $W$ invitations, then the combined inconvenience they experience is $\max(x, y)$. Determine whether or not it's possible for them to avoid having to eat lunch together — and, if so, determine the minimum combined inconvenience they must incur to do so.

## Input

Input begins with an integer $T$, the number of days James and Wilson go to work.  
For each day, there is first a line containing the space-separated integers $J$, $W$, and $L$.  
Then, $J$ lines follow, the $i$-th of which contains the space-separated integers $A_i$ and $B_i$.  
Then, $W$ lines follow, the $i$-th of which contains the space-separated integers $C_i$ and $D_i$.
