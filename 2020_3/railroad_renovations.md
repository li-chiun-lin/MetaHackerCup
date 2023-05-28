# Problem

Pennington has taken $N$ trips on his favourite railroad line, which is 1 billion metres long.

When the line was first built, creaky wood was used to support the tracks, which made a terrible racket as the train ran along them. Pennington is aware that, since then, 0 or more renovations have been made to the line at various points in time (either before his first trip or in between some of his trips), each of which would have involved replacing the supports along some continuous, possibly-degenerate interval of the line with integer endpoints (for example, the intervals $[1m,2m]$ or $[3m,3m]$ could have been renovated, but not $[3.5m,4.5m]$). No renovations were made during any of his trips. No two renovations' intervals could have inclusively overlapped with one another (for example, if one renovation involved the interval of positions $[5m,10m]$, then there could not have been another one involving $[6m,8m]$ nor $[10m,11m]$, but there could have been one involving $[11m,12m]$). Renovations would never have been undone; each one had a permanent effect on its interval of the line.

In general, Pennington just sleeps the entire time he's on the train (it is a long ride, after all). However, he did briefly wake up exactly once per trip he's taken. During his $i$-th trip, he woke up while the train was at position $P_i$​ metres along the line, and he noticed whether the supports at that position had been renovated by that point in time — if $R_i=1$, they had been, while if $R_i=0$, they had not been.

Pennington suspects he might have misremembered the order of his trips, though. To get their actual order, it may be necessary to take up to $K$ of them and insert them into other positions in the ordered list of trips (with each one moved to either before the first trip, between any two trips, or after the final trip). For example, if $K=1$, he could rearrange the 2nd trip to have actually occurred between the 4th and 5th trips (essentially shifting trips 3 and 4 to have been his 2nd and 3rd trips). It's possible that his observations would only be consistent with any possible sequence of renovations after some rearrangements of this sort, or even that they would be inconsistent after any possible set of $K$ rearrangements.

What's the minimum possible number of renovations that could have been made by the end of Pennington's final trip which would have been consistent with all $N$ of his observations (after rearranging at most $K$ of the trips), if this would have been possible at all?

## Input

Input begins with an integer $T$, the number of sets of train trips.  
For each set there are $N+1$ lines.  
The first line contains the 2 space-separated integers $N$ and $K$.  
$N$ lines follow, the $i$-th of which contains the 2 space-separated integers $P_i$​ and $R_i$​.
