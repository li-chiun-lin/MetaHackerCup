# Problem

Carlos has been working in technology so long that he's starting to feel a bit burnt out. Hoping to rejuvenate himself, Carlos has been seeking out more artistic opportunities.

Yamaha, the well-known creator of musical apparatus, has approached Carlos with a request that might be right up his alley: they'd like him to design a brand new instrument. Immediately, Carlos knows what to do.

"You may have seen Pat Metheny's 42-string guitar, but that's nothing compared to what we're going to make together."

Carlos presents his plan for a 1,000-string guitar, complete with programmatic tuning so that you don't need to turn 1,000 knobs by hand. Yamaha's market research suggests that these sorts of guitars would be great for playing palindromic chords, chords where the first string plays the same note as the last string, the second string plays the same note as the second-to-last string, and so on. Carlos is quickly tasked with developing default tunings for the strings so that the guitars are ready to play right out of the box.

For various integers $K$, Carlos wants to find a set of at most 1,000 strings on which exactly $K$ distinct palindromic chords can be played. The guitar's strings are arranged in a line, and each one must be tuned to a note from the set {A, B, C, D, E, F, G}. A chord is then played by strumming a contiguous subset of 1 or more strings. Two chords are considered to be distinct if there is at least one string that is used in one chord but not the other; chords involving the same notes but different strings are considered different.

For example, if K = 9, a set of 7 strings could be tuned to the notes C, A, B, B, A, G, E in order from left to right. You can play 7 different palindromic chords by strumming single strings, the chord BB by strumming the 3rd and 4th strings, and the chord ABBA by strumming the 2nd, 3rd, 4th, and 5th strings. This is a total of 9 distinct palindromic chords.

Output any non-empty string of valid musical notes, with length at most 1,000, representing the tunings of sequential strings. An aspiring musician must be able to play exactly $K$ distinct palindromic chords on these strings. It's guaranteed that there is at least one valid output for each possible valid input.

## Input

Input begins with an integer $T$, the number of tunings that Carlos needs to figure out.  
For each tuning, there is a single line containing the integer $K$.
