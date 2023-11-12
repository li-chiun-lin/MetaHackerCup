# Problem

Charlotte is a very successful Olympic skier. All the sponsor deals she landed during her career has made her very rich, so she has decided to retire from skiing. Charlotte has just bought an entire mountain, and is planning to build a ski resort there. The mountain has $N$ interesting points, numbered $0, 1, ..., N-1$. Point $0$ is the top of the mountain. Point $i$ is further down the mountain than point $j$ if $i > j$.

For each point $a > 0$, she has decided on a different point $b$, which has the following property: All paths from the top of the mountain to point $a$ have to go through point $b$, and there is no point $c$, such that $b < c < a$ and all paths from the top of the mountain to point $a$ go through point $c$. A path can never go up the mountain.

You have been given the task to plan where the slopes go. You can add slopes directly between any two different interesting points. How many ways can you lay out the slopes for her resort, while satisfying the conditions above?

Two ways of laying out the slopes, $X$ and $Y$, are different if there exists two interesting points $a$ and $b$, such that the slope between $a$ and $b$ exists in $X$ or $Y$, but not in the other.

You can assume that the skiers will be able to get to a lift from any point, so you don't have to worry about getting them all the way down for every path. You have to be able to reach all interesting points from the top.

## Input

The first line of the input consists of a single integer $T$, the number of test cases.  
Each test case starts with a line containing the integer $N$.  
The next line of each test case contains $N-1$ integers, $A_1, A_2, ..., A_{N-1}$, where $A_i$ is the lowest interesting point that all paths to point $i$ has to pass through.
