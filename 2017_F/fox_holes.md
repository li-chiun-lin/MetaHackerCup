# Problem

Kit is a young, obedient Fox who excels in his studies, diligently practices his hunting skills, and is always friendly. His parents couldn't be prouder! That is, except for one problem... he refuses to eat his vegetables!

In an effort to improve Kit's diet, his parents have set up a little game for him to play. They've dug a series of $2N + 2$ small holes in a row on the ground, and numbered them from $0$ to $2N + 1$, from first to last. They've left the first and last holes empty, and filled the remaining $2N$ holes with one healthy vegetable each! There are N different types of vegetables, numbered from $1$ to $N$, and a vegetable of type $V_i$ has initially been placed into each hole $i$, such that exactly 2 vegetables of each type were used in total.

Kit must start inside hole 0, and jump forwards from hole to hole until he reaches hole $2N + 1$. When he's inside any given hole $i$, he's agile enough to jump to either hole $i + 1$ or directly to hole $i + 2$, but he can't jump any further than that at once. Whenever he lands in a hole containing a vegetable, the rules of the game mandate that he must eat it!

Kit has agreed to play this game (not that he has much choice in the matter), but there's only so much he can take. The vegetables are tolerable as long as there's variety. He doesn't care how many he has to eat in total, but he absolutely refuses to eat multiple vegetables of any single type over the course of the game. In other words, for each vegetable type, he must only enter at most one of the two holes containing that vegetable on his way from hole $0$ to hole $2N + 1$.

Kit will play the game once per day for a period of M days. For some fun variety, at the start of each day $i$, his parents will swap the contents of two different holes $A_i$ and $B_i$. Then, Kit will play the game using the current configuration of vegetables. Once he's done, his parents will replace any vegetables which he had eaten with new vegetables of the same types, thus resetting the game to the state it was in before Kit played it.

Each day, there might be no acceptable way for Kit to complete the game, or there might be many different ways for him to do so. Two ways are considered different if at least one hole is visited in one but not the other. In order to make the game more exciting for himself, Kit would like to count up the number of different ways he could potentially complete it each day. However, that's a lot of big numbers to keep track of, so he's only interested in the sum of these $M$ values when taken modulo $1,000,000,007$. Please help him compute this overall sum!

## Input

Input begins with an integer $T$, the number of different rows of holes.  
For each row of holes, there is first a line containing the space-separated integers $N$ and $M$.  
There is next a line containing $2N$ space-separated integers, the $i$-th of which is $V_i$.  
Then $M$ lines follow, the $i$-th of which contains the space-separated integers $A_i$ and $B_i$.
