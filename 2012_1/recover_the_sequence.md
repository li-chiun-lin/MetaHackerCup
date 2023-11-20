# Problem

Merge sort is one of the classic sorting algorithms. It divides the input array into two halves, recursively sorts each half, then merges the two sorted halves.

In this problem merge sort is used to sort an array of integers in ascending order. The exact behavior is given by the following pseudo-code:

```text
function merge_sort(arr):
    n = arr.length()
    if n  0 and arr2.length() > 0:
        if arr1[0] < arr2[0]:
            print '1' // for debugging
            result.append(arr1[0])
            arr1.remove_first()
        else:
            print '2' // for debugging
            result.append(arr2[0])
            arr2.remove_first()
            
    result.append(arr1)
    result.append(arr2)
    return result
```

A very important permutation of the integers $1$ through $N$ was lost to a hard drive failure. Luckily, that sequence had been sorted by the above algorithm and the debug sequence of $1s$ and $2s$ was recorded on a different disk. You will be given the length $N$ of the original sequence, and the debug sequence. Recover the original sequence of integers.

## Input

The first line of the input file contains an integer $T$. This is followed by $T$ test cases, each of which has two lines.  
The first line of each test case contains the length of the original sequence, $N$.  
The second line contains a string of $1s$ and $2s$, the debug sequence produced by merge sort while sorting the original sequence. Lines are separated using Unix-style ("\n") line endings.
