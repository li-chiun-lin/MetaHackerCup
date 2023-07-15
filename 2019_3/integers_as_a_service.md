# Problem

Looking for a new direction for his company, Carlos wants to break into the most exciting tech field: digital rights management (DRM). In the world of DRM, mega-corporations wage perpetual war against a vast sea of e-pirates, modern-day Robin Hoods of ambiguous moral character.

One of the biggest players in this struggle is Sony, the well-known copyrighter of numbers. Considering the speed with which Sony puts out new products, it's no wonder they're having trouble coming up with enough secret encryption keys to protect all of their intellectual property. Enter Carlos.

"Gone are the days of paying over-priced number theory PhDs to craft primes by hand. I can make you a system that will generate all the numbers you need, to your exact specifications."

Sony wants to see a demonstration of Carlos's system before forking over millions of dollars in consultancy fees. They have some new products in development, each of which requires a secret key, $X$. For each key, Sony has a list of $N$ requirements. The $i$-th requirement has an operator character $O_i$, an integer value $V_i$, and an integer result $R_i$.

When $O_i$ is 'G', the $i$-th requirement states that the greatest common divisor of $X$ and $V_i$ must be $R_i$. That is, $GCD(X, V_i) = R_i$.

When $O_i$ is 'L', the $i$-th requirement states that the least common multiple of $X$ and $V_i$ must be $R_i$. That is, $LCM(X, V_i) = R_i$.

There is also a global requirement that all of Sony's secret keys must be positive integers no larger than $1,000,000,000$. Help Carlos build any positive integer $X$ consistent with all of these requirements, or determine that no such integer exists.

## Input

Input begins with an integer $T$, the number of secret keys that Sony wants Carlos to generate.  
For each number, there is first a line containing the integer $N$.  
Then, $N$ lines follow, the $i$-th of which contains the character $O_i$, and the integers $V_i$ and $R_i$, all separated by spaces.
