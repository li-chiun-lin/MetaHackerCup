# Problem

A rich, retired programmer has decided to invest his (possibly) massive savings into constructing custom yachts for himself.

Initially, he has a real amount of dollars, chosen uniformly at random from the range $[A, B]$. Constructing a yacht consists of $N$ sequential steps, with the $i$-th step requiring $C_i$ dollars.

The programmer blindly pays for the steps in order, until he's either completed all of them, or can't afford the cost of the next step. If the former occurs, he puts his completed yacht aside and restarts the process from the first step with his remaining money - he wants as many yachts as possible! Otherwise, in the latter case, he immediately stops his project entirely, without spending any additional money on other steps.

What's the expected amount of money which the programmer will be left with once he stops spending it on yachts? Your output should have at most $10^{-6}$ absolute or relative error.

## Input

Input begins with an integer $T$, the number of times the programmer embarks on a yacht-creation spree.  
For each spree, there is first a line containing the space-separated integers $N$, $A$, and $B$ in that order, then a line containing $N$ space-separated integers, the $i$-th of which is $C_i$.
