# Problem

Connie received a string ___S___ for her birthday, consisting entirely of uppercase letters (each between "A" and "Z", inclusive).

However, Connie really only likes nice, consistent strings. She considers a string to be consistent if and only if all of its letters are the same.

Each second, Connie may choose one letter in ___S___ and replace it with a different letter. There are ___K___ different types of replacements she may make, with the iiith one involving choosing letter ___A<sub>i</sub>___ anywhere in ___S___ and replacing it with letter ___B<sub>i</sub>___ ​. No type of replacement (ordered pair of ___A<sub>i</sub>___ ​and ___B<sub>i</sub>___) is given twice. There is no limit on how many times she may end up using each type of replacement. If a letter appears multiple times in ___S___, she may only replace a single occurrence per second.

Help her determine the minimum number of seconds required to change ___S___ into any consistent string, if possible. If it's impossible to ever do so, output -1 instead. Note that ___S___ might already be consistent, in which case 0 seconds would be required.

## Sample input

```text
7
ABC
2
BA
CA
ABC
2
AB
AC
F
0
BANANA
4
AB
AN
BA
NA
FBHC
4
FB
BF
HC
CH
FOXEN
8
NI
OE
NX
EW
OI
FE
FN
XW
CONSISTENCY
26
AB
BC
CD
DE
EF
FG
GH
HI
IJ
JK
KL
LM
MN
NO
OP
PQ
QR
RS
ST
TU
UV
VW
WX
XY
YZ
ZA
```

## Sample output

```text
Case #1: 2
Case #2: -1
Case #3: 0
Case #4: 3
Case #5: -1
Case #6: 8
Case #7: 100
```
