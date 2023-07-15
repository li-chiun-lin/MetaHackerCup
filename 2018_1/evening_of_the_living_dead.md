# Problem

A quiet evening has set over a residential area. As families sit down for supper in the safety of their homes, a calm atmosphere permeates the outside air. The neighborhood feels truly at peace, separated from the frenzy of the rest of the world. Also, a bunch of zombies have just risen out of the ground and want to eat everybody.

The neighborhood has $N$ yards in a row, numbered from $1$ to $N$. There are also $N-1$ fences, one between each pair of adjacent yards. The fence between yards $i$ and $i+1$ has an unknown integral height drawn uniformly at random from the inclusive interval $[A_i, B_i]$. In other words, the ith fence has $B_i - A_i + 1$ possible heights, each of which is equally likely.

$M$ hungry zombies are also present, with the $i$-th of them initially in yard $Y_i$. Fortunately for the zombies, they might not be stopped by the surrounding fences so easily. The $i$-th zombie has the ability to climb over any fence with a height of at most $H_i$. It may repeatedly move from its current yard to an adjacent one, as long as the fence between the yards is no taller than $H_i$. Multiple zombies may start in the same yard, and multiple zombies may occupy the same yard at any point.

A yard is considered "safe" if it's impossible for any zombies to ever reach it. Determine the probability that at least one of the $N$ yards is safe. Let this probability be represented as a quotient of integers $p/q$ in lowest terms. Output the value of this quotient modulo $10^9 + 7$ — in other words, output the unique integer $x$ such that $0 \leq x < 10^9 + 7$ and $p = x \times q \mod 10^9 + 7$.

## Input

Input begins with an integer $T$, the number of neighborhoods.  
For each neighborhood, there is first a line containing the space-separated integers $N$ and $M$.  
Then, $N-1$ lines follow. The $i$-th of these lines contains the space-separated integers $A_i$ and $B_i$.  
Then, $M$ lines follow. The $i$-th of these lines contains the space-separated integers $Y_i$ and $H_i$.
