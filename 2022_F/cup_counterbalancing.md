# Problem

Courtney has an avant-garde kitchen counter made out of $N$ rectangular sheets of metal of equal height, standing perpendicular to the ground. When viewed directly from the top, the counter looks like an (unfilled) polygon on a plane with $N$ edges, the $i$-th of which extends from point $(X_i,Y_i)$ to point $(X_{(i \mod N)+1},Y_{(i \mod N)+1})$. These line segments only intersect at their endpoints.

Courtney's friends often make fun of the counter, saying that the thin metal "surface" is useless for holding anything up, but Courtney wants to prove them wrong.

Courtney considers placing a cup with a circular rim of radius $R$ onto the counter (with the rim facing down), centered at a point chosen uniformly randomly from the square $[0,L]×[0,L]$. What is the chance that the cup stays balanced on the counter without falling? Your output will be accepted if it is within $10^{−6}$ of the jury's answer.

Note: The face-down cup is modeled as an unfilled ring—not as a disk.

## Input

Input begins with a single integer $T$, the number of test cases.  
For each test case, there is first a line containing three space-separated integers $N$, $R$, and $L$.  
Then, $N$ lines follow, the $i$-th of which contains two space-separated integers $X_i$​ and $Y_i$​,
