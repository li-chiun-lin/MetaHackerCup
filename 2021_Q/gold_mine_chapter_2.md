# Problem

Just like logging, mining is a key industry in Canada's primary sector. Prospectors use geological tools to find ore deposits, then drill, and blast to excavate a system of underground tunnels for access to the ores.

Minerva is a contract miner who spends her days extracting gold ore from underground mines across Ontario. One particular gold mine she's contracting for consists of $N$ underground caves, numbered from $1$ to $N$, with cave $1$ having an exit to the surface. There are also $N - 1$ tunnels running among the caves, the $i$-th of which allows one to travel in either direction between caves $A_i$ and $B_i$. Each cave is reachable from cave $1$ by a sequence of these tunnels.

Cave $i$ is known to contain $C_i$ ounces of gold ore. With her trusty dump truck, Minerva plans to drive underground starting in cave $1$, collect as much gold ore as possible, and exit back to the surface through cave $1$.

There's just one issue: the tunnels are highly unstable, and will cave in after Minerva drives through them. Therefore, she is only able to traverse each tunnel at most once. Fortunately, the caves themselves are reinforced with pillars and will never collapse — she may visit each cave any number of times (though she can only collect its gold ore at most once).

This safety measure may limit mobility. Thankfully, Minerva's truck is also equipped to be a drill rig. As she travels through the system of caves, she may at any point use it to travel from her current cave to any other cave by drilling a new tunnel. In this chapter, the rig only has the energy to drill at most $K$ such tunnels. Unfortunately, these new tunnels will be just as unstable as the existing ones — Minerva will only dare travel through each new tunnel once.

Please help Minerva determine the maximum weight of gold ore that can be collected if she begins in cave $1$, spends any amount of time exploring the mine (traveling through tunnels, drilling at most $K$ new tunnels, and collecting ore from any visited caves), and end up once again in cave $1$.

## Input

Input begins with an integer $T$, the number of mines that Minerva is contracted to work.  
For each mine, there is first a line containing the single integer $N$.  
Then, there is a second line containing $N$ space-separated integers, $C_{1..N}$​.  
Then, $N−1$ lines follow, the $i$-th of which contains the space-separated integers $A_i$​ and $B_i$​.
