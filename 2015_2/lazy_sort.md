# Problem

Much to Mr. Book's amazement, his entire first-grade math class has completed the enormous amount of homework that he assigned only the day before. Being hyperactive little kids, the grade-schoolers have dumped their homework, one page per student, unceremoniously in a pile on Mr. Book's desk.

There are $N$ students in Mr. Book's class, and they each have a distinct integer student ID from $1$ to $N$. Mr. Book wants the homework to be sorted by student ID with the page from student #$1$ at the top, all the way down to the page from student #$N$ at the bottom. As we know, Mr. Book is a lazy fellow. He's not going to put much effort into sorting the pile himself.

As he considers the pile before him, Mr. Book decides that he'll sort the homework as follows: Every time he moves a page, he'll only move it from the original pile to his finished stack, which initially starts empty. Furthermore, he'll only move the top or bottom page of the remaining original pile, and he'll only place it on the top or bottom of his neat destination stack.

Is it possible for Mr. Book to sort the homework with such a method?

## Input

Input begins with an integer $T$, the number of test cases. For each case, there are two lines.  
The first contains the integer $N$.  
The second contains a permutation of the integers from $1$ to $N$. These are the students' IDs in the order their homework appears in the pile, from bottom to top.
