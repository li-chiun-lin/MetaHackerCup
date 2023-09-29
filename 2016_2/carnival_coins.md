# Problem

At the local carnival you find a midway game advertising "TONS OF FABULOUS PRIZES". Certainly a fabulous prize or two would make your time worthwhile. It turns out that "TONS" is actually a bit of an understatement. There are in fact infinitely many prizes available. Consequently, the game operator is willing to give you a chance to score multiple prizes in a single game (for a nominal fee).

After you hand over your money, the game operator gives you $N$ coins. Each coin has the same probability $p$ of landing on heads when flipped (and consequently probability $1 - p$ of landing on tails). She also gives you a goal, an integer $K$.

As long as you still have some coins remaining, you can select any number of them and flip them all simultaneously. These coins are then taken away. If at least $K$ of them land on heads, you win a prize. If you play optimally, what is the expected number of prizes you'll manage to win?

## Input

Input begins with an integer $T$, the number of times you play the game.  
For each attempt, there is a line containing the space-separated values $N$, $K$ and $p$. $N$ and $K$ are integers, and $p4 is given with at most 16 decimal places.
