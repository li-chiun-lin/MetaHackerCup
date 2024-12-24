# Problem

As the organizer of Meta Snacker Cup, you've built a fleet of robot servers to collect snack orders from the kitchen, which is represented as a two-dimensional grid $G$ with $R$ rows and $C$ columns. The top-left cell is denoted $(1,1)$ and the bottom-right is $(R,C)$. Each cell $(r,c)$ has a Latin letter $G_{r,c}$​ denoting the type of snack to be collected there. Some letters are capitalized, indicating that an active robot initially occupies that cell.

Every second, each active robot either deactivates itself, moves right, or moves down. That is, an active robot at $(r,c)$ can move to either $(r+1,c)$ or $(r,c+1)$. At the end of each second, no cell may be occupied by more than one active robot. If a robot cannot (or chooses not to) make a valid move, then it becomes deactivated and can never become active again.

Each robot has a tray on which snacks are stacked as the robot moves. At any time, robot $i$'s tray is expressed as a string $S_i$​, initially consisting of only the letter in its starting cell. When robot $i$ visits cell $(r,c)$, it appends the lower-case version of $G_{r,c}$​ to the end of $S_i$​.

For a given sequence of valid moves, let $\min⁡(S_i)$ be the lexicographically minimum value across all final strings $S_i$​. Of all possible valid ways the robots can move, what's the lexicographically maximum possible value of $\min⁡(S_i)$?

## Input Format

Input begins with an integer $T$, the number of test cases.
The first line of each case consists of the integers $R$ and $C$.
Then, $R$ lines follow, the $r$-th line containing the string $G_{r,1..C}$​.
