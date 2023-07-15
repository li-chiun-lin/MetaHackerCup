# Problem

It's time for your school class to elect its class officers for the year. These officers will have the honour of representing the class and will hold various responsibilities. The position of class treasurer is particularly appealing to some of the more organized and mathematically-inclined students, especially two rivals, Amy and Betty. They've both been running strong campaigns, to the point that no other feasible candidates remain.

A democratic vote to elect the class treasurer is about to take place! Each of the $N$ students in the class will cast one vote, for either Amy or Betty. The students have IDs numbered from $1$ to $N$, and student $i$ is currently planning on voting for either Amy (if $V_i$ = "A") or Betty (if $V_i$ = "B").

Your teacher, Mr. X, has some "novel" ideas about how elections should work. Perhaps in an effort to teach your class a statistics lesson, he will organize the election as follows. He'll consider the set of all $N \times (N+1)/2$ possible non-empty contiguous sets of student IDs, and will select one at random. Each set will have an equal chance of being selected. He'll refer to this as the "representative set" of students. He will also announce a threshold of victory, $K$. He'll then tally up the number of votes for Amy and Betty amongst those students — let these vote counts be $a$ and $b$ respectively. If $a > b + K$, then Amy will win. If $b > a + K$, then Betty will win. Otherwise, if $|a - b| ≤ K$, then it will be a draw (neither candidate will win, and the class will be left without a treasurer).

Amy has grown concerned about how the election will turn out, so she's enlisted your help in potentially swaying some of your classmates' opinions. She's tasked you with ensuring that, no matter which representative set gets chosen, Betty cannot possibly win (in other words, either Amy will win or neither candidate will win). To do so, you may pay $0$ or more students to change their vote from their current candidate to the other one. Student $i$ requires $2i$ dollars to be influenced in this fashion. You must finish paying students off before you know what the representative set will be.

What's the minimum possible cost required to guarantee that Betty cannot possibly win and become the class treasurer? As this cost may be large, output it modulo $1,000,000,007$. Note that you must minimize the actual cost, rather than minimizing the resulting value of the cost after it's taken modulo $1,000,000,007$.

## Input

Input begins with an integer $T$, the number of elections. For each election, there are two lines.  
The first line contains the space-separated integers $N$ and $K$.  
The second line contains the $N$ characters $V_1$ through $V_N$.
