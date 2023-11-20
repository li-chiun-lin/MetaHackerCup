# Problem

We are starting preparations for Hacker Cup 2013 really early. Our first step is to prepare billboards to advertise the contest. We have text for hundreds of billboards, but we need your help to design them.

The billboards are of different sizes, but are all rectangular. The billboard widths and heights are all integers. We will supply you with the size in inches and the text we want printed. We want you to tell us how large we can print the text, such that it fits on the billboard without splitting any words across lines. Since this is to attract hackers like yourself, we will use a monospace font, meaning that all characters are of the same width (e.g.. 'l' and 'm' take up the same horizontal space, as do space characters). The characters in our font are of equal width and height, and there will be no additional spacing between adjacent characters or adjacent rows. If you print a word on one line and print the next word on the next line, you do not need to print a space between them.

Let's say we want to print the text "Facebook Hacker Cup 2013" on a 350x100" billboard. If we use a font size of 33" per character, then we can print "Facebook" on the first line, "Hacker Cup" on the second and "2013" on the third. The widest of the three lines is "Hacker Cup", which is 330" wide. There are three lines, so the total height is 99". We cannot go any larger.

## Input

The first line of the input file contains a single integer $T$: the number of test cases. $T$ lines follow, each representing a single test case in the form "$W H S$".  
$W$ and $H$ are the width and height in inches of the available space.  
$S$ is the text to be written.
