# Problem

You just landed a job as a machine learning engineer! As a ramp-up exercise, Boss Rob tasked you with modeling the watering wells in his yard, which can be represented on a Cartesian plane.

Boss Rob has a primary well at point $(A_x,A_y)$ and a backup well at a different point $(B_x,B_y)$, each able to water trees within an $R$ unit radius. Using $A_x$​, $A_y$​, $B_x$​, $B_y$​, and $R$ (unknown integers to you), Rob plants $N$ happy little trees at real number points obtained by $N$ calls to the function:

```python
def gen_one_tree(A_x, A_y, B_x, B_y, R):
    while True:
        r = random.uniform(0, R)
        theta = random.uniform(0, 2*math.pi)
        x = A_x + r*math.cos(theta)
        y = A_y + r*math.sin(theta)
        if (x - B_x)**2 + (y - B_y)**2 <= R*R:
            return (x, y)
```

Here, $random.uniform(L, H)$ returns a real number in $[L,H)$ uniformly at random.

In other words, he picks a point $(x,y)$ in the circular range of the primary well using the special method above. If $(x,y)$ happens to be in range of the backup well, he plants a tree there (else he discards it and tries again with a new $(x,y)$). This repeats until Rob has planted $N$ trees.

Given only the planted tree coordinates $(X_1​,Y_1​),…,(X_N​,Y_N​)$, you are tasked to predict the exact values of $A_x$​, $A_y$​, $B_x$​, $B_y$​, and $R$. As you are new, Boss Rob will accept your solution if it correctly predicts at least $80\%$ of the test cases.

## Input

Input begins with a single integer $T$, the number of test cases.  
For each case, there is first a line containing a single integer $N$, the number of planted trees.  
Then, $N$ lines follow, the $i$-th of which contains two space-separated real numbers $Xi$​ and $Yi$​, each given to 6 decimal places.
