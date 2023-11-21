# Problem

After decades of shadowy demonstrations and delays from the game’s maker, **Chess 2** has finally been released. You waited in line all night to be one of the first to purchase an example of the hot sequel to the classic original, and now you are finally getting a chance to open up your new investment and take a look inside. What you find is slightly puzzling; in addition to the traditional pieces, the game has been expanded to contain a number of pieces that are not actually original.

The best-known piece that has been added to the game is the **nightrider**. The **nightrider** can make any number of **knight** moves in a single direction, i.e., its offset from its initial position will be $2 \times m$ in one dimension and $m$ in the other for some nonzero integer $m$. Like other "sliding" pieces, if one of the **knight** moves would cause it to take another piece it is not able to traverse beyond that point

The **archbishop** is also part of **Chess 2**. The **archbishop** can simply make any move that a **knight** or **bishop** could legally make.

The strangest new piece is the **kraken**. The **kraken** can move to any square on the board, regardless of the position of any other pieces, including its own current position.

You don't feel like reading the manual to learn about how the new pieces fit into the standard chess opening positions, so instead you place some of the pieces randomly on the board. The game you’ve decided to play is simply to count how many pieces on the board are currently being threatened. A piece is threatened if another piece is able to move into its cell and take it (note that if the **kraken** moves into its own cell it does not take itself).

## Input

Your input file will consist of a single integer $N$ followed by $N$ test cases.  
Each case will consist of, all separated by whitespace, an integer $P$ followed by the identities and positions of $P$ Chess 2 pieces.  
Pieces are described by a single character $C$ to denote their type (see specification below) followed by two integers $R$ and $F$, the 1-based rank and file, respectively, of the piece.

You've decided to ignore the colors of the pieces in this game. The color of the pieces will not be reflected in the input and so cannot affect your output.

To make room for the new pieces, the Chess 2 board is a $16 \times 16$ grid. No specified pieces will fall outside the board, and no two pieces will occupy the same position.

The types of pieces will be specified as follows, and no entries not present in this table will appear on the board:

|Piece |  Abbreviation  |
|--|--|
|King |K|
|Queen |Q|
|Rook |R|
|Bishop |B|
|Knight |N|
|Nightrider |S|
|Archbishop |A|
|Kraken |E|
