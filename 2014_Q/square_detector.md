# Problem

You want to write an image detection system that is able to recognize different geometric shapes. In the first version of the system you settled with just being able to detect filled squares on a grid.

You are given a grid of $N \times N$ square cells. Each cell is either white or black. Your task is to detect whether all the black cells form a square shape.

## Input

The first line of the input consists of a single number $T$, the number of test cases.  
Each test case starts with a line containing a single integer $N$.  
Each of the subsequent $N$ lines contain $N$ characters. Each character is either "." symbolizing a white cell, or "#" symbolizing a black cell. Every test case contains at least one black cell.
