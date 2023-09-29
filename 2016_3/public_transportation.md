# Problem

You live on a circular road, $L$ metres in length. Any point on the road can be referred to by a real number $x$ $(0 ≤ x < L)$, the distance along the road clockwise from its Northmost point to that point (in metres).

Fortunately for you, this road is served by public transportation! There are $N$ bus stops at distinct, integral points along the road.

Unfortunately for you, due to budget cuts exactly $K$ of these $N$ stops will soon be removed. The group of $K$ removed stops will be chosen uniformly at random from the set of all possible groups of $K$ stops.

You'd like to calculate the expected distance you'll have to walk from a random point along the road, chosen uniformly at random from the interval $[0, L)$, to the nearest of the remaining $N - K$ bus stops, in metres.

## Input

Input begins with an integer $T$, the number of roads.  
For each road, there is first a line containing the space-separated integers $N$, $K$, and $L$.  
Then follows a line containing a string of length $L$. This string consists of only the characters '0' and '1'. There is a bus stop at position $x$ if and only if the $(x + 1)$-th character of the string is '1'. Exactly $N$ of the characters will be '1'.
