# Problem

Facebulk Inc. is a mining company whose Bulk Geological Processing (BGP) network has been disrupted lately. To improve response times in the event of future disruptions, the company plans to assign shift partners within each of its $T$ ore-processing plants.

A given plant has $N$ employees, numbered from $1$ to $N$ in decreasing order of seniority.

Initially, none of the employees are partners with one another. The company will then assign $M$ partnerships, one by one, with the $i$-th partnership pairing up employees $A_i$​ and $B_i$​ if they weren't already. An employee can be part of multiple partnerships.

An employee $x$ can directly receive reports from an employee $y$ if $x$ has higher seniority than $y$ (that is, $x<y$), or if $x$ and $y$ are partners, or both. An employee $x$ can indirectly receive reports from an employee $y$ if there exists at least one intermediate employee $z$ such that $x$ can directly receive reports from $z$, and $z$ can directly or indirectly receive reports from $y$.

Let $S_i$​ be the number of ordered pairs of employees $(x,y)$ such that employee $x$ can directly or indirectly receive reports from employee $y$ after the first $i$ partnership pairings have been made. Note that $S_i≤N(N−1)$.

Please help Facebulk evaluate its reporting efficiency over time by computing the product of $S_{1..M}$​. As this product may be very large, you should compute its value modulo $10^9 + 7$.

## Input

Input begins with an integer $T$, the number of ore-processing plants.  
For each plant, there is first a line containing 2 space-separated integers, $N$ and $M$.  
Then, $M$ lines follow, the $i$-th of which contains 2 space-separated integers, $A_i$​ and $B_i$​.
