# Problem

You have an $N×N$ boolean matrix $G$, except some cells have not been set to either 0 or 1 and are instead marked as ?.
The cover of $G$ is the smallest rectangular sub-matrix that contains every 1 in $G$ (and may also contain 0 or unset ? cells).
You'd like to set exactly $K$ of the ? cells to 1, and then compute the cover. What is the maximum area of the cover that you can achieve?

## Input Format

Input begins with an integer $T$, the number of test cases.
The first line of each case contains the integers $N$ and $K$.
Then, $N$ lines follow, the $i$-th of which contains $N$ characters, the $i$-th row of $G$.
