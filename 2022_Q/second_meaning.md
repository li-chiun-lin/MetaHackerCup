# Problem

Morse code is a classic way to send messages, where each letter in an alphabet is substituted with a codeword: a unique sequence of dots and dashes. However, ignoring spaces, it's possible for a coded message to have multiple meanings.

For example, **".....--.-.-.-..-.-.-...-.--."** can be interpreted as either **"HACKER CUP"** or **"SEE META RENT A VAN"**.

Beyond Morse code, a general set of codewords is an unambiguous encoding if any possible sequence of dots and dashes corresponds to either zero or exactly one sequence of codewords.

Given one codeword $C_1$​ from a set of $N$ distinct codewords, your task is to generate another $N - 1$ codewords $C_2, \dots,C_N$ to yield an unambiguous encoding. It can be shown that an answer always exists. If there are multiple answers, you may print any one of them.

## Input

Input begins with an integer $T$, the number of test cases.  
For each case, there is first a line containing a single integer $N$.  
Then, there is a line containing the codeword $C_1$​.
