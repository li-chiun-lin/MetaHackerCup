# Problem

Timmy the toddler is training to be a top typist. His teacher has assigned some homework in the form of a list of **T** string exercises to be typed, consisting of only the uppercase letters **"F"**, **"O"**, and **"X"**.

Timmy is eating a popsicle on a hot summer afternoon, but still hopes to complete his homework. He would like to hold the popsicle with one hand, and type with the other. Unfortunately, Timmy is still a growing boy, and each of his hands is a tad too small to reach all the way across the keyboard. He can only reach the letters **"F" and "X" with his left hand**, and the letters **"F" and "O" with his right**.

Consider a string **W** which Timmy must type. Timmy may start typing with any hand of his choice (with the other holding the popsicle). He must then switch hands as necessary to type out the **|W|** letters in order, ending on any hand of his choice.

Given an exercise string **W** of length **N**, let **F(W)** be the minimum number of times Timmy must switch hands to type **W**. Please help Timmy compute the value of **F(W)**.

## Input

Input begins with an integer $T$, the number of exercises that Timmy has been assigned.  
For each exercise, there is first a line containing the single integer $N$, followed by a second line containing the string $W$ of length $N$.
