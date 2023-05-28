# Problem

Dynamite is an effective tool for clearing ice to allow logs to flow downstream in the great Canadian log drive. But as every Canadian knows, successful use of dynamite requires a certain finesse. Logan the logging director is planning to hook up a network of dynamite sticks using fuse wires so that they may be detonated from afar.

Logan would like to use at most 2000 sticks of dynamite and at most 2000 fuse wires to build his dynamite network at a certain job site. He'll number the sticks from $1$ to $N$, and the wires from $1$ to $M$ (for some $N$ and $M$ of his choice). Each fuse wire is used to connect two different sticks of dynamite together. No two fuse wires may be used to connect the same unordered pair of sticks. The resulting dynamite network must all be connected (that is, it must be possible to reach each dynamite stick from each other stick by following a sequence of connected wires and sticks).

There's just one problem: sticks of dynamite are not individually powerful enough to break the thick ice. Logan must rely on chain explosions to amplify the dynamite's power. A potential chain explosion can occur anywhere in Logan's network where there is an ordered triple $(a,b,c)$ of distinct sticks of dynamite such that sticks $a$ and $b$ are connected by a fuse wire, as are sticks $b$ and $c$. Logan would like to build a network with exactly $K$ potential chain explosions, where $K$ is an even integer. Any less than $K$, and there might not be enough ice-breaking power; any more than $K$, and he risks damaging the logs.

Help Logan bust some ice by constructing any valid dynamite network for the given value of $K$. Please note that at least one valid network exists for each possible valid value of $K$.

## Input

Input begins with an integer $T$, the number of job sites.  
For each job site, there is a line containing a single integer $K$.

## Output

For the $i$-th job site, print a line containing "Case #$i$: ", followed by 2 integers $N$ and $M$, the number of sticks of dynamite and fuse wires your network will use $(1≤N,M≤2000)$.  
After that, print $M$ more lines, the $j$-th of which contains 2 integers $A_j$​ and $B_j$​, the two sticks of dynamite connected by the $j$-th fuse wire $(1≤A_j,B_j≤N,A_j≠B_j)$.
