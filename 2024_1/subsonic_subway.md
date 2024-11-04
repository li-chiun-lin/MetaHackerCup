# Problem

When he's not busy fighting with Dr. Robotnik, Sonic makes a living delivering submarine sandwiches via an empty subway tunnel. The tunnel goes past $N$ stations, numbered from $1$ to $N$. Station $i$ is located $i$ miles away from Sonic, who plans to run from one end of the tunnel to the other, tossing a sandwich to an awaiting customer at every station.
At each station, a customer is scheduled to meet Sonic within an expected delivery window. Sonic can deliver a sandwich to station $i$ only if he arrives within the inclusive interval $[A_i,B_i]$ seconds.
Chasing Dr. Robotnik is tiring enough, so Sonic doesn't want to exert himself more than he has to. If he runs at a constant speed, what’s the minimum speed, in miles per second, that will allow him to deliver to every station? If no such constant speed exists, output $−1$.
Your answer will be accepted if it is within an absolute or relative error of $10^{−6}$ (even if the expected answer is $−1$).

## Input Format

Input begins with an integer $T$, the number of test cases.
Each case starts with a line containing the integer $N$.
Then, $N$ lines follow, the $i$-th of which contains the integers $A_i$​ and $B_i$​.
