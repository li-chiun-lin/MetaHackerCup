# Problem

Dahlia is taking a roadtrip across all of Canada! Along the way, she's spending a night in one of the country's hallmark cities, Toronto.

Toronto's nighttime skyline can be represented as a 2D plane, with the ground forming a horizontal line with y-coordinate 0. There are W building windows, with the ith one at coordinates (XWi, YWi). There are also S visible stars, with the ith one at coordinates (XSi, YSi). It's guaranteed that all W + S of these points are distinct, and that no star is directly below a window (having the same x-coordinate but a smaller y-coordinate).

At night, it's impossible to see any given window unless there's light coming from it. On any given night, each window is independently either lit up or not with equal probability. As such, there are 2W equally-likely subsets of windows which might be visible. Dahlia finds herself looking at Toronto's skyline on one such random night.

Dahlia knows that Toronto consists of 0 or more buildings, each of which covers a rectangular portion of the sky with some bottom-left corner (x1, 0) and some top-right corner (x2, h), for some real values of x1, x2, and h (such that x1 < x2 and h > 0). The buildings might overlap with one another. Based on Dahlia's view of the stars and lit-up windows, she can infer some things about the set of buildings present. In particular, for each lit-up window i, Dahlia realizes that there must be at least one building whose rectangle inclusively covers the point (XWi, YWi). Furthermore, for each star i, Dahlia realizes that there must be no buildings whose rectangles inclusively cover the point (XSi, YSi).

Dahlia is going to assume that Toronto consists of as few buildings as possible which are consistent with her observations on that night. What's the expected number of buildings which she'll assume exist? In order to avoid floating-point arithmetic and large integers, output this expected number multiplied by 2W (which is guaranteed to result in an integer) and then taken modulo 1,000,000,007.

## Input

Input begins with an integer T, the number of skylines. For each skyline, there is first a line containing the space-separated integers W and S. Then, W lines follow, the ith of which contains the space-separated integers XWi and YWi. Then, S lines follow, the ith of which contains the space-separated integers XSi and YSi.
