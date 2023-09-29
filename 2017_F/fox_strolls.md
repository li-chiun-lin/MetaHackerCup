# Problem

A certain forest has $N$ trees growing in it, and there just so happens to be a Fox living at the top of each one! The trees are numbered from $1$ to $N$, and their bases are all arranged in a straight line on the ground, with 1 metre between the bases of each pair of adjacent trees $i$ and $i + 1$. Each tree $i$ is $H_i$ metres tall.

The Foxen are all good friends with one another, and frequently like to go out for strolls to visit each other's homes. Rather than jumping directly between the trees, they prefer to always keep their paws firmly planted on some surface, such as tree trunks or the ground. As such, the shortest possible trip from the top of tree $i$ to the top of another tree $j$ requires climbing down tree $i$ to the ground, walking along the ground to the base of tree $j$, and then climbing up to its top, resulting in a total distance of $H_i + |j - i| + H_j$ metres traveled.

However, the Foxen aren't terribly satisfied with how long their trips currently take. Given the frequency of their strolls, they've decided to invest in reducing their travel distance by constructing some bridges between the tree trunks. They're only interested in building metre-long, horizontal bridges. Each bridge may be constructed to connect any pair of adjacent trees $i$ and $i + 1$, and it may be placed at any height above the ground, as long as it touches both of those tree trunks (in other words, its height must be no larger than the minimum of $H_i$ and $H_{i+1}$). Multiple bridges may be constructed at different heights between any given pair of adjacent trees. Once bridges are installed, the Foxen will be willing to walk across them, potentially saving them the time of descending all the way to the ground during their strolls.

There are $N \times (N - 1) / 2$ different pairs of Foxen $i$ and $j$ who might want to meet up, requiring a trip to be taken from the top of tree $i$ to the top of tree $j$ (or vice versa). The Foxen's top priority is minimizing the sum of the $N \times (N - 1) / 2$ pairwise shortest distances of strolls which would be required for these visits to take place. Please help them determine the minimum possible value of this sum, assuming that they construct as many bridges as it takes. That being said, they don't want to spend all day constructing bridges either... as such, they're also interested in the minimum number of bridges which they can construct to achieve that minimum possible sum of pairwise distances.

## Input

Input begins with an integer $T$, the number of forests. For each forest, there are two lines.  
The first line contains the integer $N$.  
The second line contains $N$ space-separated integers, the $i$-th of which is the integer $H_i$.
