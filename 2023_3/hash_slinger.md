# Problem

Spongebob wants to go out trick-or-treating on Halloween, but has to work a graveyard shift at the Krusty Krab. Luckily, his ghostly fry cook friend, the hash-slinging slasher, is here to cover.

At the start of the shift, there are $N$ patties on the grill (numbered from $1$ to $N$), the $i$-th of which weighs $A_i$​ grams. For each order that comes in, the slasher removes from the grill a non-empty sequence of patties at contiguous indices $i..j$ (patties $i..j$ must all be on the grill at that moment). The deliciousness of the order is defined as $(A_i+...+A_j)$, modulo $M$ because too much meat can be overpowering! Note that if a patty is removed, a future order's range cannot span across that empty spot. Also, there may be patties left over at the end.

As proof of his hard work at the end of the shift, the slasher will compute a hash by taking the bitwise XOR of the deliciousnesses of all the orders. How many distinct hashes are possible across all valid sequences of $0$ or more orders?

## Input Format

Input begins with an integer $T$, the number of test cases.  
Each case begins with a line containing the two integers $N$ and $M$.  
Then, there is a single line containing $N$ integers, $A_1,...,A_N$​.
