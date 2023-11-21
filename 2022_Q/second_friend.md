# Problem

Boss Rob painted a beautiful scene on a 2D canvas of $R$ rows by $C$ columns, containing zero or more happy little trees.

To make sure none of his trees are lonely, Rob would like you to add as many trees as you'd like (possibly $0$) to empty spaces so that each tree in the final painting has at least two tree friends, that is, two trees which are each adjacent to it (directly to its north, south, east, or west). If there are multiple solutions, you may print any one of them.

## Input

Input begins with an integer $T$, the number of test cases.  
For each case, there is first a line containing two space-separated integers, $R$ and $C$.  
Then, $R$ lines follow, each of which contains $C$ characters, either "." (an empty space) or "^" (a tree), representing the initial painting.
