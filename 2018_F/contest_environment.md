# Problem

The 2018 Hacker Cup finals are underway! The contest is being held in a room with $2$ rows of $N$ desks each, with finalists sitting at some of them.

One of the finalists, Alex, is sitting at the leftmost desk in the front row. Another finalist, Borys, is sitting at the rightmost desk in the front row. Unfortunately, both of them find themselves distracted by the contest room's environment — Alex is a bit too hot on his side of the room, while Borys is a bit too cold. If only they could switch places! Unfortunately, this would be against the rules, but if they work together with some other contestants, perhaps they can manage it without the contest organizers noticing...

The initial state of each row of desks can be represented by a string of $N$ characters, with the $i$-th character corresponding to the $i$-th desk from the left in that row. Each character is one of the following:

- A - Alex's desk (guaranteed to appear exactly once, as the leftmost desk in the front row)
- B - Borys's desk (guaranteed to appear exactly once, as the rightmost desk in the front row)
- \* - A cooperative finalist's desk
- \# - An uncooperative finalist's desk
- . - An unoccupied desk

At any point, a single finalist may move from their current desk to an adjacent, currently-unoccupied desk. Two desks are considered adjacent if either they're in the same column, or they're directly side-by-side in the same row. However, the finalists won't be foolish enough to move sideways between two desks in the front row, as that would surely attract the contest organizers' attention.

Alex, Borys, and any cooperative finalists may all move between desks in this fashion. On the other hand, uncooperative finalists are too busy actually competing, and will never move from their original desks.

Assuming that Alex, Borys, and the cooperative finalists all work together, is it possible for Alex and Borys to switch seats (in other words, for Alex to occupy the front row's rightmost desk while Borys simultaneously occupies its leftmost desk) without the contest organizers noticing?

## Input

Input begins with an integer $T$, the number of parallel universes in which the 2018 Hacker Cup is occurring.  
For each universe, there are two lines of $N$ characters each, as described above. The first line is the front row of desks, and the second line is the back row of desks.
