# Problem

Matt Laundro is about to engage in his favourite activity — doing laundry! He's brought $L$ loads of laundry to his local laundromat, which has recently been cracking down on excessive washer and dryer usage. It turns out the other customers weren't very thrilled when they saw Matt using a billion washers and dryers simultaneously, so he's now been restricted to just one washer and one dryer. Matt's $i$-th load of laundry takes $W_i$ minutes to wash, and $D_i$ minutes to dry. As is usually the case with laundry, each load takes at least as long to dry as it does to wash. At any point in time, each machine may only be processing at most one load of laundry.

As one might expect, Matt wants to wash and then dry each of his $L$ loads of laundry. Unfortunately, the laundromat closes in $K$ minutes, so he might not be able to get through every load. But he'll try his best! If he chooses to wash and dry the $i$-th load of laundry, it will go through the following steps in order:

1. A non-negative amount of time after Matt arrives at the laundromat, Matt places the load in the washing machine
1. $W_i$ minutes later, he removes the load from the washing machine, placing it in a temporary holding basket (which has unlimited space)
1. A non-negative amount of time later, he places the load in the dryer
1. $D_i$ minutes later, he removes the load from the dryer

Matt can instantaneously add laundry to or remove laundry from a machine. He can choose to wash and dry any of his loads and they can be washed and dried in any order as long as they each follow the steps above. Help Matt maximize the number of loads he can finish washing and drying in $K$ minutes, and amongst all the ways he could finish that many loads, find the minimum amount of time it will take for all of those loads to be washed and dried.

## Input

In this problem, the sequences $W$ and $D$ are generated using a pseudo-random number generator. The generator first produces two length-$L$ sequences $X$ and $Y$. $X_1$ and $Y_1$ are given, and the remaining terms $X_2...X_L$ and $Y_2...Y_L$ are computed as follows:

$X_i = ( (A_x \times X_{i-1} + B_x) \mod C_x) + 1$  
$Y_i = ( (A_y \times Y_{i-1} + B_y) \mod C_y) + 1$

After $X$ and $Y$ are generated, $W$ and $D$ are computed as follows:

$W_i = \min \{X_i, Y_i \}$  
$D_i = \max \{X_i, Y_i \}$

Input begins with an integer $T$, the number of times Matt goes to the laundromat.  
For each trip to the laundromat, there is first a line containing the space-separated integers $L$ and $K$,  
then a line containing the space-separated integers $A_x, B_x, C_x,$ and $X_1$,  
then a line containing the space-separated integers $A_y, B_y, C_y,$ and $Y_1$.
