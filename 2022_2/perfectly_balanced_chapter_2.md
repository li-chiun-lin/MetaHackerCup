# Problem

An array is perfectly balanced if its length is even, and the first half of the array can be shuffled to make the array a palindrome.

An array is almost perfectly balanced if you can delete exactly one element from it to make it perfectly balanced.

You are given a larger template array $A_1,\dots , A_N$​ of length $N$, along with $Q$ events, the $i$-th of which is one of the following two formats:

- $1$ $X_i$​ $Y_i$​: set $A_{X_i}$​​ to $Y_i$​.
- $2$ $L_i$​ $R_i$​: check whether the subarray $A_{L_i \dots R_i}$​​ is almost perfectly balanced.

For how many type-2 queries is the subarray almost perfectly balanced?

## Input Format

Input begins with a single integer $T$, the number of test cases.
For each test case, there is first a line containing a single integer $N$.
Then, there is a line containing $N$ space-separated integers $A_1,...,A_N$.
Then, there is a line containing a single integer $Q$.
Then, $Q$ lines follow, the $i$-th of which contains three space-separated integers, either "$1$ $X_i$​ $Y_i$​" or "$2$ $L_i$​ $R_i$​".
