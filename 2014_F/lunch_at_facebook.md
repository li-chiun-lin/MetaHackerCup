# Problem

What's the best thing about working at Facebook? It's hard to say, but the free food doesn't hurt. Every day there are long lines for food, and sometimes guests visit the campus, as hungry as everybody else. It pays to be a good host, so sometimes we'll let guests cut ahead in the line. But obviously nobody wants to miss out on delicious Facebook food.

Every day, $N$ Facebook employees are lined up for lunch, and every day $M$ visitors come to the campus looking for food. Each person has an appetite $A_i$, which is a positive integer. Curiously, no two people have the same appetite.

If people with large appetites eat first, there's a concern that the food might run out before the people at the back get to eat, so it's ideal to have people with smaller appetites further ahead in the line. With this in mind, we'd like to squeeze all of the guests into the lunch line as efficiently as possible.

We define the unsuitableness of a line as the number of pairs of people in the line, $P_i$ and $P_j$, such that $P_i$ is ahead of $P_j$ in the line, and $P_i$ has a larger appetite than $P_j$. Your task is to find a way to get all the visitors into the lunch line such that the unsuitableness of the resulting line is minimized. The employees that are standing in line won't change order, but you can put guests in any place you want.

## Input

The first line contains an integer $T$, the number of test cases. Each test case has three lines:  
A line with $N$ and $M$.  
A line with $N$ integers, the appetites of the employees in order, beginning with the first employee.  
A line with $M$ integers, the appetites of the visitors.
