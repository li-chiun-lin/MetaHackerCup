# Problem

 It's time to clean up your friends list after friending too many people on Facebook over the winter. The set of your friends' user ids is $F = \{x_0, x_1, ..., x_{n-1}\}$. Each friend from F is on zero or more friend lists that you use to organize your friends. There are $M$ friend lists, $c_0, c_1, ..., c_{m-1}$. You can unfriend (remove from F) some of your friends, but because you want to stay in touch with people, you can only unfriend one person from each friend list. You may also choose not to unfriend anyone from friend list. Any friend that isn't on a friend list cannot be unfriended.

Your goal is to find the maximum possible distance between the two friends whose user ids are the closest after you are done unfriending people. The distance between user id $x$ and user id $y$ is defined as $abs(x-y)$.

## Input

The first line contains a positive integer $T$, the number of test cases. $T$ test cases follow.

The first line of each test case contains the number of friends $N$, and number of friend lists $M,$ separated by a space. The second line contains $x_0$ and integer parameters $a, b,$ and $p$, separated by spaces. You must use these to generate the remaining numbers $x_1, …, x_{n-1}$ according to this formula:

$x_i = (x_{i-1} \times a + b) \mod p$

The next $M$ lines of each test case define the friend lists for that test case. Each line consists of the following integers, separated by spaces: size, $y_0, a, b$. The size is the number of friends in the friend list. $y_0$ is the index in $F$ of the first friend in the list. You must generate the remaining friends in the friend list $y_1, …, y_{n-1}$ according to the following formula:

$y_i = (y_{i-1} \times a + b) \mod n$

If a friend list contains more than one of a given index, consider it to only contain that index once.
