# Problem

After decades of shadowy demonstrations and delays from the game’s maker, **Chess 2** has finally been released. You waited in line all night to be one of the first to purchase an example of the hot sequel to the classic original, and now you are finally getting a chance to open up your new investment and take a look inside. What you find is slightly puzzling; in addition to the traditional pieces, the game has been expanded to contain a number of pieces that are not actually original.

The best-known piece that has been added to the game is the **nightrider**. The **nightrider** can make any number of **knight** moves in a single direction, i.e., its offset from its initial position will be $2 \times m$ in one dimension and $m$ in the other for some nonzero integer $m$. Like other "sliding" pieces, if one of the **knight** moves would cause it to take another piece it is not able to traverse beyond that point

The **archbishop** is also part of **Chess 2**. The **archbishop** can simply make any move that a **knight** or **bishop** could legally make.

The strangest new piece is the **kraken**. The **kraken** can move to any square on the board, regardless of the position of any other pieces, including its own current position.

You don't feel like reading the manual to learn about how the new pieces fit into the standard chess opening positions, so instead you place some of the pieces randomly on the board. The game you’ve decided to play is simply to count how many pieces on the board are currently being threatened. A piece is threatened if another piece is able to move into its cell and take it (note that if the **kraken** moves into its own cell it does not take itself).
