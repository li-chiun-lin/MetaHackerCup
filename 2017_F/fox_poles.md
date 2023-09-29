# Problem

While taking a walk through the woods, a group of Foxen have come upon a curious sight — a row of N wooden poles sticking straight up out of the ground! Who placed them there, and why? The Foxen have no clue.

Looking at the poles from the side, they can be modeled as vertical line segments rising upwards from a number line (which represents the ground), with the $i$-th pole at distinct integral position $P_i$ and having a real-valued height of Hi.

One of the Foxen, Ozy, is fascinated by the shadows being cast on the ground by the poles. The sun is shining down on the poles from some point very high up in the sky, resulting in infinitely many rays of light descending towards the number line at all possible positions along it, but all travelling in some uniform direction. Each ray of light stops travelling as soon as it comes into contact with either a pole or the ground. Any point on the ground which is incapable of being reached by rays of light (because they would get blocked by at least one pole before reaching that point) is considered to be covered in shadows.

The sunlight's direction can be described by a real value a, with absolute value no larger than $80$, where a is the signed angle difference (in degrees) between the rays' direction and a vector pointing directly downwards. As an example, let's imagine that there's a single pole at position $50$ and with a height of $100$. If $a = 45$, then sunlight is shining diagonally down and to the right, meaning that the pole obstructs rays of light from being able to reach any points on the ground in the interval $[50, 150]$, effectively casting a shadow with length $100$ to the right. If $a = -45$, then sunlight is shining diagonally down and to the left, causing the pole to cast a shadow with $100$ to the left instead (over the interval $[-50, 50]$). If $a = 0$, then sunlight is shining directly downwards onto the ground, resulting in the pole not casting any shadow.

Ozy is planning on returning by himself tomorrow in order to observe the poles again, but he doesn't know at what time of day he'll be able to make the trip. He does at least have it narrowed down to being within some interval of time, during which he knows that the sunlight's direction a will range from $A$ and $B$, inclusive. Given that the sunlight's direction a will be a real number drawn uniformly at random from the interval $[A, B]$ when Ozy visits the poles tomorrow, please help him predict the expected total length of ground which will be covered in shadows at that time.

## Input

Input begins with an integer $T$, the number of different sets of poles.  
For each set of poles, there is first a line containing the space-separated integers $N$, $A$, and $B$.  
Then $N$ lines follow, the $i$-th of which contains the integer $P_i$ and the real number $H_i$ separated by a space. The poles' heights are given with at most 4 digits after the decimal point.
