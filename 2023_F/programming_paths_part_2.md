# Problem

A Drizzle program is a 2D grid of the following four types of cells:

- '@' (start) −− there is exactly one start cell in the entire grid
- '#' (wall)
- '.' (space)
- '*' (instruction)

The program uses two registers $A$ and $B$ (both initially $0$), and executes as follows:

1. Compute the minimum distance from the start to each instruction cell using orthogonal movements, without going outside of the grid or passing through any wall cells. Instruction cells that cannot be reached are ignored.
2. In increasing order, for each unique distance $D$ such that there’s at least one instruction cell that’s at distance $D$ from the start cell:
   1. Count the number of shortest paths, $P$, to all instruction cells of distance $D$.
   2. Look up the instruction corresponding to $(P \mod 2,D \mod 2)$ in the table below and modify one of the registers accordingly.
3. At the end, the value in register $A$ is outputted.

```text
┌─────────────┬─────────────┬─────────────┐
│             │ D mod 2 = 0 │ D mod 2 = 1 │
├─────────────┼─────────────┼─────────────┤
│ P mod 2 = 0 │ A := A + 1  │ A := A - 1  │
│ P mod 2 = 1 │ B := B + A  │ A := B      │
└─────────────┴─────────────┴─────────────┘
```

For a given value $K$, output any Drizzle program that outputs $K$ when executed, with the restriction that the program must fit on a $10 × 10$ grid.

## Input

Input begins with an integer $T$, the number of test cases.  
For each case, there is a line containing the single integer $K$.

## Output

For the $i$-th case, output "Case #$i$:" followed by two integers $R$ and $C$, the number of rows and columns in your program, respectively.  
Then output your program. It must be exactly $R$ lines long, with each line containing exactly $C$ characters.
