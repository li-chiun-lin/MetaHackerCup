# Problem

You have a list of $N$ distinct words, consisting of only lowercase letters. You'd like to print any $K$ words from this list, one per page, in any order.

You will accomplish this using a very basic text editor. It supports 3 types of operations: typing a letter, deleting the previous letter, and printing the current document. Note that it does not allow the cursor to be moved! This means that the first operation may only add a letter to the end of the document, and the second may only delete the last letter (if any). Due to issues with memory leakage, you also need to remember to leave the document completely empty after you've printed your $K$ words!

What's the minimum number of operations required to get the job done?

As an example, let's say that you want to print 3 of the following 5 words:

```text
a
hair
box
awesome
hail
```

One optimal sequence of 15 operations is as follows:

- type 'h', 'a', 'i', and 'r' (document = 'hair')
- print
- backspace (document = 'hai')
- type 'l' (document = 'hail')
- print
- backspace 4 times (document = empty)
- type 'a' (document = 'a')
- print
- backspace (document = empty)

## Input

Input begins with an integer $T$, the number of sets of words you want to print.  
For each set, there is first a line containing the space-separated integers $N$ and $K$.  
The next $N$ lines contain the set of words, one per line.
