# Problem

Note: The only difference between this chapter and chapter 2 is that here, coordinates are only up to $\mathbf{3{,}000}$.

Boss Rob just planted $N$ happy little trees in his yard, which can be represented on a Cartesian plane. The $i$-th tree is located at coordinates $t_i = (A_i, B_i)$. Now, he's looking for the best spot to build a well in order to provide water to them. He considers the inconvenience of a potential well location ppp to be the sum of the squared Euclidean distances to every tree:

$\sum_{i=1}^{N} \Vert \,p - t_i \Vert ^ 2$

Rob wants to pick a location for his well, well... well. Help him determine the inconvenience for $Q$ different potential well locations, $(X_1, Y_1), ..., (X_Q, Y_Q)$. To reduce output size, please print the sum of inconveniences for all potential well locations, modulo $1{,}000{,}000{,}007$.

## Input

Input begins with a single integer $T$, the number of test cases.  
For each case, there is first a line containing a single integer $N$.  
Then, $N$ lines follow, the $i$-th of which contains two space-separated integers $A_i$​ and $B_i$​.  
Then there is a line containing a single integer $Q$.  
Then, $Q$ lines follow, the $i$-th of which contains two space-separated integers $X_i$​ and $Y_i$​.
