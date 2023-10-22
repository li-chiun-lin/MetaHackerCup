# Problem

You and some friends are playing Wiki Race on an online encyclopedia of $N$ pages, numbered from $1$ to $N$. Page $i$ covers $M_i$​ topics $S_{i,1}​ ... S_{i,M_i}$​​, each a string of lowercase letters. Each player starts on a unique page, and will race to reach page $1$ (the target page) by repeatedly clicking to neighboring pages.

Unfortunately, someone out there has already published the shortest path from each page to page $1$ for the whole internet to see. This forms a tree structure with page $1$ as the root, and edges directed upwards from each descendent page. In particular, you and your friends all know that at each page $i>1$, one should click to the neighboring page $P_i$​ for the fastest route to page $1$.

In light of this, all players have agreed to a new rule that each page should be visited by exactly one person per game. This means that once a player hits a page someone has already visited, their upward path ends there and the player loses. Formally, we can express each game's outcome as a partition of the tree into vertex-disjoint paths, with each path's upper endpoint always having an edge to a node on another player's path (except the winner, whose upper endpoint is page $1$).

After playing the game for so long, you're all starting to realize that "it's not about winning, but the knowledge acquired along the way!"

For a given partition of the tree into paths, a topic is mutually-learned by all players if every path has at least one page covering that topic. You'd like to know, across all possible partitions of paths, all topics that could be mutually-learned.

## Input Format

Input begins with an integer $T$, the number of test cases.  
For each case, there is first a line containing a single integer $N$.  
Then, there is a line containing $N−1$ integers $P_2,...,P_N$​.  
Then, $N$ lines follow, the $i$-th of which contains the integer $M_i$​, followed by strings $S_{i,1}​ ... S_{i,M_i}$​​.
