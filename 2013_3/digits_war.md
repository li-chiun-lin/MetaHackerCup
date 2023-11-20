# Problem

There has been a war between the digits in the kingdom of numbers and it is King Infinity's job to restore balance. In search of peace he came up with a new number system which only allows those numbers to exist in which:

1. None of the consecutive digits are at war against each other.
2. No two digits that have only one digit in between them are at war.

For example, if $4$ is at war with $5$, then $45$, $405$, and $574$ are all forbidden.

A digit can be at war with itself. You are given a $10 \times 10$ binary matrix $M$ (0 index based), where $M[i][j]$ denotes whether there is a war between digit i and digit j. If $M[i][j] = 1$ then they are at war and $M[i][j] = 0$ means they are not. $M[i][j]$ will always be equal to $M[j][i]$.

Your task is to find the count of positive numbers that can exist in this number system with number of digits $≤ K$. No number in the number system can have leading zeroes.

## Input

Input consists of $T$ test cases, with $T$.  
Each test case begins with the value of $K$ followed by a $10 \times 10$ binary matrix.
