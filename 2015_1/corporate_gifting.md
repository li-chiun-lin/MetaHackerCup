# Problem

The fine people of Corpro Corp. are a festive bunch. Every holiday season, everybody buys a gift for their manager. A cynic might say that the employees are just trying to bribe their way to a better performance review, but if you asked them yourself, they'd say they just wanted to spread cheer.

The fine people of Corpro Corp. are a frugal bunch. When they buy gifts, they cooperate to collectively buy the least expensive gifts that they can. A cynic might say that the employees are cheap, but if you asked them yourself, they'd say it's the thought that counts.

There are $N$ employees working at Corpro Corp., and each of them has a manager, except for the CEO who has no manager (the CEO also buys a gift every year, but she donates it to charity). The employees each have a unique employee ID which is an integer from $1$ to $N$. As you might expect, the CEO has the ID $1$.

If there exists a set of two or more employees $\{p_1, ..., p_k\}$ such that, for all $i < k$, $p_i$ is the manager of $p_{i+1}$, then we say that $p_1$ is "responsible for" $p_k$. There are never two employees who are responsible for each other. That would be a silly hierarchy indeed.

There are $N$ kinds of gifts available for purchase, and the $i$-th kind of gift costs $i$ dollars. That is, the prices of the different kinds of gifts are $\{\$1, \$2, \$3, ... \$N\}$. There are $N$ copies of each gift available for purchase.

The only thing that stops all employees from purchasing gifts that cost $\$1$ is the awkwardness of buying a gift for their manager that's the same as the one their manager is giving away. No employee would ever do such a thing!

What's the minimum possible total expenditure across the whole company during the gift exchange?

## Input

Input begins with an integer $T$, the number of corporate hierarchies to consider. Each hierarchy is made up of two lines.  
The first line contains the integer $N$.  
The second line contains $N$ space-separated integers. The $i$-th integer is the employee ID of the manager of employee $i$, with the exception that the first integer is always $0$, denoting that the CEO has no manager.
