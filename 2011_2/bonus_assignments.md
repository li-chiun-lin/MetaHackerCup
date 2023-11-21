# Problem

You are in charge of a group of $N$ workers, and you want to pay a one-time bonus to each of them. The bonus for each worker is an integer number of dollars. According to state law the bonus of the worker who gets the least should be no less than $A$, but no more than $B$. To motivate your staff, the bonus of the worker who gets the most should be no less than $C$ and no more than $D$.

Workers tend to spend their entire bonuses on HackerCola. Each of them buys bottles of HackerCola until he runs out of money, i.e., until amount of money left is less than the price of one bottle. Workers are very individualistic and each of them uses his own money only, so they never pool to buy HackerCola. Unfortunately you don't remember the price of one bottle of HackerCola, but you are pretty sure that it is an integer number of dollars greater than $1$.

Since you care about the working class you want to assign bonuses to workers in such a way that there would be at least one worker who would have some money left after buying as much HackerCola as possible regardless of the price of the bottle. Calculate the number of possible bonus assignments that fit this constraint. Two bonus assignments are different if at least one worker gets different bonus in each assignment. Since the answer can be large, calculate it modulo $1,000,000,007$.

## Input

The first line of the input contains one integer $T$, the number of test cases.  
Each of the next $T$ lines consists of 5 integers separated by spaces: $N, A, B, C$ and $D$.
