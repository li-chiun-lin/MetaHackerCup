# Problem

Melody is visiting the renowned Notre-Dame Basilica church in Montréal, Canada. Aside from appreciating its beautiful architecture, she's there to see a spectacular light show scheduled to be held within!

Representing the cross-sectional view of the church as a 2D plane, it has a mirror-covered ceiling made up of two 45-degree line segments, the first running from $(0, 0)$ to $(H, H)$ and the second running from $(H, H)$ to $(2H, 0)$.

$N$ lasers have been set up on the floor, pointing upwards, with the $i$-th one at integral coordinates $(X_i, 0)$ emitting a coloured beam of either red (if $C_i = 1$) or blue (if $C_i = 2$) light. All $N$ lasers are at distinct positions, and there's no laser directly under the center of the ceiling (at x-coordinate $H$). If uninterrupted, each laser's beam travels vertically upwards until it hits a point on the ceiling, at which point it bounces to travel horizontally until it hits another point on the ceiling, at which point it bounces to travel vertically downwards and eventually hits another point on the floor. No laser has been set up such that its beam can possibly end up directly hitting another laser at the end of its path. In other words, if there's a laser at coordinates $(x, 0)$, there's guaranteed to be no laser at coordinates $(2H - x, 0)$.

Melody thinks it looks pretty when laser beams interact with one another, but not when red and blue beams clash, so she's going to take matters into her own hands to optimize the show's appearance. She will use drones to suspend $0$ or more blockers in the air within the church, each occupying a single point (possibly with non-integral coordinates) strictly above the x-axis and strictly underneath the ceiling. Each laser beam stops traveling as soon as it hits a blocker.

Let $I(i, j)$ be $true$ if lasers $i$ and $j$ intersect (in other words, if there exists at least one point which both of their beams pass through). If two laser beams hit the same blocker, they are not considered to intersect at that blocker's coordinates. The quality $Q$ of a light show, in Melody's eyes, is the number of unordered pairs of laser beams $(i, j)$ for which $I(i, j)$ is $true$ and $C_i = C_j$. However, if there is any intersecting pair of differently-coloured laser beams (i.e. there exists some pair of beams $(i, j)$ for which $I(i, j)$ is $true$ and $C_i ≠ C_j$), then the quality of the light show is instead $0$.

## Input

Input begins with an integer $T$, the number of light shows that Melody watches.  
For each show, there is first a line containing the space-separated integers $H$ and $N$.  
Then, $N$ lines follow, the $i$-th of which contains the space-separated integers $X_i$ and $C_i$.
