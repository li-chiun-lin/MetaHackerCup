# Problem

A family of water spiders lives at a spring located on an earthquake hotspot. The spring features $N$ columns of rocks in a row, numbered $1$ to $N$ from left to right. Each rocky column $i$ has a width of $1$ cm and a height of $H_i$​ cm.

The spring always has some global water level. The rocky columns can each be below the water, at water level, or protrude above its surface. A spider in a given column must float on the surface of the water (if the rock is below water level) or stand atop the rock (if it's at or above water level). This means that, when the water level is $W$ cm, the effective elevation at column $i$ is $max(H_i,W)$ cm.

Water spiders sometimes want to travel from one column $a$ to another column $b$. This involves starting horizontally in the middle of column $a$, at its effective elevation, and walking along the outline of the effective elevations until ending up horizontally in the middle of column $b$. This may include walking left/right across the tops of rocks or the surface of the water, as well as up/down along the sides of the protruding rocks. Note that a spider's route will never take it left of column $1$, right of column $N$, below the surface of the water, nor into mid-air.

Unfortunately for the spring's inhabitants, frequent earthquakes occur, altering the heights of the rocky columns and the water. The spiders would like to survey the accessibility of the spring after each earthquake.

Specifically, $M$ earthquakes are about to occur, one after another. As part of the $i$-th earthquake, the height of each rocky column $c$ such that $X_i≤c≤min(X_i+Y_i−1,N)$ will become equal to $Z_i$​ cm, and the global water level will become $W_i$​ cm. After each earthquake $i$, the spiders are interested in the current sum of travel distances (in cm) over all $N∗(N−1)$ ordered pairs of starting and ending columns — we'll call this quantity $S_i$​.

Please determine the value of $(S_1∗S_2∗...∗S_M) \mod 10^9 + 7$.

In order to reduce the size of the input, the above values will not all be provided explicitly. Instead, you'll be given the first $K$ values $H_{1..K}​, X_{1..K}​, Y_{1..K}​, Z_{1..K}​,$ and $W_{1..K}$​, as well as the five quadruples of constants $(A_H,B_H,C_H,D_H), (A_X,B_X,C_X,D_X), (A_Y,B_Y,C_Y,D_Y), (A_Z,B_Z,C_Z,D_Z),$ and $(A_W,B_W,C_W,D_W)$, and must then compute $H_{(K+1)..N}​, X_{(K+1)..M}​, Y_{(K+1)..M}​, Z_{(K+1)..M}​,$ and $W_{(K+1)..M}$​ as follows:

$H_i=((A_H∗H_{i−2}+B_H∗H_{i−1}+C_H) \mod D_H)+1$ for $i>K$  
$X_i=((A_X∗X_{i−2}+B_X∗X_{i−1}+C_X) \mod D_X)+1$ for $i>K$  
$Y_i=((A_Y∗Y_{i−2}+B_Y∗Y_{i−1}+C_Y) \mod D_Y)+1$ for $i>K$  
$Z_i=((A_Z∗Z_{i−2}+B_Z∗Z_{i−1}+C_Z) \mod D_Z)+1$ for $i>K$  
$W_i=((A_W∗W_{i−2}+B_W∗W_{i−1}+C_W) \mod D_W)+1$ for $i>K$

## Input

Input begins with an integer $T$, the number of springs. For each spring there are 11 lines:  
The first line contains the 3 space-separated integers $N, M,$ and $K$.  
The second line contains the $K$ space-separated integers $H_{1..K}$​.  
The third line contains the 4 space-separated integers $A_H​, B_H​, C_H​,$ and $D_H$​.  
The fourth line contains the $K$ space-separated integers $X_{1..K}$​.  
The fifth line contains the 4 space-separated integers $A_X​, B_X​, C_X​,$ and $D_X$​.  
The sixth line contains the $K$ space-separated integers $Y_{1..K}$​.  
The seventh line contains the 4 space-separated integers $A_Y, B_Y​, C_Y​,$ and $D_Y$​.  
The eighth line contains the $K$ space-separated integers $Z_{1..K}$​.  
The ninth line contains the 4 space-separated integers $A_Z​, B_Z​, C_Z​,$ and $D_Z$​.  
The tenth line contains the $K$ space-separated integers $W_{1..K}$​.  
The eleventh line contains the 4 space-separated integers $A_W​, B_W​, C_W​,$ and $D_W$​.
