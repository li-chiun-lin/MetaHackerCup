# Problem

Mr. Fox sure loves his rocks! In fact, when he's not in a hurry, he often looks at the rocks lying around near him to decide where to wander in his forest.

Mr. Fox lives in a forest with N clearings, numbered from 0 to N-1, with P one-way trails initially running amongst them. The ith trail runs from clearing Ai to a different clearing Bi, and is littered with Ri rocks. No two clearings are connected by multiple trails running in the same direction, though they could be connected by 2 trails running in opposite directions. Additionally, an interesting property of this forest is that a trail from clearing a to clearing b may only exist if 0 ≤ floor(b/4) - floor(a/4) ≤ 1.

To entertain himself over a period of D days, Mr. Fox will cause one event to occur on each day. The ith event may be one of 3 types, determined by the value of Ei:

    Given 3 integers Xi, Yi, and Zi, Mr. Fox will create a new trail from clearing Xi to a different clearing Yi, and drop Zi rocks onto it. It's guaranteed that no trail from Xi to Yi will exist at the start of the ith day, and that 0 ≤ floor(Yi/4) - floor(Xi/4) ≤ 1 will hold.

    Given 2 distinct integers Xi and Yi, Mr. Fox will completely destroy the trail from clearing Xi to clearing Yi (which is guaranteed to exist at the start of the ith day). Note that, once such a trail is destroyed, a new trail from Xi to Yi may be created in the future.

    Given 2 distinct integers Xi and Yi, Mr. Fox will take a "random stroll" starting at clearing Xi, and would like to determine the probability that he'll visit clearing Yi at least once during it.

    A "random stroll" consists of repeating the following process potentially infinitely: If Mr. Fox is currently in some clearing c, and there are no outgoing trails from c, then the stroll ends immediately. Otherwise, he'll consider all of the rocks on all of the outgoing trails from c, choose one of these rocks uniformly at random, follow the trail on which that rock lies to its destination clearing (without removing any rocks), and repeat the process from his new clearing.

For each event of type 3, output the requested probability.

## Input

Input begins with an integer T, the number of test cases. For each test case, there is first a line containing the space-separated integers N, P, and D.

Then, P lines follow, the ith of which contains the space-separated integers Ai, Bi, and Ri.

Then, D lines follow, the ith of which contains the space-separated integers Ei, Xi, and Yi. If Ei = 1, this line additionally contains the integer Zi.
