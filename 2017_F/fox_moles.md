# Problem

It's dinner time! A group of $N$ Foxen are standing silently in a field, which can be represented as an infinite number line, patiently waiting for their meals to make an appearance. The $i$-th Fox is standing at position $P_i$, with no two Foxen standing at the same position. There's also one hole in the ground at each integral position on the number line. Each of these holes is the entrance to a mole's den, and the Foxen know that some of these delicious critters are bound to show up sooner or later!

A little-known fact about Foxen is that, in addition to having an acute array of regular senses, they possess a SONAR-like ability to emit imperceptible sound waves and use them to discern objects at great distances. The $i$-th Fox has tuned their wavelength to a distance of $R_i$, allowing them to only detect moles which emerge from holes at a distance of exactly $R_i$ away from them (that is, at either position $P_i - R_i$ or $P_i + R_i$).

All of a sudden, some number of moles have just popped up from various holes all at once! No mole popped up at any Fox's position, no two moles popped up from the same hole, and every mole was detected by at least one Fox. Furthermore, each Fox $i$ has determined that there's exactly $1$ mole at a distance of $R_i$ away from it (as opposed to there being either $0$ or $2$ such moles).

Following this initial event, there's been quite some commotion. Some moles may have retreated back underground, and some new moles may have emerged, all in any order. At every point in time, the set of moles on the surface is subject to all of the same restrictions as before, with one difference: Each Fox $i$ continues to be sure that at least 1 mole is still present at a distance of $R_i$ away from it, but can no longer determine whether or not there are perhaps now 2 such moles instead.

After some time of this, the Foxen have decided that they're ready to pounce and "invite" some of the moles currently on the surface over for dinner. Unfortunately, they've started to become rather overwhelmed with trying to keep track of which moles may be on the surface, or even roughly how many of them there might be. Assuming that the Foxen's initial observations were correct, and that some unknown amount of time has since gone by with moles surfacing or departing, please help the Foxen determine the number of different quantities of moles which could possibly have ended up on the surface.

If it's impossible for their set of initial observations to have been accurate in the first place, output $-1$ instead.

## Input

Input begins with an integer $T$, the number of different fields.  
For each field, there is first a line containing the integer $N$.  
Then $N$ lines follow, the $i$-th of which contains the space-separated integers $P_i$ and $R_i$.
