# Problem

For this problem, a possible median is defined as: The median value of a set containing an odd number of values. -or- One of all the integers between, but not including, the two median values of a set containing an even number of values.

You are given an array $A$ of $N$ unique nonnegative integers, all of which are $< N$ (i.e. a permutation of the numbers $0...N-1$), where $N$. You are also given a length $L$ $(1 ≤ L ≤ N)$. Additionally, you are given $Q queries, each containing a number $x$ $(0 ≤ x < N)$ and two indices $i$ and $j$ $(0 ≤ i < j ≤ N)$.

Each query returns $TRUE$ if and only if there exists at least one subrange, of at least $L$ elements, of the range $A[i]...A[j-1]$ (where the array indices start at $0$), with $x$ as a possible median. In other words, the answer is $TRUE$ precisely when there exist $a, b$ with $i ≤ a < b < j$ with $b - a ≥ L - 1$ and with $A[a]...A[b]$ having $x$ as a possible median.

You wish to determine the number of queries which will return $TRUE$.

## Input

The first line contains a positive integer $T$, the number of test cases. $T$ test cases follow.  
The first line of each test case consists of a single integer, $N$.  
The next line consists of $N$ space-separated integers, the $A[i]$.  
The line after that contains two space-separate $d$ integers, $L$ and $Q$.  
Each of the remaining $Q$ lines in the test case contains three space-separated integers, $x, i$ and $j$.  
These inputs are all integers, and will be input in decimal form, with no leading zeros, and no decimal points.
