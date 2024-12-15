# Problem

Connie and Forrest are playing Connect Four for bunnies by making burrows on a grid of $42$ plots of land with $6$ rows and $7$ columns. Connie goes first, and the two of them alternate turns.

On Connie's turn, she selects a column and makes a burrow in that column's southernmost unburrowed plot, marking it as her own. Forrest then does the same thing, making a burrow in the southernmost unburrowed plot in some column. Once all $6$ plots in a column have been burrowed, players can no longer choose that column.

Normally, the game ends as soon as one player has four consecutive burrows in a line (horizontally, vertically, or diagonally). That player is then declared the winner. However, the bunnies had so much fun burrowing that they didn't stop taking turns until every plot was burrowed. They’re now trying to work out who won.

Given the final $6×7$ grid of 'C' and 'F' markings (denoting plots burrowed by Connie and Forrest respectively), can you tell who must have won first?

Please output:

- C: if Connie must have won first
- F: if Forrest must have won first
- ?: if somebody has won, but it's impossible to tell who won first
- 0: if nobody has won

## Input Format

Input begins with an integer $T$, the number of test cases.
Each case starts with an empty line for readability, and then $6$ rows of $7$ characters each, representing the final state of the game. The bottom row is the southern-most row.
