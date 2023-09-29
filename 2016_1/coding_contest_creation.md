# Problem

You've been put in charge of creating the problems for a certain high-profile programming contest series.

The series will consist of one or more contests of exactly 4 problems each. Every problem has a difficulty rating (an integer between 1 and 100, inclusive), and the ratings of the 4 problems in each contest must be strictly increasing, but with a difference of no more than 10 between consecutive problems. In other words, if the problems in a contest have difficulties $a, b, c,$ and $d$ (in order), then the inequalities $a < b < c < d, b - a ≤ 10, c - b ≤ 10, d - c ≤ 10$ must all hold.

You've been given an ordered list of $N$ problems to use. Being an experienced problemsetter, you may also write some new problems to insert at any positions in the list, each with an integer difficulty between 1 and 100, inclusive. The final list of problems must still include the original $N$ problems in their original order, though (with your new problems optionally mixed in).

Once the problem list is finalized, the first 4 problems (in order) will form a contest, the next 4 problems will form another contest, and so on. Note that the number of problems in the list must be divisible by 4, and that each of the contests formed must feature a valid ordered set of 4 problems. What's the minimum number of additional problems you must write in order to create a set of valid contests?

## Input

Input begins with an integer $T$, the number of contest series you need to create.  
For each series, there is first a line containing the integer $N$, then a line containing $N$ space-separated integers, the $i$-th of which is $D_i$, the difficulty rating of the $i$-th existing problem.
