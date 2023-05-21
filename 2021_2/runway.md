# Problem

TFW it's Toronto Fashion Week. There are $T$ fashion shows to be held, during which runway models will showcase the latest outfits from top designers. Dorothy the dresser has been designated the difficult duty of dressing them all!

A given fashion show features $M$ models wearing a variety of outfits. Each outfit has a style, denoted by a positive integer. Before the show begins, each model $i$ is required to arrive at the venue wearing an outfit of style $S_i$​.

Then, $N$ rounds will follow. A round consists of a lineup of the $M$ models walking the runway in turn, each showcasing an outfit. The ordering of models can differ among different rounds' lineups, but must be some permutation of the same $M$ models each time. The show also has a predetermined program: the $j$-th outfit showcased in the $i$-th round's lineup must be of style $P_{i,j}$​.

Dorothy's job is to dress all of the models backstage, in accordance to the program requirements. A model's outfit may be changed into one of any other style, at any time while the model is not on the runway.

Being resourceful, Dorothy came up with a small trick to make her job less hectic: She can instruct each model to wear another outfit underneath the initial outfit they arrive in, making it easy for the model to change into a different style, just once, without Dorothy's help. In other words, if a model needs to change $n$ different times throughout the entire show, then Dorothy will only need to personally change the model $max(n−1,0)$ times.

Now, Dorothy would like to organize models for each round to minimize her own work. Can you help determine the minimum total number of times that Dorothy will need to personally change a model, while satisfying the program requirements for all $N$ rounds?

## Input

Input begins with an integer $T$, the number of fashion shows.  
For each show, there is first a line containing the space-separated integers $N$ and $M$.  
Then, there is a line containing $M$ space-separated integers, $S_{1..M}$​.  
Then, $N$ lines follow, the $i$-th of which contains $M$ space-separated integers, $P_{i,1..M}$​.
