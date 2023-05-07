# Problem

Your friend baked $N$ batches of cookies, the first with chocolate chips, and the rest with raisins. Batch $i$ has $C_i$​ cookies all having the same weight $W_i$​. Cookies in different batches may have the same weight. Initially, all cookies are scattered on the table, and you hope to find a hefty one to eat with your trusty balance scale.

First, you select a single cookie uniformly at random from the table and place it on the left side of the scale. Then, $K$ times, you will select a cookie uniformly at random from the table, place it on the empty side of the scale, and throw away the lighter of the two cookies on the scale (or the cookie on the left side if they both weigh the same).

Determine the probability that after throwing away $K$ cookies, the remaining cookie on the scale is a yummy chocolate chip cookie from batch $1$.

If we write this probability as a quotient of integers $p/q$ in lowest terms, then you should output this quotient modulo $1{,}000{,}000{,}007$ — in other words, output the unique integer $x$ such that $0 \le x \lt 1{,}000{,}000{,}007$ and $p = (x * q) \text{ mod } 1{,}000{,}000{,}007$.
