# Problem

Some engineers got tired of dealing with all the different ways of encoding status messages, so they decided to invent their own. In their new scheme, an encoded status message consists of a sequence of integers representing the characters in the message, separated by spaces. Each integer is between $1$ and $M$, inclusive. The integers do not have leading zeroes. Unfortunately they decided to compress the encoded status messages by removing all the spaces!

Your task is to figure out how many different encoded status messages a given compressed status message could have originally been. Because this number can be very large, you should return the answer modulo $4207849484$ ($0xfaceb00c$ in hex).

The compressed status messages are between $1$ and $1000$ characters long, inclusive. Due to database corruption, a compressed status may contain sequences of digits that could not result from removing the spaces in an encoded status message.

## Input

The input begins with a single integer, $N$, the number of compressed status messages you must analyze.  
This will be followed by $N$ compressed status messages, each consisting of an integer $M$, the highest character code for that database, then the compressed status message, which will be a string of digits each in the range '0' to '9', inclusive. All tokens in the input will be separated by some whitespace.
