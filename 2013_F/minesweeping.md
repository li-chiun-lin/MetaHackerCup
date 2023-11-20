# Problem

Do you know Minesweeper, the famous video game? The player is initially presented with a grid of undifferentiated squares. Some randomly selected squares, unknown to the player, are designated to contain mines. One square can contain at most one mine.

The game is played by revealing squares of the grid, typically by clicking them. After that, a digit is revealed in the square, indicating the number of adjacent squares (under 8-way connectivity, that is, if two squares share either an edge or a corner, they are considered adjacent) that contain mines. If this number is zero then the surrounding squares are automatically also revealed. This process applies recursively and automatically every time a new square with count zero is revealed.

Now, given a Minesweeper situation, you need to check if it is possible that such a situation can occur after exactly 1 click on the grid. Note that the game is designed in such a way, that the first clicked square never contains a mine.

## Input

The first line contains a single integer $T$. Then $T$ test cases follow.  
The first line of each test case contains two integers $n, m$ which indicate the size of the grid.  
$n$ lines follow, each line contains $m$ characters describing the situation of the grid.  
The meaning of the characters are as follows:  
$x$: the square is not revealed after the first click  
$0 - 8$: the number of mines that are adjacent to this square
