# Problem

Facebook Prime is a top-secret subscription service being developed to disrupt the online shopping space. (Or maybe there's no such service — we're not telling.) A central focus of the service is preventing package theft, something which has become all too common in today's delivery-driven world. As a member of its engineering team, you wish to model some worst-case scenarios to stress test the vulnerability of poorly-run mailrooms.

In the very worst cases, mailroom managers will actually leave mailbox keys inside mailboxes themselves. This means that if one mailbox were to be broken into, a series of other mailboxes could be compromised as well. Suppose a particular mailroom has $N$ mailboxes, each with a corresponding key, and $M$ packages. The $i$-th mailbox has a capacity of $S_i$​, meaning that it can store a set of objects (packages or keys) as long as the sum of their sizes doesn't exceed $S_i$​. The size of the $i$-th package is $P_i$​, and the size of each key is $X$.

For the purposes of our model, a valid mailroom arrangement must satisfy all of the following conditions:

1. Each package is either inside a mailbox, or is entirely absent.
1. Each key is either inside a mailbox (possibly its own corresponding mailbox), or is entirely absent.
1. Each mailbox contains at most 1 package.
1. No mailbox's capacity is exceeded.

Suppose a thief enters a validly arranged mailroom and forcibly breaks into just one mailbox (without needing a key). If the mailbox contains a package, then they'll obtain it; if the mailbox contains any keys, the thief can then proceed to open each of those keys' corresponding mailboxes and repeat the process (gaining access to any packages and keys they contain, and so on).

Given the specifications of a mailroom, you wish to determine, among all possible valid arrangements, the largest number of packages that may be obtained after a thief forcibly breaks into a single mailbox.

In order to reduce the size of the input, the above values will not all be provided explicitly. Instead, you'll be given the first $K$ values $S_{1..K}$​ and $P_{1..K}$​, as well as the two quadruples of constants $(A_S,B_S,C_S,D_S)$ and $(A_P,B_P,C_P,D_P)$, and must then compute $S_{(K+1)..N}$​ and $P_{(K+1)..M}$​ as follows:

$S_i=((A_S∗S_{i−2}+B_S∗S_{i−1}+C_S) \mod D_S)+1$ for $i>K$  
$P_i=((A_P∗P_{i−2}+B_P∗P_{i−1}+C_P) \mod D_P)+1$ for $i>K$

## Input

Input begins with an integer $T$, the number of mailrooms to be modeled.  
For each mailroom, there are 5 lines:  
The first line contains the 4 space-separated integers $N, M, K,$ and $X$.  
The second line contains the $K$ space-separated integers $S_{1..K}$​.  
The third line contains the 4 space-separated integers $A_S​, B_S​, C_S​,$ and $D_S$​.
The fourth line contains the $K$ space-separated integers $P_{1..K}$​.
The fifth line contains the 4 space-separated integers $A_P​, B_P​, C_P​,$ and $D_P$​.
