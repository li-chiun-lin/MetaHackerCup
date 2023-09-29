# Problem

You've managed to become a contestant on the hottest new game show, The Price is Correct!

After asking you to come on down to the stage, the show's host presents you with a row of $N$ closed boxes, numbered from $1$ to $N$ in order, each containing a secret positive integer. A curtain opens to reveal a shiny, new tricycle — you recognize it as an expensive, top-of-the-line model.

The host then proceeds to explain the rules: you must select a contiguous sequence of the boxes (boxes $a..b$, for some $1 ≤ a ≤ b ≤ N$). Your chosen boxes will then be opened, and if the sum of the numbers inside is no greater than the price of the tricycle, you win it!

You'd sure like to win that tricycle. Fortunately, not only are you aware that its price is exactly $P$, but you've paid off the host to let you in on the contents of the boxes! You know that each box $i$ contains the number $B_i$.

How many different sequences of boxes can you choose such that you win the tricycle? Each sequence is defined by its starting and ending box indices ($a$ and $b$).

## Input

Input begins with an integer $T$, the number of times you appear on The Price is Correct.  
For each show, there is first a line containing the space-separated integers $N$ and $P$.  
The next line contains $N$ space-separated integers, $B_1$ through $B_N$ in order.
