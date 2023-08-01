# Problem

Phineas is the proud owner of an enormous new fish tank! Looking at the fish tank from the side, it can be represented as an infinite 2D plane. Phineas has installed $N$ vertical dividers into the tank, the $i$-th of which is a line segment connecting points $(X_i, A_i)$ and $(X_i, B_i)$. No two dividers overlap at any point (including at their endpoints).

Unfortunately, Phineas's fish tank is lacking in fish, but he'll soon rectify that! He's going to place one or more fish into the tank, with each one initially occupying any point of his choice (each coordinate may be non-integral and arbitrarily small or large). No fish's location may overlap with any of the dividers (including their endpoints), but multiple fish may be placed at the same coordinates.

After the fish have been placed, each one may swim left and right freely (continuously decreasing or increasing its x-coordinate), as long as it never touches a divider (including its endpoints). Fish do not block one another from swimming, so multiple fish are able to occupy the same coordinates. However, no fish is able to change its y-coordinate.

At any given moment, each fish feels that its personal space is violated if any other fish is currently at the same x-coordinate as it (either at its current y-coordinate, or arbitrarily far above or below it). As such, if two fish ever occupy the same x-coordinate as one another, they both become unhappy.

Phineas suspects that someone's planning on stealing one of his dividers soon after he places fish into the tank!

And he wants to ensure that none of his fish have any chance of becoming unhappy!

But he still wants to have as many fish as possible!

As such, he'd like to determine the maximum number of fish which he can place into the tank such that, no matter which single one of the $N$ dividers is subsequently removed, and no matter how the fish then decide to swim around, none of the fish can ever become unhappy.

## Input

Input begins with an integer $T$, the number of fish tanks.  
For each fish tank, there is first a line containing the single integer $N$.  
Then, $N$ lines follow, the $i$-th of which contains the 3 space-separated integers $X_i$, $A_i$, and $B_i$.
