# Problem

    …right down Santa Claus Lane!

Santa Claus Lane is home to $N$ elves, the $i$-th of whom lives $X_i$​ meters from the start of the lane. As Santa's little helper, you're tasked to assign elves to work on toys for good little girls and boys. Specifically, you must assign each elf to work on some toy so that at least $2$ toys get worked on, and no elf works on a toy alone.

All elves working on the same toy will meet at the point which minimizes the farthest distance that any of them would need to walk. Formally, if the elves assigned to a given toy live at $X_1​, X_2​, …,$ then they will meet at point $P$ such that $\max(∣X_1−P∣, ∣X_2−P∣, …)$ is as small as possible.

Santa is supervising, and you reckon he could use some exercise. Among all valid assignments of elves to toys, what's the farthest Santa would need to walk to visit all meeting points? Santa may start and end anywhere, but will try to walk as little as possible after seeing your assignments.

## Input Format

Input begins with an integer $T$, the number of test cases.  
Each case begins with one line containing the integer $N$, followed by a second line containing the the $N$ integers $X_1...X_N$​.
