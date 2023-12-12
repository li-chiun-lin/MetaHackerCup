# Problem

Alice and Bob like to play cards on their lunch break. Their favorite card game starts with two decks on the table containing $K_1$​ and $K_2$​ cards. Players take turns, with Alice going first. Each turn is in two parts:

1. The player selects a deck of cards from the table. Let $k$ be the number of cards in that deck. They then remove somewhere between $A_k$​ and $B_k$​ $(1≤Ak≤Bk≤k)$, inclusive, cards from this deck.
1. The player then puts a new deck of exactly $C_k$​ $(0≤Ck<k)$ cards on the table. Here, $C_k=0$ means no deck is added.

The player who takes the last card wins.

For each possible value of $K_1$​ from $1$ to a given value $N$, find the minimum possible value of $K_2$​ so that Bob wins the game if both players play optimally. If there is no such $K_2$​ between $1$ and $N$, then $K_2=−1$. Output the sum of $K_2$​ across every $K_1=1..N$.

To reduce the input size, you will not be given $A_{1..N}$​, $B_{1..N}$​, and $C_{1..N}$​ directly. You must instead generate them using parameters $X_a​, Y_a​, Z_a​, X_b​, Y_b​, Z_b​, X_c​, Y_c​,$ and $Z_c$​ and the algorithm below:

$P_a[0]:=0$  
$P_b[0]:=0$  
$P_c[0]:=0$  
for each $i:=1..N$:  
$P_a[i]:=(P_a[i−1]∗X_a+Y_a) \mod Z_a$  \
$P_b[i]:=(P_b[i−1]∗X_b+Y_b) \mod Z_b$  ​\
$P_c[i]:=(P_c[i−1]∗X_c+Y_c) \mod Z_c$ ​ \
$A[i]:=\min(i,1+P_a[i])$    \
$B[i]:=\max(A[i],i−P_b[i])$ \
$C[i]:=\min(i−1,P_c[i])$    \

Note that for any $i$, the algorithm guarantees $1≤A_i≤B_i≤i$ and $0≤C_i<i$.

## Input

Input begins with a single integer $T$, the number of test cases.  
For each case, first there is a line containing a single integer $N$.  
Then, there is a line containing integers $X_a​, Y_a​, Z_a​, X_b​, Y_b​, Z_b​, X_c​, Y_c​,$ and $Z_c$​.
