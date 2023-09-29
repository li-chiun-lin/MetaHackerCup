# Problem

You're looking at a sort of clock which has a row of $N$ lights. Each light is either on or off, and their states can be read as an $N$-digit binary number. The first light represents the most significant (leftmost) digit while the $N$-th light represents the least significant digit. A light that's on corresponds to a $1$, and a light that's off corresponds to a $0$.

You've just started looking at the clock, and you know that every second from now on, it will count upwards by $1$, with its lights turning on or off to display the next number in binary. Once the clock displays $2^N - 1$ (with all $N$ lights on), it will wrap around to display $0$ (with all lights off) on the following second, and then continue counting up again.

However, $0$ or more of the clock's lights may be permanently broken. You don't know which ones those are, but you know that they'll always appear to be off, even when they should be on.

Currently, the $i$-th light appears to be on if $L_i = 1$, and otherwise appears to be off (if $L_i = 0$). You have also received insider information that exactly $K$ of the lights are currently supposed to be on. It's guaranteed that $K$ is at least as large as the number of lights which appear to be on.

Assuming you stand around and look at this clock for a while, what's the maximum amount of time you might have to wait before you can be completely sure of what state every single light is currently supposed to be in? It's possible that you can be sure immediately, after $0$ seconds. On the other hand, it's also possible that you might never be sure, no matter how long you wait.

## Input

Input begins with an integer $T$, the number of different clocks you own.  
For each clock, there is first a line containing the two space-separated integers, $N$ and $K$.  
Then there is a line containing $N$ space-separated integers, the $i$-th of which is $L_i$.
