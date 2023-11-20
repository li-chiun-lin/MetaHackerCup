# Problem

You are designing a new encryption system that works in the following way:

For server-client communication you need a key $k$, composed of $m$ sections, each of length $l$, and the key consists only of lowercase characters in the set $\{a, b, c, d, e, f\}$. The server has a key $k1$ and the client has a key $k2$ where:

- $k1 = f(k)$. $f$ is a function that receives a key and replace some random letters by $?$ indicating that those characters can be any lowercase letter of the set described before.
- $k2 = f(g(k))$. $g$ is a function that takes a key and produces a random permutation of its $m$ sections. And $f$ is the function defined above.

Your task is given $k1$ and $k2$, find key $k$. If there are several solutions, print the lexicographically smallest key. And if there is no solution at all, print "IMPOSSIBLE" (without the quotes).

## Input

The first line has a single integer $T$, which corresponds to the number of test cases. $T$ test cases follows.  
The first line of the test case corresponds to the integer $m$.  
The second line contains the string $k1$ and the third line contains the string $k2$.
