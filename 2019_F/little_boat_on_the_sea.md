# Problem

Recently, Melody built a little boat, as cute as it could be. And she put a number of animals, two-by-two, on her little boat on the sea!

Melody's boat features $N$ rooms, numbered from $1$ to $N$. The contents of the $i$-th room are described by the string $A_i$. If $A_i =$ "-", then the room is empty, while otherwise the room contains an animal of species $A_i$ (where $A_i$ is a case-sensitive alphanumeric string made up of lowercase letters "a"..."z", uppercase letters "A"..."Z", and digits "0"..."9"). There are at most two animals of any given species on the boat.

There are $N-1$ corridors in the boat, the $i$-th of which allows Melody and the animals to travel in either direction between rooms $X_i$ and $Y_i$. Each room is reachable from each other room by following a sequence of corridors.

It's time for Melody's daily walk through her boat! She'd like to choose one room to start in and a different room to end in, and walk from the former to the latter. She'll take the unique path which allows her to do so without visiting any room multiple times. Along the way, any time she finds herself in a room containing an animal (including the starting or ending room), that animal will join her for the remainder of her walk. Normally, both Melody and the animals will keep quiet, which is just how she likes it. However, if two animals of any given species ever end up joining her, they'll promptly make a racket talking to one another, which is no good! As such, she'll refuse to take a walk which would result in encountering two of any species of animal.

For how many of the $N \times (N-1)$ possible ordered pairs of starting/ending rooms would it be possible for Melody to enjoy a quiet walk from one to the other?

## Input

Input begins with an integer $T$, the number of boats.  
For each boat, there is first a line containing the integer $N$.  
Then, $N$ lines follow, the $i$-th of which contains the string $A_i$.  
Then, $N - 1$ lines follow, the $i$-th of which contains the space-separated integers $X_i$ and $Y_i$.
