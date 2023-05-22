# Problem

The Facebook Whacker Cup is a series of ping-pong tournaments to find the best paddlers on the social network. A tournament consists of $N$ ping-pong players and $N−1$ elimination matches among them. The players are numbered from $1$ to $N$ in increasing order of skill.

In each match, two players will be randomly selected from the set of players still in contention (if there are $x$ players, then all $x(x−1)/2$ unordered pairs of them are equally likely to be selected). Those players will then play against each other, with the more skilled (higher-numbered) of the two winning with a probability of $P$. The loser will then be eliminated from the tournament, and will not be involved in any future matches. After $N−1$ such matches, there will be exactly one player remaining who will be declared the Whacker Cup champion!

For each player, determine the expected number of matches which will occur while they're still in contention (before they're either eliminated or the tournament concludes). This should include matches which they either directly compete in (including the one in which they lose and get eliminated), or which simply occur before they've been eliminated. Each of your answers must have at most $10^{−6}$ absolute or relative error to be considered correct.

## Input

Input begins with an integer $T$, the number of tournaments.  
For each tournament, there is one line containing the space-separated integer $N$ and real number $P$ (given with at most 3 digits after the decimal point).
