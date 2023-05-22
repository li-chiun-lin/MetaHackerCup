# Problem

During the COVID-19 pandemic, Pascal, like many others, has become an expert at cooking pasta. He's become so talented that he's decided to open his own restaurant! The challenge is that restaurants today must follow strict capacity guidelines to reduce the virus's spread. He's got the cooking covered, but will need help optimizing the seating logistics in order to achieve a good trade-off between a booming business and responsible social distancing.

On a certain day, Pascal's restaurant is divided into $N$ open seating sections, with $S_i$​ customers initially sitting in each section $i$. To keep business strong, but seating capacity manageable, Pascal insists that each section $i$ must seat between $X_i$​ and $X_i+Y_i$​ customers, inclusive.

In an attempt to achieve this, he may repeatedly choose a customer to politely (yet forcibly) relocate from their current seating section to a different section of Pascal's choice.

Customers would be annoyed by too much shuffling about, so Pascal has asked for your help in determining the minimum number of such relocations necessary. If the criteria cannot all be met after any number of relocations, you should report a value of $−1$ instead.

In order to reduce the size of the input, the above values will not all be provided explicitly. Instead, you'll be given the first $K$ values $S_{1..K}​, X_{1..K}​,$ and $Y_{1..K}$​, as well as the three quadruples of constants $(A_S,B_S,C_S,D_S), (A_X,B_X,C_X,D_X),$ and $(A_Y,B_Y,C_Y,D_Y)$, and must then compute $S_{(K+1)..N}​, X_{(K+1)..N},$ and $Y_{(K+1)..N}$​ as follows:

$S_i=(A_S∗S_{i−2}+B_S∗S_{i−1}+C_S) \mod D_S$ for $i>K$  
$X_i=(A_X∗X_{i−2}+B_X∗X_{i−1}+C_X) \mod D_X$​ for $i>K$  
$Y_i=(A_Y∗Y_{i−2}+B_Y∗Y_{i−1}+C_Y) \mod D_Y$​ for $i>K$  

## Input

Input begins with an integer $T$, the number of days. For each day, there are 7 lines:  
The first line contains the 2 space-separated integers $N$ and $K$.  
The second line contains the $K$ space-separated integers $S_{1..K}$​.  
The third line contains the 4 space-separated integers $A_S​, B_S​, C_S​,$ and $D_S$​.  
The fourth line contains the $K$ space-separated integers $X_{1..K}$​.  
The fifth line contains the 4 space-separated integers $A_X​, B_X​, C_X​,$ and $D_X$​.  
The sixth line contains the $K$ space-separated integers $Y_{1..K}$​.  
The seventh line contains the 4 space-separated integers $A_Y​, B_Y​, C_Y​,$ and $D_Y$​.
