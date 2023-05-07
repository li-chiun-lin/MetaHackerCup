# Problem

The only differences between this chapter and chapter 1 is that here, $A_i \in \{1, 2\}$, and you may only swap adjacent elements of $A_i$​ with a single operation.

As a Metal Platforms employee, you place a high value on your work-life balance. Boss Rob has assigned you $N$ tasks, the $i$-th of which takes $A_i$​ minutes to finish, where $A_i$​ is either $\mathbf{1}$ or $\mathbf{2}$.

You may reorder your tasks, where each operation lets you swap any two adjacent elements of $A$ ($A_i$​ and $A_j$​ for some $i$ and $j$ such that $|i - j| = 1$).

To reflect how often task requirements change in the real world, there will be $M$ updates made to the task completion times, with the $i$-th update setting $A_{X_i}$​​ to $Y_i$​.

After completing the $i$-th update, you would like to know if it's possible to balance the time spent at work versus at home, namely if you hope to finish the first $Z_i$​ tasks at work and the rest at home. Specifically, let $Q_i$​ be the minimum number of swap operations which must be theoretically performed so that $A_1 + ... + A_{Z_i} = A_{Z_i + 1} + ... + A_{N}$​, with $Q_i = -1$ if it's impossible. Note that it's possible for $Q_i$​ to be $0$, if the subarrays already have equal sums.

To reduce the size of the output, please compute the sum of $Q_1​, \dots, Q_M$​.
