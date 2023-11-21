# Problem

Note: The only difference between this and Chapter 2 is that here, you only need to find the answer for a single $K$.

Boss Rob ain’t Som Tawyer, but he can paint a fence alright.

Rob's fence is made of $N$ wooden stakes, numbered $1$ to $N$ from left to right. Initially (at time $0$), the $i$-th stake is of color $i$. There is a fencepost before stake $1$ and after stake $N$, as well as after every $K$-th stake starting from the left.

Rob has a simple and joyful plan to repaint his fence, consisting of $M$ moments in time. At time $i$, he'll repaint all stakes which are color $A_i$​ to color $B_i$​. Doing so, when would be the first time that all pairs of stakes not separated by a fencepost have the same color? If it will never occur, consider the answer to be $-1$.

## Input

Input begins with an integer $T$, the number of test cases.  
For the $i$-th test case, there is first a line containing three space-separated integers $N$, $M$, and $K$.  
Then, $M$ lines follow, the $i$-th of which contains two space-separated integers $A_i$​ and $B_i$​.
