# Problem

Note: The only difference between this chapter and chapter 2 is that here, all card values are guaranteed to be distinct and only up to $N$.

Let's cut to the chase. You have a deck of $N$ face-up cards, each displaying a unique integer between $1$ and $N$.
Cutting the deck once consists of taking a stack of between $1$ and $N - 1$ (inclusive) cards from the top and moving it to the bottom in the same order.

Initially, the $i$-th card from the top is $A_i$​. Is it possible to cut the deck exactly $K$ times to reorder the deck such that the $i$-th card from the top is $B_i$​ for all $i$?
