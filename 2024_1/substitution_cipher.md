# Problem

You’ve probably seen the most classic substitution cipher, where 1 = A, 2 = B, and so on. Under this scheme, a string like META would be encoded as 13 5 20 1.
You’ve just received an encoded string of digits, $E$, but unfortunately all of the spaces have been removed and some (possibly 0) of the digits have become corrupted (represented as question marks).
You must first “uncorrupt” the string by replacing each instance of ? with a digit and then splitting the uncorrupted string into a series of numbers that are all between 11 and 2626 inclusive. For example, the string ?35?01 can be uncorrupted to 135201. That uncorrupted string can be split into 13 5 20 1 as above, but also 1 3 5 20 1, which decodes to ACETA. Note that leading zeros are not valid, so 13 5 2 01 is not a valid way to split the uncorrupted string, so this uncorrupted string cannot be decoded into MEBA.
Given a corrupted encoded string, what uncorrupted encoded string has the largest number of possible strings that it could decode into, and how many decoded strings is that?
As there may be multiple uncorrupted encoded strings that share the same maximum answer, output the lexicographically KKth largest among them. Output the number of decoded strings that this uncorrupted encoded string can decode into modulo 998,244,353998,244,353.

## Input Format

Input begins with an integer $T$, the number of test cases.
Each case is a single line that contains the string $E$ followed by the integer $K$.
