# Problem

The only differences between this chapter and chapter 2 is that here, $A_i \in \{1, 2, 3\}$, and you may swap any two elements of $A_i$​ with a single operation.

As a Metal Platforms employee, you place a high value on your work-life balance. Boss Rob has assigned you $N$ tasks, the $i$-th of which takes $A_i$​ minutes to finish, where $A_i$​ is either $\mathbf{1, 2}$, or $\mathbf{3}$.

You may reorder your tasks, where each operation lets you swap any two elements of $A$.

To reflect how often task requirements change in the real world, there will be $M$ updates made to the task completion times, with the $i$-th update setting $A_{X_i}$​​ to $Y_i$​.

After completing the $i$-th update, you would like to know if it's possible to balance the time spent at work versus at home, namely if you hope to finish the first $Z_i$​ tasks at work and the rest at home. Specifically, let $Q_i$​ be the minimum number of swap operations which must be theoretically performed so that $A_1 + ... + A_{Z_i} = A_{Z_i + 1} + ... + A_{N}$​, with $Q_i = -1$ if it's impossible. Note that it's possible for $Q_i$​ to be $0$, if the subarrays already have equal sums.

To reduce the size of the output, please compute the sum of $Q_1​, \dots, Q_M$​.

## Input Format

Input begins with a single integer $T$, the number of test cases.
For each test case, there is first a line containing two space-separated integers $N$ and $M$.
Then, there is a line containing $N$ digits, $A_1, A_2​, ..., A_N$​.
Then, $M$ lines follow, the $i$-th of which contains three space-separated integers $X_i, Y_i​,$ and $Z_i$​.
