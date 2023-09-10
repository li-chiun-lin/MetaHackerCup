# Problem

Some pies are sweet, full of fruit and jam and sugar.

Some pies are savory, full of meat and potatoes and spices.

Some pies are in fact not pies at all but tarts or galettes. This probably won't stop you from eating them.

Every single day for $N$ days, you're determined to eat a pie for dinner. Every morning, you'll take a trip to your local pie shop, and buy 0 or more of their pies. Every night, you'll eat one pie that you've bought. Pies never go bad, so you don't need to eat a pie on the same day that you bought it. You may instead eat one that you purchased on an earlier day.

On the $i$-th day, the shop has $M$ pies for sale, with the $j$-th of these pies costing $C_{i,j}$ dollars. You can choose to buy any (possibly empty) subset of them. However, this shop has measures in place to protect itself against crazy pie fanatics buying out its products too quickly. In particular, if you buy $p$ pies on a single day, you must pay an additional tax of $p^2$ dollars.

## Input

Input begins with an integer $T$, the number of times you go on a pie-eating spree.  
For each case, there is first a line containing two space-separated integers, $N$ and $M$.  
Then, $N$ lines follow, each containing $M$ space-separated integers. The $j$-th integer on the $i$-th line is $C_{i,j}$.
