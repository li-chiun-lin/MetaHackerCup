# Problem

The residents of Townsville have made it clear to the mayor that they're greatly concerned about gentrification, a process by which wealthy people move into the city in large numbers, displacing the people who currently live there. The mayor of Townsville knows a thing or two about this, and she would like to put the people's minds at ease by determining the worst-case scenario.

Townsville is made up of N neighbourhoods, with M one-way roads running between them. The ith road runs from neighbourhood Ai to neighbourhood Bi. A swarm of rich migrants will move to the city all at once, immediately gentrifying any neighbourhood they decide to move into.

The mayor knows the following facts about these new affluent residents: First, they like to visit other gentrified neighbourhoods. If there's a way of getting from their home neighbourhood to another gentrified neighbourhood, they will surely go visit. Second, they never walk anywhere; they only drive. Consequently, they'll get very angry if they end up in some neighbourhood with no way to drive back home.

Putting these facts together, it means that if rich migrants move into and gentrify any two neighbourhoods u and v, then it must be the case that there is a series of roads connecting u to v if and only if there is a series of roads connecting v to u.

Given this self-imposed constraint, and the layout of the roads in Townsville, what is the maximum number of neighbourhoods that can be gentrified?

## Input

Input begins with an integer T, the number of test cases. For each test case, there is first a line containing the space-separated integers N and M.

Then, M lines follow, the ith of which contains the space-separated integers Ai and Bi.
