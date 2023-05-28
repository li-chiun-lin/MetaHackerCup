# Problem

H Combinator (HC) is a business incubator that provides seed funding to startups. It operates on the core value that "nothing is somebody else's problem" (since businesses slow down when tasks get perpetually passed from person to person). HC currently supports $T$ companies. As a managing director hoping to weed out some bad investments, you would like to assess how well the structure of each company holds up to this important principle.

Suppose a company has $N$ employees, numbered $1$ to $N$ in decreasing order of seniority. Employee $1$ is the CEO, while each other employee $i$ $(i≥2)$ has a manager, employee $M_i$​ $(M_i<i)$.

When employee $i$ is assigned a task to complete, they may instead reassign it to one of the following employees:

1. One of their direct reports (any employee $j$ such that $M_j=i$), if any exist
1. Their manager (employee $M_i$​), if $i≥2$
1. The CEO (employee $1$), if $i≥2$

That employee may then reassign the task to yet another employee, and so on. However, an employee may never be reassigned a task that has ever been previously assigned to them, as the lack of responsibility would become too apparent. For example, an employee and manager cannot repeatedly pass a task back and forth.

Let $R_i$​ be the maximum number of times that a task could be reassigned from one employee to another if it were initially assigned to employee $i$. For each company, you would like to calculate the product $(R_1∗R_2∗...∗R_N) \mod 10^9+7$.

## Input

Input begins with an integer $T$, the number of companies.  
For each company there are 2 lines.  
The first line contains the single integer $N$.  
The second line contains $N−1$ space-separated integers, $M_{2..N}$​.
