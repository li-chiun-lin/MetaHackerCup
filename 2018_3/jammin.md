# Problem

Uriel is an android programmed for a singular purpose — to obtain jam. He's found himself in a row of cells, some of which hopefully contain raspberry jam for him to gather in the form of special jars called "jammers".

There are $|C|$ cells in the row, and their contents are described by a string $C$, with the $i$-th character of $C$ corresponding to the $i$-th cell. Each character is one of the following:

- ".": Empty cell
- "*": Cell initially containing a jammer
- "#": Cell containing a laser barrier

By default, each laser barrier is "active". However, whenever a laser barrier has at least one jammer in an adjacent cell to its left or right, that laser barrier becomes jammed by the jammer's jam, and becomes "inactive" instead. A laser barrier may switch back and forth between being inactive and active if jammers next to it are added or removed. A single jammer may be responsible for jamming multiple laser barriers at once.

Uriel begins in the first cell (which is guaranteed to be empty). He has the ability to carry around any number of jammers at once, though he initially has $0$ of them. At each point in time, he may choose to perform one of the following actions:

- Pick up a jammer from his current cell. He may only do so if the cell contains a jammer. That cell will then become empty.
- Place one of his jammers into his current cell. He may only do so if he's holding at least one jammer, and if the cell is currently completely empty (it doesn't contain another jammer, and doesn't contain a laser barrier, even if it's inactive).
- Walk left or right into an adjacent cell, without leaving the row of cells. He may only do so if that cell doesn't currently contain an active laser barrier.

Uriel isn't interested in consuming any jam, he just wants to hold onto it — onto as much of it as he can. As such, he'd like to determine the maximum number of jammers which he can ever end up holding at a single time, after performing any number of moves of his choice.

## Input

Input begins with an integer $T$, the number of rows of cells.  
For each row of cells, there is a single line containing the string $C$ as described above.
