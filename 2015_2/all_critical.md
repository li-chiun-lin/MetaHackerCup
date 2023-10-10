# Problem

In the game Theatrhythm Final Fantasy, you poke a screen with a stick to the beat of various songs. The goal is to poke the screen as accurately as possible. If you hit a note at just the right time, you're awarded a critical. Every song is broken into 20 sections, and if you get a critical on every note in a section, then you get that section's golden critical bar.

You would like to collect all 20 critical bars for every song. Songs vary in difficulty, but each song has a fixed probability $p$, which is the chance that you manage to secure any one critical bar on a single playthrough. The chances are independent, so for any given pair of sections, the probability of getting both critical bars in a single playthrough is $p^2$, and so on. Critical bars are saved between playthroughs, so you don't have to win all of the critical bars in a single play of the song. You might win the first 10 on one play, and then the last 10 on another.

On average, how many times will you have to play a song to win all 20 critical bars?

## Input

Input begins with an integer $T$, the number of songs you'll play.  
For each song, there is a line containing a floating point number, $p$, the probability of winning any particular critical bar on a single play of the song.
