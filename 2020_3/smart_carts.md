# Problem

Every week you take a socially-distanced trip to Overwaitea, your favourite grocery store, to stock up on food. Out front, there are $N$ shopping carts. To dissuade theft, the carts are locked together and you need to insert a quarter to unlock one cart from the rest. When you return your cart, you get your quarter back. Now that you think about it, maybe 25 Canadian cents is actually a pretty good deal for your very own shopping cart...

Each cart has a connecting chain leading out of it. There are also $N+2$ latches, which chains may be connected to (with each latch having at most one incoming chain). Each of the first $N$ latches can be found on carts, with latch $i$ fixed to cart $i$. The remaining two latches (latches $N+1$ and $N+2$) are instead mounted to a wall. Each cart $i$'s chain is initially connected to latch $A_i$​, but you suspect it would be more aesthetically pleasing if it was instead attached to an ideal target latch $B_i$​.

A sequence of $K$ carts $S_{1..K}$​ is one in which latch $S_1$​ has no incoming chain, cart $S_1$​'s chain connects to latch $S_2$​, cart $S_2$​'s chain connects to latch $S_3$​, and so on, with cart $S_{K−1}$​'s chain connecting to latch $S_K$​, and cart $S_K$​'s chain not connecting to any cart (but rather to either a wall latch or no latch).

The carts are rigid enough that it's impossible to ever form a "cycle" of carts, such that repeatedly following chain connections forwards from an initial cart will result in returning to that initial cart. This means that each cart is always part of exactly one sequence, and is present in that sequence exactly once.

The values of $A_{1..N}$​ and $B_{1..N}$​ are given such that the carts initially form a valid configuration (with no "cycles"), and would also form a valid configuration if every cart's chain were to be connected to its ideal target latch.

You may repeatedly perform either of the following actions before leaving the carts in a desired final state, in which every chain must end up once again connected to a latch:

1. Pay 1 quarter (if you have at least 1) to detach any given cart's chain from whichever latch it's currently connected to (if any)
1. Gain 1 quarter by attaching any given cart's currently-unattached chain to a latch (as long as no other chain is currently connected to that latch, and a "cycle" of carts would not be formed)

Consider a hypothetical scenario in which:

- You begin with $Q$ quarters
- A sequence consisting of more than $C$ carts must never be present (including initially)
- The final state must not have a sequence consisting of more than $X$ carts attached to latch $N+1$
- The final state must not have a sequence consisting of more than $Y$ carts attached to latch $N+2$

Let $F(Q,C,X,Y)$ be the maximum number of chains which can end up connected to their ideal target latches in a final state given such a scenario, or $−1$ if it's impossible to achieve a valid final state at all.

Let $G(v)$ be the number of quadruples $(Q,C,X,Y)$ such that $0≤Q,C,X,Y≤N$ and $F(Q,C,X,Y)=v$. You'd like to compute $G(v)$ for each integer $v$ such that $−1≤v≤N$.

## Input

Input begins with an integer $T$, the number of sets of shopping carts.  
For each set there are $N+1$ lines.  
The first contains the integer $N$.  
$N$ lines follow, the $i$-th of which contains the space-separated integers $A_i$​ and $B_i$​.
