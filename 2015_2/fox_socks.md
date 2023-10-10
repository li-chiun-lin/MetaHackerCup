# Problem

Mr. Fox sure loves his socks! He stores his many indistinguishable socks in a set of $N$ bins, which are arranged in a circle and numbered in clockwise order. For every $1 ≤ i < N$, the next bin clockwise of bin $i$ is bin $i+1$, and the next bin clockwise of bin $N$ is bin $1$. Initially, the $i$-th bin contains $S_i$ socks.

Never being quite satisfied with his sock collection, Mr. Fox would like to perform $M$ operations on it, one after another. Each operation $i$ may be of one of the following 4 types, determined by the value of $O_i$:

1. Given integers $A_i, B_i, C_i,$ and $D_i$, add $C_i + 0 \times D_i$ socks to bin $A_i$, add $C_i + 1 \times D_i$ socks to the next bin clockwise of bin $A_i$, add $C_i + 2 \times D_i$ to the next bin clockwise of that one, and so on until this has been done for $B_i$ bins. Determine the total number of socks added in this process.

1. Given integers $A_i, B_i,$ and $C_i$, remove all of the socks from bin $A_i$ and then add $C_i$ socks to it. Do the same for the next bin clockwise of $A_i$, and so on until this has been done for $B_i$ bins. Determine the sum of two values: the total number of socks removed in this process, and the total number of socks added in this process.

1. Given integers $A_i$ and $B_i$, count the number of socks in bin $A_i$ (without removing them), the number of socks in the next bin clockwise of $A_i$, and so on until the socks in $B_i$ bins have been counted. Determine the total number of socks counted in this process.

1. Given integers $A_i$ and $B_i$, check if bin $A_i$ contains an odd number of socks. Do the same for the next bin clockwise of $A_i$, and so on until this has been done for $B_i$ bins. Determine the total number of these bins that contain an odd number of socks.

Can you help Mr. Fox keep track of his socks? Note the value calculated during each of the $M$ operations as they're performed, and then output the sum of all $M$ of the values modulo $10^9$.

## Input

Input begins with an integer $T$, the number of sock collections Mr. Fox has.  
For each sock collection, there are 7 lines containing the following space-separated integers:

$N$ $M$  
$S_1$ $S_2$ $X_S$ $Y_S$ $Z_S$  
$O_1$ $O_2$ $X_O$ $Y_O$ $Z_O$  
$A_1$ $A_2$ $X_A$ $Y_A$ $Z_A$  
$B_1$ $B_2$ $X_B$ $Y_B$ $Z_B$  
$C_1$ $C_2$ $X_C$ $Y_C$ $Z_C$  
$D_1$ $D_2$ $X_D$ $Y_D$ $Z_D$  

The first two elements of each sequence of integers ($S, O, A, B, C,$ and $D$) are given, and the rest are computed with the following pseudorandom generators:

$S_i = (X_S \times S_{i-2} + Y_S \times S_{i-1} + Z_S) \mod 10^9$, for $3 ≤ i ≤ N$  
$O_i = ((X_O \times O_{i-2} + Y_O \times O_{i-1} + Z_O) \mod 4) + 1$, for $3 ≤ i ≤ M$  
$A_i = ((X_A \times A_{i-2} + Y_A \times A_{i-1} + Z_A) \mod N) + 1$, for $3 ≤ i ≤ M$  
$B_i = ((X_B \times B_{i-2} + Y_B \times B_{i-1} + Z_B) \mod N) + 1$, for $3 ≤ i ≤ M$  
$C_i = (X_C \times C_{i-2} + Y_C \times C_{i-1} + Z_C) \mod 10^9$, for $3 ≤ i ≤ M$  
$D_i = (X_D \times D_{i-2} + Y_D \times D_{i-1} + Z_D) \mod 10^9$, for $3 ≤ i ≤ M$  
