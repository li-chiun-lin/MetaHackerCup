# Problem

Ethan's doing his very first programming assignment: implementing a $contains()$ function. This function takes two strings, $A$ and $B$, and returns $true$ if $A$ is a substring of $B$, and $false$ otherwise.

Here's the algorithm that Ethan has come up with. Note that $|A|$ denotes the length of $A$, and the individual characters of the strings are 1-indexed.

1. Set $i$ and $j$ to each be equal to $1$.
1. If $i > |A|$, return $true$.
1. If $j > |B|$, return $false$.
1. If $A_i = B_j$, increment $i$ and $j$ by $1$ each, and return to Step 2.
1. If $i = 1$, increment $j$ by $1$, and return to Step 2.
1. Set $i$ to be equal to $1$, and return to Step 2.

As the TA in charge of grading Ethan's assignment, this doesn't look quite right to you. To make sure Ethan doesn't get any more credit than he deserves, you'd like to find some inputs for which his algorithm returns $false$ even though it should return $true$.

The professor teaching this class has provided you with a half-written list of test cases. In particular, it's a list of inputs for the $A$ parameter, and you're free to come up with your own inputs for the $B$ parameter. For each given string $A$, you want to find a string $B$ that will cause Ethan's algorithm to return the wrong output ($false$ instead of $true$), if possible. $A$ will only contain uppercase alphabetic characters, and $B$ must follow the same constraint. The test cases shouldn't be too large, so $B$ must also contain at most $10,000$ characters.

## Input

Input begins with an integer $T$, the number of given strings.  
Then, $T$ lines follow. Each line contains a single string, $A$.
