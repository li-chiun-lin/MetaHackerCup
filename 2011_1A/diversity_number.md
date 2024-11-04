# Problem

Let's call a sequence of integers $a_1, a_2, ..., a_N$ almost monotonic if first $K$ elements are non-decreasing sequence and last $N-K+1$ elements are non-increasing sequence: $a_1≤a_2≤...≤a_K$ and $a_K≥a_{K+1}≥...≥a_N$.

The _diversity_ number of a sequence $a_1, a_2, ..., a_N$ is the number of possible sequences $b_1, b_2,..., b_N$ for which $0≤b_i<a_i$ and all of the numbers $b_1, b_2,..., b_N$ are different. The diversity number of an empty sequence is $1$.

You need to find the sum of the diversity numbers of all almost monotonic subsequences of a sequence. Since this number can be very large, find it modulo $1,000,000,007$. A subsequence is a sequence that can be obtained from another sequence by deleting some elements without changing the order of the remaining elements. Two sequences are considered different if their lengths differ or there is at least one position at which they differ.

## Input

The first line of the input file consists of a single number $T$, the number of test cases.  
Each test case consists of a number $M$, the number of elements in a sequence, followed by $M$ numbers $n$, elements of some sequence (note that this sequence is not necessarily almost monotonic). All tokens are whitespace-separated.
