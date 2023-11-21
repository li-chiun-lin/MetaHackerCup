# Problem

Note: The only difference between this and Chapter 1 is that here, you must find the sum of answers for $K = 1..N$.

Boss Rob ain’t Som Tawyer, but he can paint a fence alright.

Rob's fence is made of $N$ wooden stakes, numbered $1$ to $N$ from left to right. Initially (at time $0$), the $i$-th stake is of color $i$. There is a fencepost before stake $1$ and after stake $N$, as well as after every $K$-th stake starting from the left.

Rob has a simple and joyful plan to repaint his fence, consisting of $M$ moments in time. At time $i$, he'll repaint all stakes which are color $A_i$​ to color $B_i$​. Doing so, when would be the first time that all pairs of stakes not separated by a fencepost have the same color? If it will never occur, consider the answer to be $-1$.

Rob is still on the fence about the value of $K$, so please print the sum of answers over $K = 1..N$. Sorry for the pun (we know there is a lot at stake in this round gating the finals). In our de​fence, it makes for good post-problem content.

## Input

Input begins with an integer $T$, the number of test cases.  
For the $i$-th test case, there is first a line containing two space-separated integers $N$ and $M$.  
Then, $M$ lines follow, the $i$-th of which contains two space-separated integers $A_i$​ and $B_i$​.
