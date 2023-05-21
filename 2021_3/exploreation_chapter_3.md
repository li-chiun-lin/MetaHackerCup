# Problem

Facebulk Inc. is a mining company who just released its latest performance reports. Backed by strong earnings, the company is now seeking to grow its infrastructure by surveying ore samples across $T$ new sites using its patented robotics tech.

A given site has been excavated after much drilling and blasting, forming a rectangular pit that's $R$ rows long by $C$ columns wide by $10^9$ cm deep. The pit consists of a grid of $R∗C$ platforms, where the platform at row $i$ and column $j$ is at height $H_{i,j}$​ cm from the bottom of the pit.

Unfortunately, there's a forecast of heavy rain — rainwater is about to start slowly flooding the pit. The water level is initially at height $0$, and will eventually fill up the entire pit at height $10^9$ cm.

Your supervisor wants $R∗C$ ore samples to be collected and analyzed, one from each platform, based on the following humidity requirements: the sample from platform $(i,j)$ is only worthwhile if collected at some point while the water level is strictly between $S_{i,j}$​ and $S_{i,j+1}$ cm.

In an attempt to accomplish this, you'll dispatch $0$ or more remote-control robots before it starts to rain, each at an initial platform of your choice. Multiple robots may occupy the same platform. At any point in time, you can command any robot at some platform $(i,j)$ to move to an adjacent platform (any platform $(i^\prime,j^\prime)$ such that $∣i−i^\prime∣+∣j−j^\prime∣=1$), or to collect an ore sample from its current platform. Rainwater will flood slowly enough that the robots have time to execute an arbitrary number of commands before water increases from any height of $x$ to $x+1$ cm.

If a robot is ever on platform $(i,j)$ while the water level is greater than or equal to $H_{i,j}$​ (either because the robot moved to that platform or because the water level increased while the robot was present on it), the robot will short circuit and stop executing any more commands.

To make matters more complicated, before you get to start implementing any plan, your supervisor will keep changing their mind about what samples are worthwhile. They'll change their mind $K$ times, such that the $i$-th time, they'll decide that $S_{A_i,B_i}$​​ will henceforth actually be equal to $U_i$​ (until they potentially change their mind about it again).

Considering the situation after your supervisor has changed their mind the first $i$ times, let $X_i$​ be the maximum number of desired ore samples which could theoretically be collected, and let $Y_i$​ be the minimum number of robots which must theoretically be dispatched to collect that many samples. Please compute the sum of $X_{1..K}$​ and the sum of $Y_{1..K}$​.

Your supervisor insists that you finish assessing the $i$-th situation and computing $X_i$​ and $Y_i$​ before they tell you how they've changed their mind for the $(i+1)$-th time. To that end, you will not be given $A_{1..K}$​, $B_{1..K}$​, and $U_{1..K}$​ directly; you'll instead be given different sequences of values $A_{1..K^\prime}​$, $B_{1..K^′}$​, and $U_{1..K^′}$​.

Given $A_1=A_1^′​, B_1=B_1^′​,$ and $U_1=U_1^′$​, for each $i≥2$ you must compute $A_i=A_i^′⊕Y_{i−1}​, B_i=B_i^′⊕Y_{i−1}​,$ and $U_i=U_i^′⊕Y_{i−1}$​ for yourself.

## Input

Input begins with an integer $T$, the number of sites to be surveyed.  
For each site, there is first a line containing 2 space-separated integers, $R$ and $C$.  
Then, $R$ lines follow, the $i$-th of which consists of $C$ space-separated integers, $H_{i,1..C}$​.  
Then, another $R$ lines follow, the $i$-th of which consists of $C$ space-separated integers $S_{i,1..C}$​.  
Then, a line will follow containing the single integer $K$.  
Then, $K$ lines will follow, the $i$-th of which contains 3 space-separated integers, $A_i^′​, B_i^′​,$ and $U_i^′$​.
