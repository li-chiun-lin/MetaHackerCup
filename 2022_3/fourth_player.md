# Problem

Four friends are playing a card game with two teams of two players each. Team $A$ consists of players $A1$ and $A2$ while team $B$ consists of players $B1$ and $B2$.

There is a deck of $N$ cards (where $N$ is always a multiple of $4$), numbered from $1$ to $N$, with all cards visible to all players at all times. First, the cards are dealt out evenly to each player:

- Player $A1$ has cards $A1_1​, \dots, A1_{N/4}$​.
- Player $B1$ has cards $B1_1​, \dots, B1_{N/4}$​.
- Player $A2$ has cards $A2_1​, \dots, A2_{N/4}$​.
- Player $B2$ has cards $B2_1​, \dots, B2_{N/4}$​.

The game proceeds for $N/4$ rounds. In each round, each player plays a card. Player $A1$ plays first, then player $B1$, then player $A2$, then player $B2$. A player may choose to play any of their cards when it’s their turn. After all four players have played a card, the team who played the highest card will score $1$ point. Once a round is complete, the four played cards are removed from the game, and then the next round starts. This continues until all cards have been played.

Assuming each team plays to maximize its score, how many points will team $A$ score?
