# Problem

Connie received a string $S$ for her birthday, consisting entirely of uppercase letters (each between "A" and "Z", inclusive).

However, Connie really only likes nice, consistent strings. She considers a string to be consistent if and only if all of its letters are the same.

Each second, Connie may choose one letter in $S$ and replace it with a different letter. If her chosen letter is a vowel, then she may replace it with any consonant of her choice. On the other hand, if her chosen letter is a consonant, then she may replace it with any vowel of her choice. The $5$ letters "A", "E", "I", "O", and "U" are considered vowels, while the remaining 21 letters of the alphabet are considered consonants. If a letter appears multiple times in $S$, she may only replace a single occurrence per second.

Help her determine the minimum number of seconds required to change $S$ into any consistent string. Note that $S$ might already be consistent, in which case 0 seconds would be required.

## Input

Input begins with an integer $T$, the number of birthdays Connie has had.  
For each birthday, there is a single line containing the string $S$.
