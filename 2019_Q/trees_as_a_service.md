# Problem

Carlos is hoping to strike it rich with his new consulting firm, Carlos Structures Industries (CSI). With a solid mission statement and a can-do attitude, he's sure to succeed in the wide world of bespoke data structures.

"Our vision is to synergistically leverage our core competencies to deliver competitive market solutions that assertively meet our clients' needs."

His first client, the well-known translation firm Treehouse, is looking to update their logo. Treehouse wants their logo to be a rooted tree with $N$ nodes numbered $1$ through $N$. They have a rough idea of what the tree should look like, but they want Carlos to finish fleshing it out. In particular, they have $M$ requirements, the $i$-th of which states that the lowest common ancestor of nodes $X_i$ and $Y_i$ must be node $Z_i$.

Carlos's goal is to find any valid tree consistent with all of these requirements if possible, or to determine that no such tree exists.

## Input

Input begins with an integer $T$, the number of tree designs.  
For each design, there is first a line containing the space-separated integers $N$ and $M$.  
Then $M$ lines follow, the $i$-th of which contains the space-separated integers $X_i$, $Y_i$, and $Z_i$.

## Output

For the $i$-th design, print a line containing "Case #$i$: " followed by a description of a valid rooted tree if possible, or the string "Impossible" if no valid tree exists. A tree description is $N$ space-separated integers, the $j$-th of which is node $j$'s parent (or $0$ if node $j$ is the root).
