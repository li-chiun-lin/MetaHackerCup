# Problem

Many people are avid fans of the daily crossword in the paper, but not you. I mean, the format is pretty terrible, right? You only get to use English words, and any hack can look those up in a dictionary. Also, it takes forever to make just one puzzle. What a waste of time.

You've written a letter to the editor describing a new word game. It's really easy to make new puzzles because the only thing you give the solver is a permutation $P_{1..N}$ of the first $N$ positive integers. It's then up to the solver to find any string that's salient for the given permutation.

A string is salient for the permutation $P_{1..N}$ if it consists of $N$ uppercase letters ("A"..."Z"), such that when its $N$ non-empty suffixes are sorted in lexicographical order, the suffix starting at the $i$-th character is the $P_i$-th suffix in the sorted list. It's possible that a given permutation has no salient strings.

You need some example puzzles to include in your letter. You already have some permutations generated, so all you need is to supply an answer for each permutation (if possible).

## Input

Input begins with an integer $T$, the number of different permutations you've generated.  
For each permutation, there is first a line containing the integer $N$.  
Then $N$ lines follow, the $i$-th of which contains the integer $P_i$. It is guaranteed that each integer from $1$ to $N$ shows up exactly once in $P$.
