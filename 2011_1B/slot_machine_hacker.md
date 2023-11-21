# Problem

You recently befriended a guy who writes software for slot machines. After hanging out with him a bit, you notice that he has a penchant for showing off his knowledge of how the slot machines work. Eventually you get him to describe for you in precise detail the algorithm used on a particular brand of machine. The algorithm is as follows:

```c
int getRandomNumber() {
  secret = (secret * 5402147 + 54321) % 10000001;
  return secret % 1000;
}
```

This function returns an integer number in $[0, 999]$; each digit represents one of ten symbols that appear on a wheel during a particular machine state. secret is initially set to some nonnegative value unknown to you.

By observing the operation of a machine long enough, you can determine value of secret and thus predict future outcomes. Knowing future outcomes you would be able to bet in a smart way and win lots of money.

## Input

The first line of the input contains positive number $T$, the number of test cases. This is followed by $T$ test cases.  
Each test case consists of a positive integer $N$, the number of observations you make.  
Next $N$ tokens are integers from $0$ to $999$ describing your observations.
