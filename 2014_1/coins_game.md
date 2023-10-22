# Problem

Alice and Bob like to play what they call the "Coins Game". In this game Bob starts with $K$ identical coins and $N$ identical jars. A jar can fit any number of coins and Bob has to distribute all the coins in whatever way he wants.

After the coins are distributed Alice takes the jars and shuffles them at random while Bob isn't looking. Alice will move jars around but will not move any coins between the jars. The jars are opaque so after the shuffle Bob doesn't see how many coins are in each.

Now Bob has $P$ moves. In each move he points at one of the jars. If the jar contains any coins Alice takes a single coin from it and hands it to Bob. If the jar is empty Alice tells Bob. Bob remembers his initial distribution and the moves he has made so far.

The goal of the game is to check whether Bob is able to acquire at least $C$ coins after his $P$ moves. If he can do that he wins the game. After losing the first few games Bob is determined to figure out what's the minimal number of moves $P$ that can guarantee his win. Your job is to help him, that is find the minimal value $P$ for which there exists an initial coins distribution and moves strategy that makes Bob win no matter what order the jars are in.

## Input

The first line of the input consists of a single integer $T$, the number of test cases.  
Each test case is a single line with three integers: $N$ $K$ $C$.
