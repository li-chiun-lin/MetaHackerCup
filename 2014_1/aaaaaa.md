# Problem

Al is the proprietor of Al's Awesome and Amazing Amusement Arcade, called AAAAAA by some, AAaAAA by others, AAAAA by others still, and alternately A$^5$ or A$^6$ by math majors.

The problem with operating such a spectacular business is managing the line of people waiting to get in. City by-laws prevent people from loitering on Al's property, so anybody who wants to experience the wonders Al has in store has to queue in the parking lot. Not wanting to turn people away, Al is interested in cramming as many hapless souls into the parking lot as he can. However, customers are a whiny bunch, and refuse to stand in any queue that makes too many detours before getting to the entrance.

You can imagine that the parking lot is a grid, with the Arcade's entrance in the upper-left corner. All queues must begin here. There may be cars in the parking lot, denoted '#'. Customers refuse to queue on top of cars. All other cells will contain '.'. Due to customer complaints, all queues must generally extend only rightwards and downwards. However, Al's clientele is not entirely unreasonable, so a queue may have a single contiguous section that runs upwards, or a single contiguous section that runs leftwards, but not both. Queues only extend in these four directions (i.e., not diagonally).

There is only room for one customer in each empty space. Each pair of consecutive customers in the queue must stand in adjacent spaces, i.e. there can't be any gaps in the queue.

## Input

The first line of the input consists of a single integer $T$, the number of test cases.  
Each test case begins with a line containing two integers, $N$ and $M$, the number of rows and columns in the lot's grid.  
The next $N$ lines each contain a string with exactly $M$ characters, where the $i$-th line correspond to the $i$-th row in the grid.
