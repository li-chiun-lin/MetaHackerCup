# Problem

Do you remember helping Prince Z.A.Y. rescue the princess of the kingdom of Hackadia from an evil dragon in Round 2? Well, as it so often happens, Z.A.Y. has fallen in love with his dearest princess. However, the princess has given Z.A.Y. a puzzle to solve to ensure that the one she marries is both brave and clever.

The princess gives Z.A.Y a 0-indexed array of $N$ integers, and she asks him a series of questions. In each question, she provides an inclusive interval to the prince, and asks him how many subarrays in that interval are slowly increasing.

A subarray is defined as a contiguous set of integers in the given array. A subarray is slowly increasing iff each integer in the subarray after the first is exactly $1$ more than the previous integer. For example, $[1, 2, 3], [5],$ and $[10, 11, 12]$ are slowly increasing, but $[7, 9], [13, 12, 11],$ and $[1, 1, 2, 2]$ are not.

Easy problem, right? Yup, so the princess is going to make it more challenging since she knows the prince is seeking help from the best Hackers from the world. Sometimes, instead of asking a question, the princess will change an integer in the array.

Still an easy problem, right? Probably, but the princess isn't going to make it any harder (the prince *did* rescue her from a dragon, and could probably use a break).

## Input

The first line consists of a single integer $T$, the number of test cases.  
Each test case starts with a line containing an integer $N$, the length of the array.  
Then 1 line follows with $N$ integers $X_i$ representing the elements of the array.  
Then 1 line follows with an integer $M$, the number of actions the princess takes (questions and updates).  
Then $M$ lines follow, each with 3 integers. The first integer, $op$, represents the action the princess takes.  
If $op$ is $0$, then 2 integers $P$ and $K$ follow, meaning that the princess will change the $P$-th element of the array to $K$.  
If $op$ is $1$, then 2 integers $L$ and $R$ follow, meaning that the princess will ask how many slowly increasing subarrays there are between $L$ and $R$ (inclusive).
