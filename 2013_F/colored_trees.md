# Problem

You are given two integers $N$ and $K$. Your task is to calculate how many distinct trees with $N$ vertices there are with each vertex colored with one of $K$ colors. Multiple vertices can have the same color, and not all colors need to be used.

Two trees $t1$ and $t2$ are considered identical if there exists a bijective function $f$ from vertices of $t1$ to vertices of $t2$ such that each vertex $x$ in $t1$ is colored the same as $f(x)$ in $t2$ and each pair of vertices $x, y$ in $t1$ is connected by an edge if and only if $f(x)$ and $f(y)$ are connected by an edge in $t2$.

A bijective function is a function that is both one-to-one and onto, meaning that $f(x) = f(y)$ if and only if $x = y$, and for every vertex $y$ in $t2$, there exists $x$ in $t1$, such that $f(x) = y$.

Since this number might be very big, output it modulo $1,000,000,007$.

## Input

The first line contains a single integer $T$. $T$ test cases follow, where each test case consists of two integers: $N$ and $K$.
