# Problem

It's time to serve some sushi! You're preparing an omakase sushi platter will contain $N$ pieces of nigiri and $M$ pieces of sashimi, to be eaten in a specific order. Each piece has a distinct tastiness value. The $i$-th piece of nigiri has tastiness $A_i$​, and the $i$-th piece of sashimi has tastiness $B_i$​.

The final platter combines and rearranges these $n=N+M$ pieces in some permutation $P$ with the $i$-th piece having tastiness $P_i$​.

The customer will appreciate the platter more if consecutive pieces of sushi do not differ too much in tastiness. To evaluate this, you've defined the "unevenness score" of $P$ as:

$S(P)=∣P_1−P_2∣+…+∣P_i−P_{i+1}∣+…+∣P_{n−1}−P_n∣$

You'd like to know how many permutations $P$ of the combined sushi pieces exist such that $S(P)≤L$. As this number may be very large, output it modulo $1,000,000,007$.

## Input Format

Input begins with an integer $T$, the number of test cases.
The first line of each case contains the three integers $N$, $M$, and $L$.
The second line of each case contains the $N$ integers $A_{1..N}$​.
The third line of each test case contains the $M$ integers $B_{1..M}$​.
