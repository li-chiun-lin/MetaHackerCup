# Problem

You found a magic coin exchange machine which takes dollar bills and randomly dispenses coins among $N$ different denominations. As an avid coin collector with a stack of old dollar bills, you'd like to try to obtain at least one copy of each coin denomination.

If you insert 1 dollar bill, you'll get a random coin (with $1/N$ probability of getting any specific denomination). However, you can spend more in each exchange to increase the chance of getting a new denomination you don't have.

If you simultaneously insert $D$ dollar bills, you’ll get a $\min⁡((D−1)⋅P,100)$ percent chance of receiving a coin denomination you don’t yet have, and a $100−\min⁡((D−1)⋅P,100)$ percent chance of receiving a random coin.

If you optimally choose how many dollar bills to insert in each exchange, how many dollar bills will it take, on average, to collect one copy of every coin?

## Input Format

Input begins with an integer $T$, the number of test cases.
Each case is a single line with the integers $N$ and $P$.
