# Problem

At last, Mr. X has managed to return to the school at which he formerly taught, with the intention of confronting his suspicious successor, Mr. Y. However, it appears that Mr. Y has fortified his position — he has brainwashed all of his students into believing that he's the world's best teacher through the timeless ploy of replacing classes with extra recesses. There's no way that Mr. Y can be thrown out of the school without first compromising his students' support!

There are $N$ students in Mr. Y's class, with IDs from $1$ to $N$. In an attempt to maximize security, Mr. Y has arranged them into a hierarchical structure, with each student $i$ either reporting to a commanding student $C_i$, or not reporting to any other student (indicated by $C_i = 0$). There's exactly one student $i$ for whom $C_i = 0$, who is the class leader.

A chain of command is a sequence of one or more students going up the hierarchical structure starting from some student $i$ and ending somewhere between $i$ and the class leader (inclusive): $i → C_i → C_{C_i} →$ etc. It's guaranteed that, for each student $i$, there exists a chain of command beginning at them and ending at the class leader.

Initially, all $N$ students are under Mr. Y's control. However, Mr. X is about to perform some bribery of his own. One by one, in order from $1$ to $N$, Mr. X will bribe each student with healthy snacks. After the first $b$ bribes, students $1..b$ will be under Mr. X's control instead of Mr. Y's.

After each of the $N$ bribes, Mr. X would like to evaluate the vulnerability of Mr. Y's class to a potential takeover. To do so, he'll determine $N$ hypothetical values: for each student $i$, he'll compute the maximum length that a controlled chain beginning with student $i$ could possibly have if $0$ or more promotions were to first take place (or $0$ if no such chain could exist).

A controlled chain is a chain of command consisting exclusively of students under Mr. X's control. A promotion is a modification to the class structure in which Mr. X selects a certain student $j$ with a commanding student $c = C_j$ (such that $c ≠ 0$ and $c ≠ i$), expels student $c$ (removing them from the class entirely), and brings $j$ up to occupy $c$'s former place (setting $C_j$ to $C_c$, and for each other student $k$ such that $C_k = c$, now setting $C_k$ to $j$). Note that each of these hypothetical values should be considered independently of the others; Mr. X will never actually perform any promotions and permanently alter the class structure.

In order to reduce the size of the output, these $N^2$ values should be aggregated into a single integer as follows: Letting $S_b$ be the sum of the $N$ students' maximum controlled chain lengths after the first $b$ students have been bribed, output $(S_1 \times S_2 \times ... \times S_N)$ modulo $1,000,000,007$.

## Input

Input begins with an integer $T$, the number of times Mr. X needs to wrest control from Mr. Y.  
For each time, there is first a line containing the integer $N$.  
Then, $N$ lines follow, the $i$-th of which contains the integer $C_i$.
