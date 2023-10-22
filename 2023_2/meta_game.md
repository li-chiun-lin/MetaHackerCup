# Problem

Hacker Cup contest strategy often involves a metagame, where choosing which problems to work on might just be an important decision. On a Quest to become more Pro, you encounter an oracle promising to teach you the contest meta if you play her own Meta-game.

The oracle presents a peg board with $2N$ moving dots. The initial $y$-positions of the dots are given as two arrays $A_{1..N}$​ and $B_{1..N}$​. Each second, simultaneously, $A_1$​ will move to the end of $B$, while $B_1$​ will move to the end of $A$ (with all elements shifting left accordingly).

You can connect the dots to form a Meta-like logo if all of the following are true:

- For the first half of both arrays, each dot in $A$ is below the corresponding dot in $B$.
- For the last half of both arrays, each dot in $A$ is above the corresponding dot in $B$.
- $A$ equals the reverse of $B$.

Formally:

- $A_i<B_i$​ for every $i<(N+1)/2$
- $A_i>B_i$​ for every $i>(N+1)/2$
- $A_i=B_{N−i+1}$​ for every $i=1..N$

Note that if $N$ is odd, the arrays' middle elements are not subject to the first two constraints.

You must answer the oracle: how many seconds must pass before the first time a Meta-like logo appears? If one never appears, output $−1$.

## Input Format

Input begins with an integer $T$, the number of test cases.  
For each case, there is first a line containing a single integer $N$.  
Then, there is a line containing integers $A_1,...,A_N$​.  
Then, there is a line containing integers $B_1,...,B_N$​.
