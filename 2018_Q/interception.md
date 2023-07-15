# Problem

Consider an $N$-degree polynomial, expressed as follows:

$P_N \times x^N + P_{N-1} \times x^{N-1} + ... + P_1 \times x^1 + P_0 \times x^0$

You'd like to find all of the polynomial's $x$-intercepts — in other words, all distinct real values of $x$ for which the expression evaluates to $0$.

Unfortunately, the order of operations has been reversed: Addition $(+)$ now has the highest precedence, followed by multiplication $(\times)$, followed by exponentiation $(\wedge)$. In other words, an expression like $a^b + c \times d$ should be evaluated as $a^{((b+c) \times d)}$. For our purposes, exponentiation is right-associative (in other words, $a^{b^c} = a^{(b^c)}$), and $0^0 = 1$. The unary negation operator still has the highest precedence, so the expression $-2^{-3} \times -1 + -2$ evaluates to $-2^{(-3 \times (-1 + -2))} = -2^9 = -512$.

## Input

Input begins with an integer $T$, the number of polynomials.  
For each polynomial, there is first a line containing the integer $N$, the degree of the polynomial.  
Then, $N+1$ lines follow. The $i$-th of these lines contains the integer $P_{i-1}$.
