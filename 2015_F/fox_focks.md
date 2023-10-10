# Problem

Mr. Fox has opened up a fabulous Fock farm! A Fock is a cute little animal which can have either red, green, or blue fur (these 3 possible colors can be numbered 1, 2, and 3, respectively). Furthermore, a Fock's fur color can change every second!

Mr. Fox owns a flock of $N$ Focks, with the $i$-th one initially having a color of $C_i$. Every second, if the $i$-th Fock currently has a color of $a$, it will switch to having a color of $b$ for the next second with probability $P_{i,a,b}\%$. All Focks change color simultaneously.

After a very large amount of time has gone by, Mr. Fox will take a single photo of all of his Focks to help advertise his farm. In particular, he picks an integer $t$ at uniform random from the range $[10^{100}, 10^{1000}]$ and waits that many seconds. He's hoping that the photo will make it look like his farm has a well-balanced mix of Fock colors — it'll be no good if the photo ends up featuring a strict majority of a single color (that is, strictly more than $N/2$ of the Focks having the same color). What's the probability of this occurring?

## Input

Input begins with an integer $T$, the number of Fock farms Mr. Fox has.  
For each farm, there is first a line containing the integer $N$.  
Then, for each Fock $i$, 4 lines follow.  
The first of these lines contains the integer $C_i$.  
The next three lines contain three space-separated integers each, with the $b$-th integer on the $a$-th line being $P_{i,a,b}$.
