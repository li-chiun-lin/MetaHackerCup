# Problem

A group of $N$ high school students wants to play a basketball game. To divide themselves into two teams they first rank all the players in the following way:

- Players with a higher shot percentage are rated higher than players with a lower shot percentage.
- If two players have the same shot percentage, the taller player is rated higher.

Luckily there are no two players with both the same shot percentage and height so they are able to order themselves in an unambiguous way. Based on that ordering each player is assigned a draft number from the range $[1..N]$, where the highest-rated player gets the number $1$, the second highest-rated gets the number $2$, and so on. Now the first team contains all the players with the odd draft numbers and the second team all the players with the even draft numbers.

Each team can only have $P$ players playing at a time, so to ensure that everyone gets similar time on the court both teams will rotate their players according to the following algorithm:

- Each team starts the game with the $P$ players who have the lowest draft numbers.
- If there are more than $P$ players on a team after each minute of the game the player with the highest total time played leaves the playing field. Ties are broken by the player with the higher draft number leaving first.
- To replace her the player on the bench with the lowest total time played joins the game. Ties are broken by the player with the lower draft number entering first.

The game has been going on for $M$ minutes now. Your task is to print out the names of all the players currently on the field, (that is after $M$ rotations).

## Input

The first line of the input consists of a single number $T$, the number of test cases.  
Each test case starts with a line containing three space separated integers $N$ $M$ $P$  
The subsequent $N$ lines are in the format "\<name\> \<shot_percentage\> \<height\>".
