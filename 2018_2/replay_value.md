# Problem

Allison has just developed the latest addictive mobile game: Super Path Drawer: Extreme Edition!

This game takes place on an infinite 2D plane (thanks to advancements in graphical technology, the entire plane can fit onto a mobile phone screen). Two distinct points on the plane are chosen: a starting point (at coordinates $(0, S)$), and an ending point (at coordinates $(1,000,000,000, E)$). The player's goal is to draw a path from the starting point to the ending point. The path may be any continuous curve on the plane (not necessarily a straight line segment), and may cross itself. If the player successfully draws such a path, they're rewarded with a "point", thus convincing them that their time is being put to good use. If they fail to draw such a path, they're instead forced to watch an ad, thus motivating them to do better on their next attempt.

By itself, this game is certainly addicting, but it doesn't seem to cause players to watch enough ads! So, as a last-minute addition, Allison has inserted some lasers. There are $N$ laser emitters, the $i$-th of which is at $(X_i, Y_i)$. Each emitter will emit a laser beam either directly up, down, left, or right. The laser beam is a ray starting from the emitter's position (inclusive) and continuing infinitely in the selected direction. Naturally, the player's path may not touch any part of any laser beam. All $N+2$ x-coordinates (of the starting point, ending point, and laser emitters) are distinct, and all $N+2$ y-coordinates are also distinct, meaning that it's impossible for a laser beam to ever directly hit the starting point, ending point, or another emitter.

Allison hasn't programmed in the capability for moving laser emitters around, but she can at least cause them to emit their laser beams in different combinations of directions each time a player replays the game. She's concerned that players will get bored as soon as they encounter a laser configuration which they've already seen, so she'll make sure that each player is presented with each of the $4^N$ possible different laser configurations exactly once.

Some laser configurations result in the ending point still being reachable from the starting point by some continuous path which doesn't touch any laser beams, in which case players will surely manage to find such a path. But for other laser configurations, no valid path exists at all, resulting in a forced ad showcase. Allison would like to count the total number of ads which a player will end up watching upon playing the game once for each of the $4^N$ possible different laser configurations. As this value can be large, you only need to compute it modulo $1,000,000,007$.

## Input

Input begins with an integer $T$, the number of sets of lasers.  
For each set of lasers, there is first a line containing the space-separated integers $N$, $S$, and $E$.  
Then, $N$ lines follow. The $i$-th of these contains the space-separated integers $X_i$ and $Y_i$.
