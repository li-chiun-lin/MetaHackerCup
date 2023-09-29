# Problem

Pierre Peintre is slaving away over a new abstract painting entitled _Rain Over New York_. This will be a simple yet powerful piece, omitting incidental details such as busy city dwellers shielding themselves with umbrellas, and instead focusing on the fundamental atmosphere of a rainy metropolitan day. It will be painted on a canvas which is subdivided into a grid of $1cm \times 1cm$ cells, with $N$ rows and $M$ columns. Each cell in this grid will be filled in with a solid color, either black, white, grey, or blue.

The lower portion of _Rain Over New York_ will depict the skyline of New York City. In each column $i$, the bottom-most $H_i$ cells will be painted grey to represent an austere skyscraper.

Somewhere above the buildings, Pierre will place a single, innocent raincloud. In particular, the cloud can be any rectangle of white cells on the canvas, as long as none of them are supposed to be grey.

Below the cloud, there must be a gentle rainfall, of course. Every cell which has a white cell somewhere directly above it and a grey cell somewhere directly below it, and which isn't supposed to be white or grey itself, should be painted blue. Note that there may be no such cells, if the cloud is immediately above the skyline.

All of the remaining cells in the painting will be painted black, providing a serene nighttime backdrop for the scene.

Pierre knows that every painting he can produce like this will sell for an enormous sum of money, but only if it's unique. As such, he'll paint as many different paintings as he can by varying the position and dimensions of the raincloud depicted in them. Two paintings are considered distinct if at least one cell on the canvas is a different color in one painting than it is in the other.

Thanks to the incredible sum of money which Pierre is sure to make from these works, he'll be able to purchase all of the paint that he'll need. He always buys his paint in cans of a fixed size, each of which contains just enough to cover a surface of $1,000,000,007$ $cm^2$, and for each color, he'll buy just enough such cans in order to be able to complete all possible distinct variations of his painting, once each. Always one to plan ahead, Pierre would like to figure out exactly how much paint of each color he'll have left over when he's done.

The sequence $H_{1..M}$ can be constructed by concatenating $K$ temporary sequences of values $S_{1..K}$, the $i$-th of which has a length of $L_i$. It's guaranteed that the sum of these sequences' lengths is equal to $M$. For each sequence $S_i$, you're given $S_{i,1}$, and $S_{i,2..L_i}$ may then be calculated as follows, using given constants $A_i$ and $B_i$:

$S_{i,j} = ((A_i \times S_{i,j-1} + B_i) \mod (N - 1)) + 1$

## Input

Input begins with an integer $T$, the number of different base skylines Pierre wants to use.  
For each skyline, there is first a line containing the three space-separated integers, $N$, $M$, and $K$.  
Then $K$ lines follow, the $i$-th of which contains the four space-separated integers $L_i$, $S_{i,1}$, $A_i$, and $B_i$.
