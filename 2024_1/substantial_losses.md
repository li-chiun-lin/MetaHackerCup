# Problem

You currently weigh $W$ units, but you would ideally weigh $G<W$ units. On some days you have the mental fortitude to eat well and exercise. On other days, not so much. Every day, with equal likelihood, your weight will either increase or decrease by $1$ unit.
While your regimen may be lax, you do have one strict rule: if your weight has ever been $w$ units, then you will never in the future allow it to exceed $w+L$. On any day where gaining $1$ unit of weight would violate this constraint, you will guarantee that you lose $1$ unit of weight instead.
On average, how many days will it take you to reach a weight of GG units? The answer can be expressed as the ratio of two integers, $p/q$ in lowest terms. Output $p×q^{−1}$ (mod $998,244,353$).

## Input Format

Input begins with an integer $T$, the number of test cases. Each case is a single line with the integers $W$, $G$, and $L$.
