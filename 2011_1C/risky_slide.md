# Problem

Being a confident and accomplished programmer, you are naturally widely considered to be one of the preeminent dancers of your generation. Unfortunately this means your dancing is under considerable public scrutiny, and your critics are often quick to point out when your moves seem to be getting stale. To prevent such a debacle, you are working on a new maneuver you're calling "the risky slide".

You haven't worked out some of the details like flourishes or vocalizations that will accompany the risky slide, but you do know that the core of the move is a standing slide across a stretch of dance floor. You need to perfect the execution of your slide, so you are looking for the ideal spot in your apartment to practice.

You live a fairly ascetic lifestyle, so your apartment is a simple rectangle with a tiled floor and no furniture or contents of any kind. You will practice the risky slide by starting out standing at the edge of some tile and running parallel to one of the walls of the apartment, and at the transition between some pair of tiles you will go from running to sliding. Your goal is to achieve the longest possible slide, with distance measured as the number of tiles you completely traverse during the slide (partial traversal doesn't count).

This would be an easy problem, but the style of the tiles in your apartment introduces a complication. Each tile has a particular stickiness that affects both how well you can run and how well you can slide on it. Each tile has a stickiness rating between $1$ and $9$, inclusive. The stickiness affects your movement as follows:

- Running across a tile with stickiness $s$ grants $s$ units of kinetic energy. For example, a tile with stickiness $9$ is not slippery at all and you can run across it very efficiently, whereas a tile with stickiness $1$ is quite slippery and does not help you increase your kinetic energy much as you run across it.
- Sliding across a tile with stickiness $s$ robs you of $s$ units of kinetic energy. If a tile would reduce your kinetic energy below $0$, you stop sliding somewhere in the middle of the tile and fail to traverse it completely.

## Input

Your input will consist of a single integer $N$ followed by a newline and $N$ test cases.  
Each case begins with a line containing integers $R$ and $C$, the number of rows and columns, respectively, of tiles in your apartment.  
This will be followed by $R$ lines, each containing a string of length $C$, describing the layout of the tiles in your apartment.  
The value of each element in these strings is the stickiness as defined above of the corresponding tile.
