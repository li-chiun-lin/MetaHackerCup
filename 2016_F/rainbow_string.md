# Problem

You have a string $S$ consisting of $N$ uppercase letters. This is no ordinary string, however — it's a rainbow string! Every letter has a colour, one of red, green, or blue (it might be ambitious to call this a rainbow, but close enough). The colour of the $i$-th letter in $S$ is indicated by the $i$-th letter in a secondary string $C$ (which also consists of $N$ uppercase letters), with the three possible values "R", "G", and "B" representing the colors red, green, and blue respectively.

You'd like to answer $Q$ questions about your rainbow string. The $i$-th question asks:

"What's the $K_i$-th lexicographically smallest substring of $S$ which has length $L_i$, includes at least one green letter, and includes no red letters?"

Note that, when considering the list of valid substrings of which to determine the $K_i$-th lexicographically smallest one, substrings which are equal to one another but occur at different positions in $S$ are distinct! Additionally, $K_i$ is guaranteed to be no larger than the number of such valid substrings.

To reduce the size of the output, you should simply output 26 integers, with the $i$-th of them being the total number of times that the $i$-th letter of the alphabet appears throughout the answers to the $Q$ questions.

## Input

Input begins with an integer $T$, the number of rainbow strings you own.  
For each rainbow string, there is first a line containing the space-separated integers $N$ and $Q$.  
The second line contains the length-$N$ string $S$ denoting the alphabetic characters in the rainbow string.  
The third line contains the length-$N$ string $C$ denoting the colours of each letter of the rainbow string, as described above.  
Then, $Q$ more lines follow, the $i$-th of which contains the space-separated integers $L_i$ and $K_i$.
