# Problem

Crys just invented a new cryptocurrency and is planning to present it at $T$ blockchain conferences around the world. The conference schedules are already on their way to being finalized, but Crys is considering how she might get her own talks in at the last minute.

A certain conference is $K$ hours long, with talks to start and end on the hour. Each talk will span a non-empty inclusive time interval of hours $[x,y]$, such that $x$ and $y$ are integers and $0≤x<y≤K$. $N$ talks are gradually being added to the schedule, one after another, with the $i$-th added talk scheduled to span the time interval $[S_i,S_i+D_i]$. The $N$ talks are not necessarily added in order of starting or ending time. Their time intervals may arbitrarily overlap with one another, and are not necessarily distinct.

Each time a talk is added to the schedule, Crys will then consider submitting a request for her own talk to also be included. This involves proposing a time interval for her talk, which must similarly be an integral interval $[x,y]$ such that $0≤x<y≤K$. Crys suspects that her request would be rejected if the inclusion of her talk might prevent an attendee from hearing another talk due to her proposed time interval entirely subsuming an already-scheduled one. As such, after the first $i$ talks have been added to the schedule, she will not propose a time interval $[x,y]$ if there exists any existing talk $j$ $(1≤j≤i)$ such that $x≤S_j$​ and $S_j+D_j≤y$.

Letting $C_i$​ be the number of different time intervals which Crys could validly propose for her talk after the first $i$ talks have been added to the schedule, please determine the value of $(C_1∗C_2∗...∗C_N) \mod 10^9+7$.

## Input

Input begins with an integer $T$, the number of conferences.  
For each conference there are $N+1$ lines.  
The first line contains the space-separated integers $N$ and $K$.  
$N$ lines follow, the $i$-th of which contains the space-separated integers $S_i$​ and $D_i$​.
