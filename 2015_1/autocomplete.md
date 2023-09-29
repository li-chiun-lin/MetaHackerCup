# Problem

Since you crave state-of-the-art technology, you've just purchased a phone with a great new feature: autocomplete! Your phone's version of autocomplete has some pros and cons. On the one hand, it's very cautious. It only autocompletes a word when it knows exactly what you're trying to write. On the other hand, you have to teach it every word you want to use.

You have $N$ distinct words that you'd like to send in a text message in order. Before sending each word, you add it to your phone's dictionary. Then, you write the smallest non-empty prefix of the word necessary for your phone to autocomplete the word. This prefix must either be the whole word, or a prefix which is not a prefix of any other word yet in the dictionary.

What's the minimum number of letters you must type to send all N words?

## Input

Input begins with an integer $T$, the number of test cases.  
For each test case, there is first a line containing the integer $N$.  
Then, $N$ lines follow, each containing a word to send in the order you wish to send them.
