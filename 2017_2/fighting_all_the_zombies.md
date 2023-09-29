# Problem

At last, your power knows no bounds! Within the world of the ever-popular role-playing game Dungeons & Dragons, or D&D, you've managed to become one of the most powerful wizards to have ever wizarded.

And yet, you're still not content — you feel compelled to continue grinding away, repeatedly destroying monsters to ever so slowly increase your power further. There's a particular cave which contains $N$ zombies, and these zombies respawn every time you reenter the cave. As such, you can efficiently gain experience by entering, destroying all of them, and leaving, repeating this process infinitely (or until your supply of Hot Pockets runs out). The $n$-th zombie has a power level of $n$.

Conveniently, you're also carrying $N$ wands with you, the $n$-th of which has a power level of $n$. Each time you enter the cave, you'll use each of your wands exactly once to cast a spell and destroy a single zombie, such that all $N$ zombies are defeated. Initially, you know $N$ different spells, the $n$-th of which allows your wand with power level $n$ to target the zombie with power level $n$.

You're going to visit the cave $M$ times today. Before each visit, you're going to learn some new spells (which you'll continue to be able to use for all of your remaining visits). In particular, before your $i$-th visit, you'll acquire $S_i$ different new spells, each of which allows your wand with power level $W_i$ to target the zombie with power level of $Z_i$. Wands are unable to affect zombies which are much more powerful than them, and it would be a waste to use a wand on a zombie much weaker than it. As such, $|W_i - Z_i| ≤ 1$ holds for all spells. Note that all spells are considered distinct, even if several of them allow a particular wand to target a particular zombie.

On each of your $M$ visits to the cave, you're interested in the number of different ways in which you can defeat all $N$ zombies, using only the spells that you've learned up to that point. Two ways are considered different if at least one spell is used in one of them but not the other. These quantities can get rather large, and you don't want to deal with $M$ big numbers, so you only care about computing their sum modulo $10^9 + 7$.

You're given $W_1$, and $W_{2..M}$ may then be calculated as follows, using given constants $A_w$ and $B_w$:

$W_i = ((A_w \times W_{i-1} + B_w) \mod N) + 1$

A temporary sequence of values $D_{1..M}$ will be used to help calculate $Z_{1..M}$. You're given $D_1$, and $D_{2..M}$ may then be calculated as follows, using given constants $A_d$ and $B_d$:

$D_i = (A_d \times D_{i-1} + B_d) \mod 3$

From these values, $Z_{1..M}$ may then be calculated as follows:

$Z_i = \max\{ 1, \min \{ N, W_i + D_i - 1\} \}$

Finally, you're given $S_1$, and $S_{2..M}$ may then be calculated as follows, using given constants $A_s$ and $B_s$:

$S_i = ((A_s \times S_{i-1} + B_s) \mod 10^9) + 1$

## Input

Input begins with an integer $T$, the number of different caves you'll visit. For each cave, there are four lines.  
The first line contains the two space-separated integers $N$ and $M$.  
The second line contains the three space-separated integers $W_1$, $A_w$, and $B_w$.  
The third line contains the three space-separated integers $D_1$, $A_d$, and $B_d$.  
The fourth line contains the three space-separated integers $S_1$, $A_s$, and $B_s$.
