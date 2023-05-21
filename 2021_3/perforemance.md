# Problem

Facebulk Inc. is a mining company that's about to release its latest performance report. In these trying times, accurate numbers will be crucial. As a forensic accountant, you've been hired to secretly audit employee earnings across $T$ ore-processing plants.

A given plant has $N$ employees. Employee $1$ is the superintendent, and has no manager. Each other employee $i$ has a single direct manager, employee $M_i​ (1≤M_i<i)$. With access to the HR database, you have full knowledge of the company structure.

The HR database also contains each employee's individual earnings in dollars, which is possibly zero or negative (if the employee lost money). However, the database's anonymization scheme prevents you from directly looking up an employee's individual earnings, instead supporting the following two types of queries which may be performed as many times as you like:

1. For a given employee $i$, query the sum of the earnings of all employees directly managed by employee $i$ (only allowed if there are at least $K$ such employees)
1. For a given employee $i$, query the sum of the earnings of all employees either directly or indirectly managed by employee $i$ (only allowed if there are at least $K$ such employees)

Despite the indirect nature of these queries, with each result being the sum of earnings of at least $K$ employees, you may still be able to infer some earnings of individual employees.

However, you're not necessarily satisfied with that. As a proficient hacker, you've figured out how to drop employees from the HR database. Before performing any queries, you may choose to delete $0$ or more employees (along with their earnings) from the company structure and database. You can only delete an employee if they do not directly manage anyone still in the database at the time.

Assuming you optimally decide which employees to delete and make the most of the database queries, what's the maximum possible number of employees whose earnings you can determine?

## Input

Input begins with an integer $T$, the number of ore-processing plants.  
For each plant, there is first a line containing 2 space-separated integers, $N$ and $K$.  
Then, there is a second line containing $N−1$ space-separated integers $M_{2..N}$​.
