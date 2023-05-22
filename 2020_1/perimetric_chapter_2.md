# Problem

After a highly successful haul from the log drive, Connie the contractor is tasked with building a number of houses in the Great White North. For each job, the client has provided a floor plan consisting of $N$ rectangular rooms. From a bird's-eye view, the rooms are arranged on a 2-dimensional plane, with axis-aligned walls. The southern wall of each room has y-coordinate $0$.

The $i$-th rectangular room has southwest corner $(L_i,0)$ and northeast corner $(L_i+W_i,H_i​)$. In this chapter of the problem, the rooms have non-increasing $H$ values $(H_1≥H_2≥...≥H_N)$. Since houses often have shared regions (such as a common living/dining area), these rooms may overlap with one another.

Unfortunately, log houses are quite susceptible to air leakage. Connie knows that she must install additional insulation to keep the houses warm and energy-efficient during the harsh Canadian winters. In order to determine the amount of insulation material required, Connie will first need to gather some metrics: the perimeters around various combinations of rooms.

Specifically, let $P_i$​ be the perimeter of the union of rooms $1..i$. Note that any given point is considered to be within the union if and only if it's within at least one of the rooms' rectangles (including right on an edge), and that the union might not form a single connected polygon. Please help compute the product $(P_1∗P_2∗...∗P_N)$. As this product may be very large, you should compute its value modulo $10^9+7$.

In order to reduce the size of the input, the rooms' coordinates will not all be provided explicitly. Instead, you'll be given the first $K$ values $L_{1..K}​, W_{1..K}​,$ and $H_{1..K}$​, as well as the three quadruples of constants $(A_L,B_L,C_L,D_L), (A_W,B_W,C_W,D_W),$ and $(A_H,B_H,C_H,D_H)$, and must then compute $L_{(K+1)..N}​, W_{(K+1)..N}​,$ and $H_{(K+1)..N}$​ as follows:

$L_i=((A_L∗L_{i−2}+B_L∗L_{i−1}+C_L) \mod D_L)+1$ for $i>K$  
$W_i=((A_W∗W_{i−2}+B_W∗W_{i−1}+C_W) \mod D_W)+1$ for $i>K$  
$H_i=((A_H∗H_{i−2}+B_H∗H_{i−1}+C_H) \mod D_H)+1$ for $i>K$

## Input

Input begins with an integer $T$, the number of floor plans.  For each plan, there are 7 lines.  
The first line contains the 2 space-separated integers $N$ and $K$.  
The second line contains the $K$ space-separated integers $L_{1..K}$​.  
The third line contains the 4 space-separated integers $A_L​, B_L​, C_L​,$ and $D_L$​.  
The fourth line contains the $K$ space-separated integers $W_{1..K}$​.  
The fifth line contains the 4 space-separated integers $A_W​, B_W​, C_W​,$ and $D_W$​.  
The sixth line contains the $K$ space-separated integers $H_{1..K}$​.  
The seventh line contains the 4 space-separated integers $A_H​, B_H​, C_H​,$ and $D_H$​.
