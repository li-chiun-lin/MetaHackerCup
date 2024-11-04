# Problem

Monty the mountain cottontail rabbit is preparing for an expedition in the Rockies. However, Monty is a mathematician first and a mountaineer second, and would like to first assess his route in terms of numbers.
A number is a "mountain" if the following criteria are met:

- it has $2k+1$ digits, $D_1...D_{2k+1}$​, for some integer $k≥0$
- none of its digits are zero
- the first $k+1$ digits are monotonically non-decreasing
  - $D_{i+1}≥D_i$​ for $1≤i<k+1$
- the last $k+1$ digits are monotonically non-increasing
  - $D_{i+1}≤D$i$​ for $k+1≤i<2k+1$
- the middle digit is unique

Given an inclusive range $[A,B]$ and an integer $M$, help Monty count the number of mountains in the range that are a multiple of $M$.

## Input Format

Input begins with an integer $T$, the number of test cases. Each case is a single line with the integers $A$, $B$, and $M$.
