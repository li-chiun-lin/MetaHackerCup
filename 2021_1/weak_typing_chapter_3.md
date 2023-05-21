## Problem

Timmy the toddler is training to be a top typist. His teacher has assigned some homework in the form of a list of $T$ string exercises to be typed, consisting of only the uppercase letters "F", "O", and "X".

Timmy is eating a popsicle on a hot summer afternoon, but still hopes to complete his homework. He would like to hold the popsicle with one hand, and type with the other. Unfortunately, Timmy is still a growing boy, and each of his hands is a tad too small to reach all the way across the keyboard. He can only reach the letters "F" and "X" with his left hand, and the letters "F" and "O" with his right.

Consider a string $W$ which Timmy must type. Timmy may start typing with any hand of his choice (with the other holding the popsicle). He must then switch hands as necessary to type out the $∣W∣$ letters in order, ending on any hand of his choice.

Let $F(W)$ be the minimum number of times Timmy must switch hands to type such a string $W$.

Because Timmy's teacher would like to assign longer strings more concisely, he has encoded each exercise in a special way, through a string $U$ of length $K$, consisting of only the characters "F", "O", "X", and ".". Consider a string $S$ which is initially empty and then has $K$ updates applied to it, one after another. The $i$-th update is described by the character $U_i$​:

- If $U_i$​ is "F", "O", or "X", then the single letter $U_i$​ is appended to the end of $S$.
- Otherwise, when $U_i$​ is ".", $S$ is duplicated, with the entire current string $S$ being appended to the end of itself (for example, if $S$ = "OX", then $S$ would become equal to "OXOX" after such an update). The first update is guaranteed to not be of this type.

Let $G(S)$ be the sum of $F(W)$ over all substrings $W$ of the final string $S$ after all $K$ updates have been applied to it. Note that there are $∣S∣∗(∣S∣+1)/2$ such substrings. Please help Timmy compute the value of $G(S)$  modulo $10^9 + 7$.

## Input

Input begins with an integer $T$, the number of exercises that Timmy has been assigned.  
For each exercise, there is first a line containing the single integer $K$, followed by a second line containing the string $U$ of length $K$.
