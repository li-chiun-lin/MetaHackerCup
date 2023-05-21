# Problem

2020 has been a tough year for travelers. Air travel is especially problematic as passengers need to spend long periods in security lines, waiting areas, and crowded cabins where social distancing is difficult to maintain.

To minimize the spread of COVID-19, each airline has decided to reorganize all of their flight routes in a linear fashion. The airlines are hoping that by not making any one country a "hub", the spread of the virus will be significantly limited.

An airline's flights normally service $N$ countries, running in various directions. Amidst the pandemic, each airline has carefully arranged these $N$ countries in a sequence with each assigned a number from $1$ to $N$. Flights are limited to run only between pairs of countries that are adjacent in this sequence, with service in both directions. No other flights are available. That is, flights are available from country $i$ to country $j$ if and only if $∣i−j∣=1$.

To make things more complicated, some countries have issued their own restrictions on incoming and outgoing travel. These restrictions are indicated by the characters $I_{1..N}$​ and $O_{1..N}$​, each of which is either "N" or "Y":

- If $I_i$​ = "N", then incoming flights to country $i$ from any other country are disallowed. Otherwise, if $I_i = $​ "Y", they may be allowed.
- If $O_i$​ = "N", then outgoing flights from country $i$ to any other country are disallowed. Otherwise, if $O_i = $​ "Y", they may be allowed.

If a flight between adjacent countries is disallowed by the restrictions of neither its departure country nor its arrival country, then it's allowed.

As a consulting data scientist in the airline industry, your job is to determine which trips between the various countries are possible. Let $P_{i,j} =$​ "Y" if it's possible to travel from country $i$ to country $j$ via a sequence of 0 or more flights (which may pass through other countries along the way), and $P_{i,j} =$​ "N" otherwise. Note that $P_{i,i}$​ is always "Y". Output this $N∗N$ matrix of characters.

## Input

Input begins with an integer $T$, the number of airlines.  
For each airline, there are three lines.  
The first line contains the integer $N$.  
The second line contains the length-$N$ string $I_{1..N}$​.  
The third line contains the length-$N$ string $O_{1..N}$​.
