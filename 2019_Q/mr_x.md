# Problem

"There's nothing more important than $x$!", laughs Mr. X as he explains a Boolean expression involving a variable $x$ to you and your classmates. He can't go 5 minutes teaching Boolean algebra without making at least one such "joke"...

In Mr. X's class, you've been learning about single-variable Boolean expressions, which are made up of the variable $x$ (and its negation), Boolean constants ($True/False$), and binary Boolean operators. A valid expression is a string in one of the following two forms:

1) A single term, which is one of the following four characters:

    - "x": The variable $x$
    - "X": The negation of the variable $x$
    - "0": The constant $False$
    - "1": The constant $True$

1) A binary operator joining two valid expressions in the format "([expression] [operator] [expression])", with the operator being one of the following three characters:

    - "|": The OR operator (evaluating to $True$ when at least one of its operands is $True$)
    - "&": The AND operator (evaluating to $True$ when both of its operands are $True$)
    - "^": The XOR operator (evaluating to $True$ when exactly one of its operands is $True$)

For example, the following expressions are valid:

- "1"
- "(x^0)"
- "((X&0)|x)"

While the following expressions are invalid:

- "(1)"
- "x^0"
- "(X&0|x)"

An upcoming test will feature a valid expression $E$ in the above format, which must be evaluated for a certain value of $x$. However, you've been getting tired of Mr. X and his lame jokes about the importance of $x$, so you're planning on hacking into his test files and changing the expression so as to make $x$ irrelevant! In particular, you'd like to modify as few characters as possible in $E$ such that it ends up still being a valid expression, but such that its overall value doesn't depend on the value of the variable $x$. You may only change characters in-place into different characters — you may not insert or delete characters.

For example, the expression "(X|(0&x))" evaluates to $True$ if $x$ is $False$, and $False$ if $x$ is $True$. If it were to be changed into "((X&0)&1)" (by modifying its 2nd, 3rd, 4th, 6th, 7th, and 8th characters), then it would evaluate to $False$ regardless of $x$'s value. Though, it's also possible to make its value independent of $x$ by modifying fewer than 6 of its characters.

Given an expression $E$, what's the minimum number of characters which must be modified? It's possible that no characters may need to be modified at all.

## Input

Input begins with an integer $T$, the number of tests. For each test, there is a line containing the expression $E$.
