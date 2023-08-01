# Problem

In preparation for his final exam, Ethan is doing his fourth programming assignment: finding the subarray with the maximum sum in an array of integers.

Given an array of $N$ integers $A_{1..N}$, Ethan's task is to find the maximum sum of any (possibly empty) contiguous subarray of $A$. Ethan has implemented an algorithm to solve this problem, described by the following pseudocode:

1. Set $s$ and $m$ to both be equal to $0$.
2. Iterate $i$ upwards from $1$ to $N$:
   1. If $A_i ≥ 0$, increment $s$ by $A_i$, otherwise set $s$ to be equal to $0$.
   2. If $s > m$, set $m$ to be equal to $s$.
3. Output $m$.

Is there any hope for Ethan? With exasperation, you set out in vain to teach another lesson.

The professor of the class has once again left you with some half-written test cases. You're given an initial array $B_{1..M}$, such that the absolute value of each element is at most $K$. You'd like to insert $M - 1$ more integers into the array, one between each pair of adjacent elements in the original array, to construct a new array $A_{1..N}$ where $N = 2M - 1$. Each of the inserted elements must likewise have an absolute value of at most $K$. You'll then feed the new array $A$ into Ethan's algorithm. Your goal is to maximize the absolute difference between the final array's correct maximum subarray sum and the output of Ethan's algorithm.

## Input

Input begins with an integer $T$, the number of test cases.  
For each test case, there is first a line containing the space-separated integers $M$ and $K$.  
Then one more line follows containing the $M$ space-separated integers $B_1$ through $B_M$.
