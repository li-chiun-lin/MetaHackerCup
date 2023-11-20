# Problem

You are the King of Byteland, which now consists of $K$ rival states. The national day of Byteland is approaching, and it is a day of great merriment. Each of the $K$ states is throwing its own party. Fortunately your kingdom also has $N$ rich and famous entertainers, numbered from $0$ to $N-1$. Its your job to allocate to each state, some non empty set of entertainers. Note that the same entertainer cannot be allocated to two different states. Some entertainers may be unallocated. Also to each allocated entertainer, you must pay $C$ coins to hire him.

The trouble is, some of the entertainers are fond of some others, and refuse to spend the national day without their friends, meaning they insist on being allocated to the same state if they are allocated). Under this constraint, you find out that allocating entertainers to the states becomes impossible. So you appeal to them to relax their requirements, and they ask you to donate more money to the entertainment industry. More formally, you will be provided with a 2-dimensional array $R$. If the total amount of money you donate is less than $R[u][v]$, for $u$ not equal to $v$, then entertainer $\#u$ will NOT agree to spend the national day without the company of entertainer $\#v$. Note that if you do not allocate entertainer $\#u$, then you can safely ignore his restrictions. $R[u][v]$ need not be equal to $R[v][u]$.

You are free to donate any non-negative amount of coins as you see fit. Find out the minimum expenditure you must make to satisfy all entertainers and all states. Note that your total expenditure is : (the amount of money you donate $+$ $C$ $\times$ the number of allocated entertainers).

## Input

The first line contains $T$, the number of test cases. Each test contains 3 lines.  
The first line contains 3 integers $N, K, C$.  
The second line contains 4 integers $x_1, a_1, b_1, m_1$  
The third line contains 4 integers $x_2, a_2, b_2, m_2$  
Using these values, the array $R$ can be generated as follows:  
Let $f_1[0] = x_1, f_2[0] = x_2;$  
$f_1[i] = (a_1 \times f_1[i-1] + b_1) \mod m_1$ for $i ≥ 1$  
$f_2[i] = (a_2 \times f_2[i-1] + b_2) \mod m_2$ for $i ≥ 1$  
If $i > j$, $R[i][j] = f_1[ i \times (i-1) / 2 + j ]$  
If $i < j$, $R[i][j] = f_2[ j \times (j-1) / 2 + i ]$  
Note that $R[i][j]$ is not defined for $i = j$.
