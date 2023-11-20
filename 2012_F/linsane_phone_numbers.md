# Problem

 As the Jeremy Lin sensation goes on, Roger, who is a geek and a super fan of Jeremy Lin, decides his new cell phone number must be "Linsane". More specifically, he wants his new phone number to satisfy:

1) Adjacent sum:
There is at least one occurrence in the phone number of three adjacent digits summing to $x$, where $x$ is Lin's jersey number at New York Knicks.

2) Diversity:
There are at least $y$ different values of the digits used in the phone number, where $y$ is Lin's jersey number at Golden State Warriors.

3) Neighboring difference:
There is at least one pair of neighboring digits whose difference is equal to $z$, where $z$ is Lin's jersey number at Harvard.

A phone number with length $n$ contains $n$ digits. Each digit is in the range from $0$ to $9$, except that the first digit must be non-zero.
A phone number is called "linsane" if it satisfies the three constraints listed above.

For phone numbers with a given length $n$, Roger wonders how many "linsane" phone numbers exist.

He also wants to find out the "most linsane" phone number among them.
For a given length, the "most linsane" phone number is a "linsane" phone number that has the biggest "linsanity measurement" among them.
"Linsanity measurement" is defined as , where $n$ is the number of digits and $d_i$ is the $i$-th digit in the phone number.

If there is a tie on such measurement, choose the one whose median of the digits is largest; and if there is still a tie, choose the largest phone number.

Median is the $(n+1)/2$-th smallest digit if $n$ is odd, or the average of the $(n/2)$-th and $(n/2+1)$-th digit if $n$ is even.

## Input

The first line contains a positive integer $T$, the number of test cases. $T$ test cases follow.  
Each test case is a single line and contains exactly four integers separated by single white space: $n$ $x$ $y$ $z$, where $n$ is the length of the phone number, $x$ is Lin's jersey number at New York Knicks, $y$ is Lin's jersey number at Golden State Warriors and $z$ is Lin's jersey number at Harvard.
