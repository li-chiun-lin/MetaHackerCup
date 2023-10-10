# Problem

```text
Is this a real verse? Is this just fantasy?
Caught in a mixtape, no escape from this melody.
Open your ears, listen to the beats and see.
I'm just a rapper, I need no sympathy,
Because it's easy come, easy go, little high, little low,
Any way the bars flow doesn't really matter to me, to me.
```

As an up-and-coming rapper, you're trying to distinguish yourself by writing a song with the most bohemian rhyme scheme!

Your vocabulary consists of $N$ words, $W_1​, …, W_N$​ made up of only lowercase letters. We consider two words to $K$-rhyme with each other if they have the same suffix of length $K$. For example, “mixtape” 3-rhymes with “escape”. If two words $K$-rhyme for $K>1$, they also $(K−1)$-rhyme.

You are faced with $Q$ bohemian rap-queries, the $i$-th of which specifies $(A_i,B_i,K_i)$. You’d like to assign each word $W_{A_i}​​, …, W_{B_i}$​​ to at most one group such that:

- the number of words in each group is unique and nonzero,
- groups only contain words with length at least $K_i$​,
- within each group, all pairs of words $K_i$​-rhyme with each other, and
- no two words from different groups $K_i$​-rhyme.

The answer to each query is the maximum possible number of nonempty groups. For each test case, output the sum of the answers over all queries.

## Input Format

Input begins with an integer $T$, the number of test cases.  
For each case, there is first a line containing a single integer $N$.  
$N$ lines follow, the $i$-th of which contains the string $W_i$​.  
Then, there is a line containing a single integer $Q$.  
$Q$ lines follow, the $i$-th of which contains $3$ space-separated integers $A_i​, B_i​,$ and $K_i$​.
