# Problem

Meta Snacker Cup is an event where foodies of the world congregate to try snacks made by top chefs. For the first course, there is a selection of ham snacks, each denoted as a single letter from an alphabet $Σ$. A customer can make an order, which is any string consisting of letters from $Σ$.

Due to the sheer popularity of Snacker Cup, the organizers have built robots to automate ordering. Unfortunately, the bots are in beta and can make mistakes. To help untangle orders, a metric called the Ham distance is used. Given two length-$N$ strings $s_1$​ and $s_2$​, the Ham distance $h(s_1,s_2)$ is the number of places in which they differ.

One of the robots recorded two orders $S_1$​ and $S_2$​ of equal length $N$. Each of these is a duplicate of the same original order given by a customer, but each diverged via zero or more letter substitutions (mistakes). Unfortunately, the robot crashed and lost both the two recorded orders, and the original order. From the error logs, you only know that:

- $h(S_1,S_2)=H$
- Order $S_1$​ had at most $M_1$​ mistakes, i.e. the original order is in $\{s:h(s,S_1)≤M_1\}$
- Order $S_2$​ had at most $M_2$​ mistakes, i.e. the original order is in $\{s:h(s,S_2)≤M_2\}$

You'd like to count the number of ways the original order and the two recorded orders could have been made. Formally, you'd like to know the value of:

$∑_{S_1,S_2∈Σ^N, h(S_1,S_2)=H}∣\{s:h(s,S_1)≤M_1\}⋂\{s:h(s,S_2)≤M_2\}∣$

As this number may be very large, print it modulo $1,000,000,007$.

## Input Format

The first line contains the number of test cases $T$.
For each case, there is a single line consisting of five space-separated integers $N, M_1​, M_2​, H,$ and $∣Σ∣$.
