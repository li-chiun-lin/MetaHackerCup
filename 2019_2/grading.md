# Problem

Due to a convenient recent teaching vacancy, Laz Y. has suddenly landed a job as a schoolteacher. Known to his students as Mr. Y, he's prepared to provide a comprehensive, fairly-evaluated educational experience — as long as it doesn't take too much effort.

Mr. Y's first order of business in his new role will be grading recent exams from two different subjects: art and biology. He has been handed $S$ stacks of $H$ exam papers each. The $i$-th paper from the top in the $j$-th stack is either from the art exam (if $P_{i,j} =$ "A"), or otherwise from the biology exam (if $P_{i,j} =$ "B").

Mr. Y will go about the grading process as follows: At each point in time, he'll select a stack which still contains at least one exam paper, and remove its topmost paper. He'll then either grade that paper, or accidentally "lose" it and assign its owner a random grade instead. Either way, once he's done with that paper, he'll repeat the process of selecting a new paper until all of the stacks are empty and all $H \times S$ papers have been dealt with.

There are few things that Mr. Y hates as much as context switching. For example, it's very troublesome to jump from grading an art exam to a biology one! (Or from relaxing to doing any work at all.) Each time Mr. Y begins a grading a paper, he must make a context switch if this is either the first paper he's choosing to grade, or if its subject is different than that of the previous paper that he graded. Note that this entirely excludes any "lost" papers.

Mr. Y is no fool — he realizes that his evaluations would be too suspiciously inaccurate if he were to simply lose all $H \times S$ papers. Even losing a smaller number of them may prove too suspicious. Therefore, he'll imagine $K$ different theoretical scenarios, such that in the $i$-th one, he will allow himself to lose at most $L_i$ papers throughout the grading process (with $L_{1..K}$ all being distinct). Independently for each scenario, he'd like to determine the minimum number of context switches he would need to make throughout the process.

## Input

Input begins with an integer $T$, the number of days Mr. Y spends grading exams.  
For each day, there is first a line containing the space-separated integers $H$, $S$, and $K$.  
Then, $H$ lines follow, the $i$-th of which contains the length-$S$ string $P_{i,1..S}$.  
Then, a final line follows containing the $K$ space-separated integers $L_1$ through $L_K$.
