# Problem

Carlos knows that the key to sustained customer loyalty is early customer acquisition and constant re-engagement. With that in mind, he's setting his sights on sugary cereals. Kids love it, and they keep coming back for more. He has a proposal for Post, the well-known manufacturer of Alpha-Bits:

"For 60 years these bits have been made of letters, but kids today are tired of letters for breakfast. Let me show you something truly revolutionary: bits made of numbers!"

The executives at Post would like to assess the feasibility of producing numeric bits. In particular, they want to see if Carlos can create a string of bits, $B$, of length $N$. In this string, each character is either '0' or '1'.

Carlos has been given a list of $M$ requirements. The $i$-th requirement states that the substring $B_{X_i...Y_i}$ must be a palindrome. The new cereal surely won't succeed without appealing to children's acute sense of symmetry.

Furthermore, the number of zeroes and ones in $B$ must be as close as possible. In other words, if $C(b)$ is the number of occurrences of bit $b$ in $B$, then the absolute difference $|C(0) - C(1)|$ must be minimized. The margins on cereal are razor thin, and as everybody knows, bits are produced in pairs, so it's wasteful to use more of one sort than the other.

Help Carlos build any bitstring $B$ consistent with all of these requirements (and with minimal difference between the number of zeroes and ones). It's guaranteed that such a bitstring exists for every given set of requirements.

## Input

Input begins with an integer $T$, the number of bitstrings that Post has commissioned.  
For each bitstring, there is first a line containing the space-separated integers $N$ and $M$.  
Then, $M$ lines follow, the $i$-th of which contains the space-separated integers $X_i$ and $Y_i$.
