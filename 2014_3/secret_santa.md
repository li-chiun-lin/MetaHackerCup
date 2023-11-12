# Problem

There are $K$ families living in Christmasville. During Christmas they have this tradition, where each person secretly gets a gift for some other person. The assignment of who gives gift to whom is generally done by a lottery, but this time we are writing a program to do it.

The assignment should have the following properties:

- Each person should give exactly one gift.
- Each person should receive exactly one gift.
- A person should not give a gift to someone within the same family.

Find out how many possible assignments are there, that satisfy above constraints. Two assignments are considered different, if there exists some person, who gives gifts to different people in the two assignments. Since this number may be very large, output this number modulo $1,000,000,007$.

## Input

The first line of the input consists of a single integer $T$, the number of test cases.  
Each test case starts with a line containing the integer $K$, the number of families.  
The next line of each test case contains $K$ integers, $n_1, n_2, ..., n_K$, where $n_i$ is the number of people in the $i$-th family.
