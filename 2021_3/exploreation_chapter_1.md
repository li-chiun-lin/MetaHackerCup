# Problem

Facebulk Inc. is a mining company who just released its latest performance reports. Backed by strong earnings, the company is now seeking to grow its infrastructure by surveying ore samples across $T$ new sites using its patented robotics tech.

A given site has been excavated after much drilling and blasting, forming a rectangular pit that's $R$ rows long by $C$ columns wide by $10^9$ cm deep. The pit consists of a grid of $R∗C$ platforms, where the platform at row $i$ and column $j$ is at height $H_{i,j}$​ cm from the bottom of the pit.

Unfortunately, there's a forecast of heavy rain — rainwater is about to start slowly flooding the pit. The water level is initially at height $0$, and will eventually fill up the entire pit at height $10^9$ cm.

Your supervisor wants $R∗C$ ore samples to be collected and analyzed, one from each platform, based on the following humidity requirements: the sample from platform $(i,j)$ is only worthwhile if collected at some point while the water level is strictly between $S_{i,j}$​ and $S_{i,j}+1$ cm.

In an attempt to accomplish this, you'll dispatch 00 or more remote-control robots before it starts to rain, each at an initial platform of your choice. Multiple robots may occupy the same platform. At any point in time, you can command any robot at some platform $(i,j)$ to move to an adjacent platform, or to collect an ore sample from its current platform. Rainwater will flood slowly enough that the robots have time to execute an arbitrary number of commands before water increases from any height of $x$ to $x+1$ cm.

If a robot is ever on platform $(i,j)$ while the water level is greater than or equal to $H_{i,j}$​ (either because the robot moved to that platform or because the water level increased while the robot was present on it), the robot will short circuit and stop executing any more commands.

Let $X$ be the maximum number of desired ore samples which can be collected, and let $Y$ be the minimum number of robots which must be dispatched to collect that many samples. Please compute $X$ and $Y$.

## Input

Input begins with an integer $T$, the number of sites to be surveyed.  
For each site, there is first a line containing 2 space-separated integers, $R$ and $C$.  
Then, $R$ lines follow, the $i$-th of which consists of $C$ space-separated integers, $H_{i,1..C}$​.  
Then, another $R$ lines follow, the $i$-th of which consists of $C$ space-separated integers $S_{i,1..C}$​.
