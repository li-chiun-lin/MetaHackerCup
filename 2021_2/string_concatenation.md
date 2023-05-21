# Problem

Taylor the tailor has just finished work on millions of outfits at the request of her friend Dorothy. Now she is left with a major cleanup job in her studio.

A given room in the studio has $N$ leftover pieces of strings scattered about, indexed from $1$ to $N$. The $i$-th piece of string has a length of $L_i$​ centimeters.

Taylor has two spools, so she would like to concatenate these strings into two threads by fusing their ends together. She plans to concatenate several pieces of string into a first thread to be stored on her first spool, and then several other pieces into a second thread to store on her second spool. A concatenated thread has length equal to the sum of the lengths of the individual strings. Pieces of string not used in either thread will be thrown away, and obviously, any given piece of string can be used in only one of the threads.

Taylor is also very particular about the cleanup process:

- She would like her two concatenated threads to be exactly the same positive length, and
- She would like to throw away at most $K$ pieces of string in total to reduce waste.

Please help Taylor determine how to concatenate strings to satisfy these requirements, if possible. If there are multiple answers, any one will be accepted.

## Input

Input begins with an integer $T$, the number of rooms in the studio.  
For each room, there is first a line containing two space-separated integers $N$ and $K$. Then, there is a line containing $N$ space-separated integers, $L_{1..N}$​.
