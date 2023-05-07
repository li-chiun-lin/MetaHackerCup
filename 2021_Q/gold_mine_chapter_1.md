# Problem

Just like logging, mining is a key industry in Canada's primary sector. Prospectors use geological tools to find ore deposits, then drill, and blast to excavate a system of underground tunnels for access to the ores.

Minerva is a contract miner who spends her days extracting gold ore from underground mines across Ontario. One particular gold mine she's contracting for consists of ___N___ underground caves, numbered from __1__ to ___N___, with cave __1__ having an exit to the surface. There are also ___N___ __- 1__ tunnels running among the caves, the _i_-th of which allows one to travel in either direction between caves ___A<sub>i</sub>___ and ___B<sub>i</sub>___. Each cave is reachable from cave __1__ by a sequence of these tunnels.

Cave _i_ is known to contain ___C<sub>i</sub>___ ounces of gold ore. With her trusty dump truck, Minerva plans to drive underground starting in cave __1__, collect as much gold ore as possible, and exit back to the surface through cave __1__.

There's just one issue: the tunnels are highly unstable, and will cave in after Minerva drives through them. Therefore, she is only able to traverse each tunnel at most once. Fortunately, the caves themselves are reinforced with pillars and will never collapse — she may visit each cave any number of times (though she can only collect its gold ore at most once).

This safety measure may limit mobility. Thankfully, Minerva's truck is also equipped to be a drill rig. As she travels through the system of caves, she may at any point use it to travel from her current cave to any other cave by drilling a new tunnel. In this chapter, the rig only has the energy to drill at most one such tunnel. Unfortunately, this new tunnel will be just as unstable as the existing ones — Minerva will only dare travel through it once.

Please help Minerva determine the maximum weight of gold ore that can be collected if she begins in cave __1__, spends any amount of time exploring the mine (traveling through tunnels, drilling at most one new tunnel, and collecting ore from any visited caves), and end up once again in cave __1__.

## Sample input

```text
5
2
10 20
1 2
4
1 1 1 1
2 1
4 2
1 3
4
1 1 1 1
2 1
4 1
1 3
6
5 4 1 3 2 4
5 1
5 4
5 3
5 2
6 3
9
2 14 7 6 11 3 6 1 8
4 5
6 7
8 9
1 3
6 8
2 4
4 1
1 8
```

## Sample output

```text
Case #1: 30
Case #2: 4
Case #3: 3
Case #4: 12
Case #5: 32
```
