# Number Generator

Solution to a programming challenge to check collisions between two random number generators, written in C++ using 32-bit integers and avoiding division. 

Use `-std=c++11` to compile.


## The Problem

In front of you are a pair of generators, generator A and generator B, that
produce an infinite sequence of numbers.
The generators both work on the same principle. To create its next value, a
generator will take the previous value it produced, multiply it by a factor
(generator A uses 16807; generator B uses 48271), and then keep the remainder
of dividing that resulting product by 2147483647. That final remainder is the
value it produces next.
To calculate each generator's first value, it instead uses a specific starting
value as its "previous value."
For example, suppose that for starting values, generator A uses 65, while
generator B uses 8921. Then, the first five pairs of generated values are:
```
--Gen. A-- --Gen. B--
1092455 430625591
1181022009 1233683848
245556042 1431495498
1744312007 137874439
1352636452 285222916
```
Your task is to count the number of pairs that "match" among the first 40
million pairs. A pair is said to match if the least significant 16 bits of
both values match.
For example, the pairs above in binary are (with generator A's value first in
each pair):
```
00000000000100001010101101100111
00011001101010101101001100110111
01000110011001001111011100111001
01001001100010001000010110001000
00001110101000101110001101001010
01010101010100101110001101001010
01100111111110000001011011000111
00001000001101111100110000000111
01010000100111111001100000100100
00010001000000000010100000000100
```
Here, you can see that the least significant (here, rightmost) 16 bits of the
third value match: `1110001101001010`. None of the other pairs match, so after
processing these five pairs, your count would be `1`.
After processing the full set of 40 million pairs using the starting values of
65 and 8921, your count would be `588`.
Write a program that prints the number of matching pairs among the first 40
million pairs, for arbitrary starting values.

