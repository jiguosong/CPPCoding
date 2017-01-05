/*
 * pragma.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */




/*

#pragma pack instructs the compiler to pack structure members with particular alignment. Most compilers, when you declare a struct, will insert padding between members to ensure that they are aligned to appropriate addresses in memory (usually a multiple of the type's size). This avoids the performance penalty (or outright error) on some architectures associated with accessing variables that are not aligned properly. For example, given 4-byte integers and the following struct:

struct Test
{
   char AA;
   int BB;
   char CC;
};

The compiler could choose to lay the struct out in memory like this:

|   1   |   2   |   3   |   4   |

| AA(1) | pad.................. |
| BB(1) | BB(2) | BB(3) | BB(4) |
| CC(1) | pad.................. |

and sizeof(Test) would be 4 × 3 = 12, even though it only contains 6 bytes of data. The most common use case for the #pragma (to my knowledge) is when working with hardware devices where you need to ensure that the compiler does not insert padding into the data and each member follows the previous one. With #pragma pack(1), the struct above would be laid out like this:

|   1   |

| AA(1) |
| BB(1) |
| BB(2) |
| BB(3) |
| BB(4) |
| CC(1) |

And sizeof(Test) would be 1 × 6 = 6.

With #pragma pack(2), the struct above would be laid out like this:

|   1   |   2   |

| AA(1) | pad.. |
| BB(1) | BB(2) |
| BB(3) | BB(4) |
| CC(1) | pad.. |

And sizeof(Test) would be 2 × 4 = 8.
*/

