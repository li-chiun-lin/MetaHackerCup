# Problem

Patrick's big sister Sam is visiting for Halloween, and Sandy wants to impress the two Stars by dressing as an astronaut. Unfortunately her regular outfit already resembles an astronaut, so she'll have to go as a computer scientist instead. Sandy knows a lot about double stars in astronomy, but will now have to learn about double stars in graph theory.

There is an unrooted tree with $N$ nodes, and an edge between nodes $i$ and $P_i$​ (for each $i≥2$). A double star is a tree centered at some edge $u↔v$, where $u$ and $v$ each have $x$ chains connected to them, each chain consisting of $y$ nodes ($x,y≥1$). Alternatively, you can think of a double star as two identical star graphs (each with $x$ chains of length $y$) connected by their centers. Thus, a distinct double star is specified by a tuple $(u,v,x,y)$, where $u<v$.

Please help Sandy count the number of distinct tuples $(u,v,x,y)$ for which the tree contains the double star described by that tuple as a subgraph.

## Input Format

Input begins with an integer $T$, the number of test cases. Each case has two lines.  
The first contains the integer $N$, and the second contains the $N−1$ integers $P_2$​ through $P_N$​.
