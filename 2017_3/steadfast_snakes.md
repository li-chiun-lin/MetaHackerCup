# Problem

Once upon a time, you were the proud owner of a great many ladders and snakes. Unfortunately, you were forced to give up all but one of each, and in time, even your single remaining snake slithered away...

But all of that is about to change. You've just received word that a new executive order has been passed which will allow you to once again keep as many snakes as you'd like! To prepare, you've eagerly gone ahead and constructed a series of N ladders which will serve as a home for the impending flock of snakes. Unfortunately, it was only then that you realized your huge mistake — feeding snakes is extraordinarily expensive!

The $N$ ladders are arranged in a line on the ground, with each one standing up vertically. Each pair of consecutive ladders are $1$ metre apart from each other, and the $i$-th ladder from the left initially has a height of $H_i$ metres. As an expert in reptilian behavioral patterns, you're sure that a certain number of snakes will soon arrive on your property. In particular, every possible unordered pair of ladders will surely be claimed by a single snake, meaning that exactly $N \times (N - 1) / 2$ snakes will be showing up. If a snake claims the pair of ladders $i$ and $j$, it will want to stretch itself out perfectly between the tops of those two ladders, such that its body runs down one ladder, along the ground, and up along the other ladder. Therefore, such a snake will surely have a length of exactly $H_i + |j - i| + H_j$ metres.

You're desperate to reduce the heights of some of your ladders as quickly as possible so as to attract some shorter snakes and save your wallet. You estimate that you've got $K$ minutes to make your alterations before the snakes start showing up. Each minute, you may choose a single ladder and cut off its top few rungs, reducing its height by exactly $1$ metre. You may not shorten a ladder if it's already only $1$ metre tall. You may choose not to cut any ladders in a given minute.

As everyone knows, the daily cost of feeding a snake is proportional to its length. That being said, you're not concerned with the total amount you'll have to dish out every day, but rather on the largest amount you'll have to spend on any one snake. As such, you're like to determine the minimum possible length that the longest of the $N \times (N - 1) / 2$ snakes can end up having, given that you perform your ladder cutting optimally.

You're given $H_1$, and $H_{2..N}$ may then be calculated as follows using given constants $A$, $B$, and $C$.

$H_i = ((A \times H_{i-1} + B) \mod C + 1$

## Input

Input begins with an integer $T$, the number of different sets of ladders.  
For each set of ladders, there is first a line containing the space-separated integers $N$ and $K$.  
Then there is a line with four space-separated integers, $H_1, A, B$ and $C$.
