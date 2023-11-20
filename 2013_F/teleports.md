# Problem

Your house has $N$ distinct rooms. None of the rooms have doors, but every room has a one way teleport which takes you to a different room. The same teleport will always go to the same room. You want to make sure that every room can be reached from every room, via a series of teleports. To do this, you are allowed to change the destination of some (or all) of the teleports.

What is the sum of the minimum number of teleports you have to change to achieve this, over all possible different starting configurations? Two starting configurations are different if for some room, the outgoing teleport goes to different rooms in the two configurations.

Since this number might be very big, output it modulo $1,000,000,007$.

## Input

The first line contains a single integer $T$. $T$ test cases follow, where each test case consists of one integer: $N$
