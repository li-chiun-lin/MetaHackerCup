# Problem

Percy is a harlequin tuskfish who lives on a stretch of the sea floor, which may be represented as a number line. There are $N$ objects resting on the sand beneath the waves, the $i$-th of which is at a positive integral position $P_i$, is either a clam (if $O_i =$ "C") or otherwise a rock (if $O_i =$ "R"), and in either case has a hardness of $H_i$. No two objects are at the same position, and at least one of the objects is a clam.

Percy initially finds himself at position $0$, and can then swim in either direction along the number line at a rate of 1 unit per second. Whenever he occupies the same position as a clam, he may pick it up and begin carrying it around in his mouth. Picking up a clam requires no additional time, and Percy is talented enough to carry any number of clams at once.

Percy would like to devour the delicious interior of each clam, but can't get to it without first somehow breaking open its hard shell. Fortunately, Percy is clever and persistent enough to have a solution to this problem. Whenever he occupies the same position as a rock, he may take each clam that he's currently carrying that has a strictly smaller hardness than that of the rock, knock the clam against the rock to break open its shell, and eat the meal packaged within! This process requires no additional time per clam.

What's the minimum amount of time required for Percy to swim around and eat all of the clams (by picking each one up and then knocking it against a harder rock than itself), if at all possible?

In order to reduce the size of the input, the object's positions and hardnesses will not all be provided explicitly. Instead, you'll be given $P_1, P_2, H_1, H_2,$ as well as the 8 constants $A_p, B_p, C_p, D_p, A_h, B_h, C_h,$ and $D_h$, and must then compute $P_{3..N}$ and $H_{3..N}$ as follows (bearing in mind that intermediate values may not fit within 32-bit integers):

$P_i = ((A_p \times P_{i-2} + B_p \times P_{i-1} + C_p) \mod D_p) + 1$, for $i = 3$ to $N$.  
$H_i = ((A_h \times H_{i-2} + B_h \times H_{i-1} + C_h) \mod D_h) + 1$, for $i = 3$ to $N$.

## Input

Input begins with an integer $T$, the number of days Percy goes hunting for clams. For each day, there are four lines.  
The first line contains the integer $N$.  
The second line contains the space-separated integers $P_1, P_2, A_p, B_p, C_p,$ and $D_p$.  
The third line contains the space-separated integers $H_1, H_2, A_h, B_h, C_h,$ and $D_h$.  
The fourth line contains the length-$N$ string $O_{1..N}$.
