# Problem

The Facebook campus has $N$ different attractions, numbered from $1$ to $N$ in decreasing order of popularity. The name of the $i$-th attraction is $A_i$, a unique, non-empty string consisting of at most 20 characters. Each character is either a lowercase letter ("a".."z"), uppercase letter ("A".."Z"), or digit ("0".."9").

Alex enjoys visiting the campus repeatedly for tours (including the free food!). Each time he visits, he has time to see exactly $K$ of the attractions. To decide which $K$ he'll see, he sorts the $N$ attractions in non-decreasing order of how many times he's already seen them before, breaking ties in decreasing order of popularity, and then chooses the first $K$ attractions in the sorted list. In other words, he prioritizes seeing attractions which he's seen the fewest number of times previously, but also opts to see the most popular attractions out of the ones he's seen an equal number of times.

Alex has visited the Facebook campus $V-1$ separate times already, and is about to go for his $V$-th visit. Given that he's always followed the rules stated above, and that he'll continue to, he'd like to determine which $K$ attractions he'll see on his $V$-th visit. He'd like to list them in decreasing order of popularity (in other words, in the same relative order as they appear in the given list of all $N$ attractions).

## Input

Input begins with an integer $T$, the number of campuses.  
For each campus, there is first a line containing the space-separated integers $N$, $K$, and $V$.  
Then, $N$ lines follow. The $i$-th of these lines contains the string $A_i$.
