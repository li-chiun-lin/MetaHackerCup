# Problem

$N$ pairs of friends are standing in two lines of $N$ people each, waiting to go through an airport security checkpoint. The $i$-th passenger in the first line (counting from the front) belongs to pair $A_i$, while the $i$-th passenger in the second line belongs to pair $B_i$. In the $2N$ integers $A_{i..N}$, and $B_{i..N}$, each value from $1$ and $N$ appears exactly twice. A pair of friends might be standing in the same line or in different lines.

Every minute, the first person in one of the two lines will be admitted through security. If one of the lines is already empty, then the person at the front of the other line will necessarily be admitted. This process will go on for $2N$ minutes, until both lines have been exhausted. Some people are much slower than others at the tedious process of removing their shoes and belts, placing their laptops in separate bins, and so on. As such, it's unclear which line will be chosen to advance in each minute.

When a passenger passes through security, they will wait just past the checkpoint for their friend (the other person in their pair) to also make it through. If their friend has already made it through first, then the two of them will immediately proceed to their gate. As such, if a pair of friends pass through security after $a$ and $b$ minutes respectively, they will be able to head to their gate after $\max(a, b)$ minutes. However, everyone hates standing around after security for too long! If anyone is forced to wait for their friend for more than $2$ minutes (that is, $\max(a, b) > \min(a, b) + 2)$, then they'll throw a fit and the entire airport will be closed down.

Assuming that everyone is satisfied and manages to get through security without closing down the airport, sorting the pairs of friends by the times at which they proceed to their gates yields a permutation of $N$ pair numbers. How many such pair orders are possible (modulo $1,000,000,007$)?

In order to reduce the size of your input file, you're given $A_1$, and $A_{2..N}$ can be calculated as follows:

$A_i = A_{i-1} + D_{A,i-1}$

In order to compute the sequence $D_{A,1..(N-1)}$, you're given $K_A$ other sequences, the $i$-th of which consists of $L_{A,i}$ elements $S_{A,i,1..L_{A,i}}$, and has an associated repetition number $R_{A,i}$. The sequence $D_{A,1..(N-1)}$ can then be constructed by concatenating together $K_A$ sequences, the $i$-th of which consists of the sequence $S_{A,i,1..L_{A,i}}$ repeated $R_{A,i}$ times. It's guaranteed that the concatenation of these repeated sequences has exactly $N - 1$ elements (in other words, the sum of the products $L_{A,i} \times R_{A,i}$ for $i = 1..K_A$ is equal to $N - 1$).

In the same way, you're given $B_1$, and $B_{2..N}$ can be calculated using the sequence $D_{B,1..(N-1)}$, which in turn can be calculated by concatenating together $K_B$ sequences, the $i$-th of which consists of $R_{B,i}$ copies of the sequence $S_{B,i,1..L_{B,i}}$.

## Input

Input begins with an integer $T$, the number of different airports. For each airport, there is first a line containing the integer $N$.

There is then a line with two space-separated integers $A_1$ and $K_A$. Then there are $K_A$ lines, the $i$-th of which contains two space-separated integers $R_{A,i}$ and $L_{A,i}$, followed by $L_{A,i}$ more space-separated integers, the $j$-th of which is $S_{A,i,j}$.

Similarly, there is then a line with two space-separated integers $B_1$ and $K_B$. Then there are $K_B$ lines, the $i$-th of which contains two space-separated integers $R_{B,i}$ and $L_{B,i}$, followed by $L_{B,i}$ more space-separated integers, the $j$-th of which is $S_{B,i,j}$.
