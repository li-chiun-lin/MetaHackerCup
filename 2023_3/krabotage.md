# Problem

Despite his age, Mr. Krabs still goes trick-or-treating. Free candy (free anything, really) is irresistible to him. Bikini Bottom is an $R×C$ grid of houses, with house $(i,j)$ having $A_{i,j}$​ pieces of candy.

Mr. Krabs plans to travel from house $(1,1)$, the top-left corner, to house $(R,C)$, the bottom-right corner, taking as much candy as possible along the way. When Mr. Krabs is at house $(i,j)$, he takes all the candy, and then either moves down to house $(i+1,j)$ or right to house $(i,j+1)$.

Plankton wants to sabotage him, and has decided to complete his own candy run before Mr. Krabs even starts his trip. Plankton will go from house $(1,C)$, the top-right corner, to house $(R,1)$, the bottom-left corner. When Plankton is at house $(i,j)$, he takes all its candy (so there's none left for Mr. Krabs later) and either moves down to house $(i+1,j)$ or left to house $(i,j−1)$.

What's the maximum amount of candy that Mr. Krabs can collect, assuming that Plankton strives to minimize this value by completing his trip before Mr. Krabs starts?

## Input Format

Input begins with an integer $T$, the number of test cases.  
Each case begins with a line containing the two integers $R$ and $C$.  
Then, $R$ lines follow, the $i$-th of which contains the $C$ integers $A_{i,1}$​ through $A_{i,C}$​.
