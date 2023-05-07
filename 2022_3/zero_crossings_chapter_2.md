# Problem

Note: The only difference between this and Chapter 1 is that here, marble locations depend on previous answers.

There are $N$ rubber bands on an infinite 2D peg board. The $i$-th rubber band is initially shaped as a convex polygon of $M_i$​ integer vertices, $(X_{i,1}, Y_{i,1}),\ldots,(X_{i,M_i}, Y_{i,M_i})$ in clockwise order. No two rubber bands touch or cross each other, though each rubber band may be fully enclosed in another. Other than their initial layout, all rubber bands look identical.

You are given $Q$ queries, the $i$-th of which involves a red and blue marble shaped as a circle with radius $1$, centered at points $(A_i, B_i)$ and $(C_i, D_i)$ respectively. The marbles do not touch each other, or any rubber bands. Formally, $(A_i, B_i)$ and $(C_i, D_i)$ are more than $2$ units away from each other, and each more than $1$ unit away from any rubber band.

Query $i$ asks whether you can roll the marbles and continuously move/deform rubber bands so:

- the red marble ends up at $(C_i, D_i)$,
- the blue marble ends up at $(A_i, B_i)$,
- the final state of all rubber bands looks identical to the initial state (one rubber band may end up in place of another, but must end up having the exact same vertices), and
- rubber bands never touch/cross, and the marbles never touch each other or any rubber band.

Let $R_i = 1$ if the answer to the $i$-th query is "yes", else $R_i = 0$. Please find the sum of $R_1, ..., R_Q$​.

You'll only be given $A_1, B_1, C_1​, D_1$​ directly, and must compute the remaining query points given values $A_i'​, B_i​', C_i'​, D_i'$​ for $i \gt 1$ along with an array $E_{1..Q}$​, as follows:

$A_i\ := A_i'\ \oplus \ (R_1*E_1)\ \oplus \,\cdots\, \oplus\ (R_{i-1}*E_{1-1})$

where $\oplus$ is the bitwise XOR operator, with $B_i$​, $C_i$​, and $D_i$​ computed similarly. In other words, if the answer to the $i$-th query is "yes", XOR all future query coordinates by $E_i$​.
