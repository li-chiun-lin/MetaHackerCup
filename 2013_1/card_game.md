# Problem

John is playing a game with his friends. The game's rules are as follows: There is deck of $N$ cards from which each person is dealt a hand of $K$ cards. Each card has an integer value representing its strength. A hand's strength is determined by the value of the highest card in the hand. The person with the strongest hand wins the round. Bets are placed before each player reveals the strength of their hand.

John needs your help to decide when to bet. He decides he wants to bet when the strength of his hand is higher than the average hand strength. Hence John wants to calculate the average strength of ALL possible sets of hands. John is very good at division, but he needs your help in calculating the sum of the strengths of all possible hands.

You are given an array $a$ with $N ≤ 10,000$ different integer numbers and a number, $K$, where $1 ≤ K ≤ N$. For all possible subsets of a of size $K$ find the sum of their maximal elements modulo $1,000,000,007$.

## Input

The first line contains the number of test cases $T$.  
Each case begins with a line containing integers $N$ and $K$.  
The next line contains $N$ space-separated numbers $a[i]$, which describe the array $a$.
