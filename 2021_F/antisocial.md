# Problem

Cole is a programmer in the coal division of Metal (previously Facebulk), working across $T$ office buildings with very pleasant coworkers and unlimited free ice cream. However, as a self-proclaimed antisocial code monkey, he still prefers to "mine" his own business when possible.

A given office building can be represented by an axis-aligned rectangle with opposite corners $(0,0)$ and $(X_R,Y_R)$ on a 2D plane. Inside, there are $N$ friendly coworkers, the $i$-th of whom is permanently seated at position $(X_i,Y_i)$, distinct from all other coworkers.

Cole is currently at position $(X_A,Y_A)$, and would like to reach the unlimited free ice cream at a different position $(X_B,Y_B)$. Neither position is located at a coworker's seat.

Please help Cole determine the closest distance he'll need to get to another coworker in order to travel from $(X_A,Y_A)$ to $(X_B,Y_B)$ without leaving the building. Your answer will be accepted if it is within either $10^{−6}$ or $0.000001\%$ of the right answer.

## Input

Input begins with a single integer $T$, the number of office buildings.  
For each building, there is first a line containing 2 space-separated integers, $X_R$​ and $Y_R$​.  
Then, there is a line containing 4 space-separated integers, $X_A, Y_A​, X_B​,$ and $Y_B$​.  
Then, there a line containing a single integer $N$.  
Then, $N$ lines follow, the $i$-th of which consists of 2 space-separated integers, $X_i$​ and $Y_i$​.
