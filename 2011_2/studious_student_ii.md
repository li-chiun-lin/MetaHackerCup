# Problem

You've decided to make up another string manipulation game instead of paying attention in class. Starting with a string composed entirely of 'a' and 'b' characters, you will iteratively apply the following operation:

For a string $s$ of length $len$, choose indices $i$ and $j$, where $i < j < len$. Choose a character $c$ that occurs in the substring which begins at zero-based index $i$ of string $s$ and extends to the index $j$ (inclusive). Replace all characters in $s$ with zero-based index in $[i, j]$ with a single instance of $c$ to generate $s'$. Set $s$ to be $s'$.

The goal of your game is simple: calculate how many different sequences of operations you can perform. As this number can be very large, you decide to calculate it modulo $1,000,000,007$. Two sequences of operations are considered different if they differ in length, or if they differ in at least one position. Note that the order of operations is a factor. The empty sequence of operations should be counted as well. Operations can be considered triples of $(i, j, c)$ as described above, and these are the only values used when computing whether two operations are the same.

## Input

The first line of the input file contains a single number $N$, the number of test cases.  
Each test case is written on a separate line, and contains a string consisting of letters 'a' and 'b'.
