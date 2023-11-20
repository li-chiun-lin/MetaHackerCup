# Problem

After sending smileys, John decided to play with arrays. Did you know that hackers enjoy playing with arrays? John has a zero-based index array, $m$, which contains $n$ non-negative integers. However, only the first $k$ values of the array are known to him, and he wants to figure out the rest.

John knows the following: for each index $i$, where $k ≤ i < n$, $m[i]$ is the minimum non-negative integer which is *not* contained in the previous $k$ values of $m$.

For example, if $k = 3, n = 4$ and the known values of $m$ are $[2, 3, 0]$, he can figure out that $m[3] = 1$.

John is very busy making the world more open and connected, as such, he doesn't have time to figure out the rest of the array. It is your task to help him.

Given the first $k$ values of $m$, calculate the $n$-th value of this array. (i.e. $m[n - 1]$).

Because the values of $n$ and $k$ can be very large, we use a pseudo-random number generator to calculate the first $k$ values of $m$. Given non-negative integers $a, b, c$ and positive integer $r$, the known values of $m$ can be calculated as follows:

- $m[0] = a$
- $m[i] = (b \times m[i - 1] + c) \mod r, 0 < i < k$

## Input

The first line contains an integer $T$, the number of test cases.  
This is followed by $T$ test cases, consisting of 2 lines each.  
The first line of each test case contains 2 space separated integers, $n, k$.  
The second line of each test case contains 4 space separated integers $a, b, c, r$.
