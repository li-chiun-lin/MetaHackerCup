# Problem

You just landed yourself a gig as a delivery driver for a nationwide supply chain. You've been assigned a series of long-haul jobs, so it's time to get to work.

For each job, you will be provided with a map of the relevant region, which includes $N$ cities and $N−1$ two-way roads running amongst them. The cities are connected by roads in a single line, such that there's a road between each pair of consecutive cities. In other words, cities $i$ and $j$ are directly connected by a road if and only if $∣i−j∣=1$.

You will begin in city $1$ with a shipment of supplies to be delivered to city $N$, and with a full gas tank having a capacity of $M$ gallons. You will then have two options at each point in time:

1. Drive along a road from your current city to an adjacent one, using up $1$ gallon of gas. You may not do this if your tank is empty, but it's fine if your tank becomes empty as a result.
1. Fill your tank all the way back up to $M$ gallons of gas at a cost of $C_i$​ dollars, where $i$ is your current city. Note that the cost is independent of how much gas your tank had before refueling. You may not do this if city $i$ has no gas station (indicated with $C_i=0$).

Determine the minimum cost required to arrive at city $N$, if it's possible at all.

## Input

Input begins with an integer $T$, the number of long-haul jobs you've been assigned.  
For each job there is first a line containing the space-separated integers $N$ and $M$.  
Then, $N$ lines follow, the $i$-th of which contains the single integer $C_i$​.
