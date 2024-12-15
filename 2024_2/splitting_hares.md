# Problem

You're designing Hacker Cup shirts for $N$ rabbits, numbered $1$ to $N$, with the $i$-th rabbit weighing $W_i$​ ounces. All rabbits have a unique weight.

You've created a variety of shirt colors, assigning color $C_i$​ to the $i$-th rabbit, by following these rules:

- No shirt color is worn by exactly one rabbit.
- The sum of $F(c)$ across all shirt colors is as low as possible, where $F(c)$ is the difference between the maximum and minimum weights of rabbits wearing color $c$.

Before ordering the shirts, you wrote down the weights of each rabbit on a really large carrot. But now that the shirts have arrived and it's time to hand them out, you notice that pieces of this carrot have been eaten, causing some weights to be missing ($−1$ in the input).

Now you want to figure out missing weights which satisfy the above conditions. If it turns out that no possible replacement for the missing weights would result in the given shirt assignment $C$, then you must have made an error when assigning the shirt colors in the first place, in which case you'll just give up.

When outputting weights, you must stay within the range $[1 ... 10,000]$, and you must ensure that all weights remain distinct.

## Input Format

Input begins with an integer $T$, the number of test cases. Each test case is three lines.
The first line contains the integer $N$.
The second line contains the $N$ integers $W_1$​ through $W_N$​, with unknown weights denoted as $-1$.
The third line contains the $N$ integers $C_1$​ through $C_N$​.
