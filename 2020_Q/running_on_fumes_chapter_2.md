# Problem

After working for many months as a delivery driver for a nationwide supply chain, you've finally received a promotion! This promotion has come with a nice pay bump, but also with the responsibility of serving regions with more complex maps. With no opportunity for a vacation, you've promptly been assigned a new series of long-haul jobs.

For each job, you will be provided with a map of the relevant region, which includes $N$ cities and $N−1$ two-way roads running amongst them. In computer science terms, the map is organized like a tree rooted at city $1$, such each city $i$ is connected to its parent city $P_i$​ by a road (aside from city $1$, which has no parent, with $P_1$​ given as $0$). It's possible to drive from any city to any other city by following a sequence of roads. Note that each road may be driven along in either direction (either from city $i$ to city $P_i$​, or vice versa).

You will begin in a given city $A$ with a shipment of supplies to be delivered to another given city $B$, and with a full gas tank having a capacity of $M$ gallons. You will then have two options at each point in time:

1. Drive along a road from your current city to an adjacent one, using up $1$ gallon of gas. You may not do this if your tank is empty, but it's fine if your tank becomes empty as a result.
1. Fill your tank all the way back up to MM gallons of gas at a cost of $C_i$​ dollars, where $i$ is your current city. Note that the cost is independent of how much gas your tank had before refueling. You may not do this if city ii has no gas station (indicated with $C_i​ = 0$).

Determine the minimum cost required to complete your delivery, if it's possible at all.

## Input

Input begins with an integer $T$, the number of long-haul jobs you are assigned.  
For each job there is first a line containing the space-separated integers $N, M, A,$ and $B$.  
Then, $N$ lines follow, the $i$-th of which contains the space-separated integers $P_i$​ and $C_i$​.
