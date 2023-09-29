# Problem

Two chess grandmasters, Andrew and Jacob, are having an epic chess showdown to determine which of them is the uncontested best player in the world!

The showdown consists of $N$ games. In each game, one player plays as White and the other plays as Black. In the first game, Andrew plays as White. After each game, the player who loses it chooses which color they'll play as in the following game. However, the victor of the final game wins the entire showdown, regardless of the results of the previous games!

In each game, each player may decide to attempt to win or attempt to lose:

1. If both players play to win, then Andrew wins with probability $W_w$ if he plays as White (and loses with probability $1 - W_w$, as there are no draws at this high level of play). Similarly, he wins with probability $W_b$ if he plays as Black.
1. If both players play to lose (achieved by tipping over their own king as quickly as possible), then Andrew loses with probability $L_w$ if he plays as White, and loses with probability $L_b$ if he plays as Black.
1. If exactly one player wants to win a game, then he's guaranteed to win it.

Assuming both players play optimally in an attempt to win the showdown, what is Andrew's probability of besting Jacob?

## Input

Input begins with an integer $T$, the number of showdowns between Andrew and Jacob.  
For each showdown, there is first a line containing the integer $N$,  
then a line containing the space-separated values $W_w$ and $W_b$,  
then a line containing the space-separated values $L_w$ and $L_b$.  
These probabilities are given with at most 9 decimal places.
