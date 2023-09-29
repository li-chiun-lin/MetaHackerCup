# Problem

Wilson has had quite enough of his job driving trucks for a moving company, and is now interested in carrying out different sorts of deliveries — namely, pizza pie deliveries! Unfortunately, his local pizzeria already has a full-time driver, Mario Crosta, but Wilson has devised a devious plan to sabotage Mario, hopefully resulting in him getting fired and Wilson taking over.

The pizzeria is located in a town which can be modeled as a grid of cells with $N$ rows and $M$ columns, with each cell representing an intersection. There are at least two intersections (in other words, $N \times M ≥ 2$). It's possible to drive from a given intersection to any adjacent intersection (directly up, down, left, or right) in 1 minute. It's not possible to leave the grid.

The pizzeria is located at the top-left intersection, and Wilson is planning on placing an order for pizza to be delivered to the bottom-right intersection. Due to the paramount importance of pizza arriving while it's still hot, this pizzeria guarantees that their deliveries will always arrive within at most $N + M - 2$ minutes (or the customer will get their money back and also the driver will be immediately fired). Ordinarily, this is just enough time to reach even the bottom-right corner of the town, but Wilson intends to make this not an ordinary delivery.

Before placing his order, Wilson will pull some strings and arrange to have some of the intersections blocked off. In particular, he can shut down an entire axis-aligned $K \times K$ square of intersections all at once. He can even choose multiple such squares, as long as all of them lie entirely within the grid, none of them overlap with one another, and none of them include the top-left or bottom-right intersections. When he's done, Mario will be unable to pass through any intersection which is part of any of the squares.

Wilson doesn't want to block off so many intersections that Mario will be unable to complete his delivery at all, as that would likely be too obvious. Instead, he wants to make sure that the delivery is still possible but is forced to take longer than $N + M - 2$ minutes, resulting in Mario losing his job.

Despite his vast network of connections with corrupt government officials, shutting down each square of intersections will still cost Wilson a fair sum of money, so he'd like to successfully complete his sabotage by blocking off as few squares as possible. Unfortunately, it also might be the case that no possible set of squares can result in Mario's delivery taking too long without making the delivery impossible.

## Input

Input begins with an integer $T$, the number of different pizzerias Wilson wants to work for.  
For each pizzeria, there is a single line containing the three space-separated integers, $N$, $M$, and $K$.
