# Problem

This morning you woke up with an uncontrollable urge to send a text message made up of $K$ distinct words. But, can you believe it? Your new phone just crashed and all of the words are missing from its dictionary! You used to have $N$ words in there, and you certainly don't have time to add all of them back right now.

Your plan is to just choose $K$ of the $N$ possible words, add them to your phone's dictionary, and then text each of them. To text a certain word, you must either type the word itself, or any nonempty prefix of it which is not a prefix of any other word in the dictionary.

What's the minimum number of letters you must type to send your message of $K$ words?

## Input

Input begins with an integer $T$, the number of test cases.  
For each test case, there is first a line containing the space-separated integers $N$ and $K$.  
Then, $N$ lines follow, each containing a word that used to be in your phone's dictionary.
