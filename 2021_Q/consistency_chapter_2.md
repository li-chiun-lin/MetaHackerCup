# Problem

Connie received a string $S$ for her birthday, consisting entirely of uppercase letters (each between "A" and "Z", inclusive).

However, Connie really only likes nice, consistent strings. She considers a string to be consistent if and only if all of its letters are the same.

Each second, Connie may choose one letter in $S$ and replace it with a different letter. There are $K$ different types of replacements she may make, with the iiith one involving choosing letter $A_i$ anywhere in $S$ and replacing it with letter $B_i$​. No type of replacement (ordered pair of $A_i$ ​and $B_i$) is given twice. There is no limit on how many times she may end up using each type of replacement. If a letter appears multiple times in $S$, she may only replace a single occurrence per second.

Help her determine the minimum number of seconds required to change $S$ into any consistent string, if possible. If it's impossible to ever do so, output $-1$ instead. Note that $S$ might already be consistent, in which case 0 seconds would be required.

## Input

Input begins with an integer $T$, the number of birthdays Connie has had.  
For each birthday, there is one line containing the string $S$, then another line containing the integer $K$, then $K$ more lines, the $i$-th of which contains the two characters $A_i$​ and $B_i$​.
