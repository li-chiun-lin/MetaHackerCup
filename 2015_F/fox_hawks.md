# Problem

Mr. Fox always puts aside some time on the weekends to practice his falconry. Mr. Fox owns $N$ hawks, numbered from $1$ to $N$. While numbering is somewhat impersonal, it quickly becomes infeasible to name each hawk individually when you have as many hawks as Mr. Fox.

Every year, the local falconer club hosts a festival for falconers from across the nation. Mr. Fox shows off some of his hawks at each festival, and this year is no different. Selecting a set of hawks to display is not a straightforward task however. Hawks can be temperamental creatures, and they'll refuse to perform if they don't like the situation they find themselves in. Luckily, after careful study, Mr. Fox has been able to capture the hawks' preferences in a simple boolean expression.

For example, let's say Mr. Fox has $4$ hawks. Hawk $1$ will only perform if some other hawk is present. Hawks $2$ and $3$ will only perform if hawks $1$ or $4$ are present. Hawk $4$ is much more easy-going and will perform in all situations. We can express these preferences with the following expression:

$((1 \& (2 | 3)) | 4)$

Each number is a boolean variable indicating whether or not Mr. Fox brings that hawk. If the expression is satisfied, then all of the hawks he brings will perform. If the expression is not satisfied, the hawks will be moody and that means no blue ribbons for Mr. Fox.

Mr. Fox is keen not to bore his audience, so he always brings a different set of hawks each year. This is the $K$-th annual festival, so he would like to bring the set of performing hawks with the $K$-th lowest value. Mr. Fox defines the value of a set of hawks as follows: the empty set has a value of $0$, and hawk $i$ adds $2^i$ to the value of a set. So with $3$ hawks, the sets in increasing order are:

$
\{1\}     \\
\{2\}     \\
\{1, 2\}  \\
\{3\}     \\
\{1, 3\}  \\
\{2, 3\}  \\
\{1, 2, 3\}
$

Note that Mr. Fox always brings a non-empty set of hawks.

## Input

Input begins with an integer $T$, the number of festivals under consideration.  
For each festival, there is first a line containing the space-separated integers $N$ and $K$.  
The next line contains the boolean expression encoding the hawks' preferences.
