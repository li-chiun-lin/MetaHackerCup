# Problem

Meta Getaways is a travel agency that deals with $N$ airports numbered $1 \dots N$, and $M$ flight paths. Flight path $i$ connects airports $A_i$​ and $B_i$​ in both directions, with two direct flights operating every morning (one in each direction), and another two every evening (also one in each direction). Each of these four direct flights can carry up to $C_i$​ tourists.

Peak travel season is here, and will last $Q$ days. For each day $i$, determine $F_i$​, the maximum number of tourists who could possibly fly from airport $X_i$​ to $Y_i$​. Each tourist may either fly directly or take one morning and one evening flight which share an intermediate airport.

## Input

Input begins with a single integer $T$, the number of test cases.  
For each case, there is first a line containing three space-separated integers $N$, $M$, and $Q$.  
Then, $M$ lines follow, the $i$-th of which contains three space-separated integers $A_i$​, $B_i$​, and $C_i$​.  
Then, $Q$ lines follow, the $i$-th of which contains two space-separated integers $X_i$​ and $Y_i$​.
