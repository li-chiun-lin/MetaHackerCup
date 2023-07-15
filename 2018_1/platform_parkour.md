# Problem

You're about to put on an exciting show at your local circus — a parkour demonstration! $N$ platforms with adjustable heights have been set up in a row, and are numbered from $1$ to $N$ in order from left to right. The initial height of platform $i$ is $H_i$ metres.

When the show starts, $M$ parkourists will take the stage. The $i$-th parkourist will start at platform $A_i$, with the goal of reaching a different platform $B_i$. If $B_i > A_i$, they'll repeatedly jump to the next platform to their right until they reach $B_i$. If $B_i < A_i$, they'll instead repeatedly jump to the next platform to their left until they reach $B_i$. All of the parkourists will complete their routes simultaneously (but don't worry, they've been trained well to not impede one another).

Not all parkourists are equally talented, and there are limits on how far up or down they can jump between successive platforms. The $i$-th parkourist's maximum upwards and downwards jump heights are $U_i$ and $D_i$, respectively. This means that they're only able to move directly from platform $x$ to some adjacent platform $y$ if $H_x - D_i \leq H_y \leq H_x + U_i$, where $H_x$ and $H_y$ are the current heights of platforms $x$ and $y$, respectively.

With the show about to begin, a disastrous flaw has just occurred to you — it may not be possible for all of the parkourists to actually complete their routes with the existing arrangement of platforms! If so, you will need to quickly adjust some of the platforms' heights first. The height of each platform may be adjusted upwards or downwards at a rate of $1$ metre per second, to any non-negative real-valued height of your choice, and multiple platforms may be adjusted simultaneously. As such, if the initial height of platform $i$ is $H_i$ and its final height is $P_i$, then the total time required to make your chosen height adjustments will be $\max{|H_i - P_i|}$ over $i=1..N$.

Determine the minimum amount of time required to set up the platforms such that all $M$ parkourists will then be able to complete their required routes. Note that you may not perform further height adjustments once the show starts. The platform heights must all remain constant while all $M$ parkourists complete their routes.

In order to reduce the size of the input data, you're given $H_1$ and $H_2$. $H_{3..N}$ may then be generated as follows using given constants $W$, $X$, $Y$, and $Z$ (please watch out for integer overflow during this process):

$H_i = (W \times H_{i-2} + X \times H_{i-1} + Y) \mod Z$ (for $i=3..N$)

## Input

Input begins with an integer $T$, the number of shows.  
For each show, there is first a line containing the space-separated integers $N$ and $M$.  
The next line contains the space-separated integers $H_1, H_2, W, X, Y,$ and $Z$.  
Then, $M$ lines follow. The $i$-th of these lines contains the space-separated integers $A_i, B_i, U_i,$ and $D_i$.
