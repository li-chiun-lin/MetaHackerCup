# Problem

A trie is a tree where every node represents a prefix of a string. When a string $s$ is inserted into a trie, up to $∣s∣+1$ nodes are created if they don't already exist:

- a node representing the empty string, '', which is always the root of the trie
- a node representing the first character of $s$, which is a child of the root
- a node representing the first two characters of $s$, which is a child of the previous node
- ... and so on

You have $N$ wildcard strings, $S_1$​ through $S_N$​, which each consist of uppercase Latin letters and question marks. A wildcard string represents the set of all strings that you can create by replacing each question mark with some uppercase Latin letter.
If you add every string represented by each of your wildcard strings to a single trie (initially empty), how many nodes will that trie have? Output this number modulo $998,244,353$.

## Input Format

Input begins with an integer $T$, the number of test cases.
Each case begins with a line that contains the integer $N$.
Then $N$ lines follow, the $i$-th of which contains the string $S_i$​.
