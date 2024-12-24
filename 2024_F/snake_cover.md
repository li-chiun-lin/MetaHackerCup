# Problem

While unloading freshly-picked fruits as a snack for guests, Jessie noticed that a snake snuck into her basket and is now roaming her kitchen, represented as an infinite 2D plane. The snake is made up of $N$ connected $1×1$ cells numbered $1..N$. At any time, the snake's head (cell $1$) faces either north, east, south, or west. Initially, the cells of the snake are horizontal with the head facing east.
The snake makes $M$ moves. Move $i$ is given by a pair $D_i$​ $X_i$​ denoting a turn followed by a slither:

1. First, the snake turns its head left or right by $90°$ (if $D_i=$ 'L' or 'R'). If $D_i=$ 'S', then the snake continues straight in its current direction. In all cases, this step takes $0$ seconds.
1. Then, the snake shifts its head forward by $X_i$​ units in its current direction, taking $X_i$​ seconds ($1$ second per unit moved). For each unit shifted by the head, every cell $i>1$ also shifts to the position that cell $i−1$ was previously at.

Different from the classic video game, it's possible for the snake to intersect itself and continue slithering, with multiple cells occupying the same coordinates.

Jessie has rectangular containers of all sizes that can be used to cover and contain the snake, but she would prefer to use the smallest one so the rest can be used to serve fruit.

Let $A(t)$ be the area of the smallest axis-aligned rectangle that completely covers the snake at time $t$, and suppose that move $i$ occurs during the time interval $(t_i,t_{i+X_i}]$. Jessie is interested in the function

$f(i)=\min⁡(A(t_i+1),A(t_i+2),…A(t_i+X_i))$

denoting the minimum rectangle area to cover the snake after each second of the $i$-th slither.

Please determine the value of $(f(1)+f(2)+…+f(M))$ modulo $1,000,000,007$.

## Input Format

Input begins with an integer $T$, the number of test cases.
The first line of each case consists of two integers $N$ and $M$.
Then, $M$ lines follow, the $i$-th of which consists of letter $D_i$​ and integer $X_i$​.
