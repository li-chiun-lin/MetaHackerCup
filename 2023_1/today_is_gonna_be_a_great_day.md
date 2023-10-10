# Problem

```text
This could possibly be the best day ever!
And the forecast says that tomorrow will likely be a billion and 6 times better.
So make every minute count, jump up, jump in, and seize the day,
And let's make sure that in every single possible way… today is gonna be a great day!
```

There's $N$ days of summer vacation, and the $i$-th day initially has greatness $A_i$​. However, the days just keep getting better! In particular, there will be $Q$ changes, the $i$-th of which changes the greatness of every day from $L_i$​ to $R_i$​ to be $1000000006$ times what they were before!

After each query, you'd like to know: which day's greatness modulo $1000000007$ is the largest? If multiple days tie, we're interested in the earliest of them. To keep the output size small, please print only the sum of answers to all queries.

## Input Format

Input begins with a single integer $T$, the number of test cases.  
For each case, there is first a line containing a single integer $N$.  
Then, there is a line containing $N$ space-separated integers $A_1,...,A_N$​.  
Then, there is a line containing a single integer $Q$.  
$Q$ lines follow, the $i$-th of which contains two space-separated integers $L_i$​ and $R_i$​.
