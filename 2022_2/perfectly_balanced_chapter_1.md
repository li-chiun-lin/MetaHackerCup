# Problem

A string is perfectly balanced if its length is even, and the first half of the string can be shuffled to make the string a palindrome.

A string is almost perfectly balanced if you can delete exactly one character from it to make it perfectly balanced.

You are given a larger template string $S$, and $Q$ substrings, the $i$-th of which is $S_{L_i..R_i}$​​. For how many of these $Q$ queries is the substring almost perfectly balanced?

## Input Format

Input begins with a single integer $T$, the number of test cases.
For each test case, there is first a line containing a single template string $S$.
Then, there is a line containing a single integer $Q$.
Then, $Q$ lines follow, the $i$-th of which contains two space-separated integers $L_i$​ and $R_i$​.
