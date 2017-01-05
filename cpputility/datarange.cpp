/*
 * minrange.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: songjiguo
 */

/*
The C++ standard does not specify the size of integral types in bytes, but it specifies minimum ranges
they must be able to hold. You can infer minimum size in bits from the required range. You can infer
minimum size in bytes from that and the value of the CHAR_BIT macro that defines the number of bits
in a byte (in all but the most obscure platforms it's 8, and it can't be less than 8).
One additional constraint for char is that its size is always 1 byte, or CHAR_BIT bits (hence the name).

Minimum ranges required by the standard (page 22) and Data Type Ranges on MSDN:

    signed char: -127 to 127 (note, not -128 to 127; this accommodates 1's-complement and sign-and-magnitude platforms)
    unsigned char: 0 to 255
    "plain" char: same range as signed char or unsigned char, implementation-defined
    signed short: -32767 to 32767
    unsigned short: 0 to 65535
    signed int: -32767 to 32767
    unsigned int: 0 to 65535
    signed long: -2147483647 to 2147483647
    unsigned long: 0 to 4294967295
    signed long long: -9223372036854775807 to 9223372036854775807
    unsigned long long: 0 to 18446744073709551615

A C++ (or C) implementation can define the size of a type in bytes sizeof(type) to any value, as long as
the expression sizeof(type) * CHAR_BIT evaluates to a number of bits high enough to contain required ranges,
and the ordering of type is still valid (e.g. sizeof(int) <= sizeof(long)).

The actual implementation-specific ranges can be found in <limits.h> header in C, or <climits> in C++
(or even better, templated std::numeric_limits in <limits> header).

For example, this is how you will find maximum range for int:

C:

#include <limits.h>
const int min_int = INT_MIN;
const int max_int = INT_MAX;

C++:

#include <limits>
const int min_int = std::numeric_limits<int>::min();
const int max_int = std::numeric_limits<int>::max();
*/


// example to handle overflow

/*#include <limits.h>
int safe_add(int a, int b) {
    if (a > 0 && b > INT_MAX - a) {
         handle overflow
    } else if (a < 0 && b < INT_MIN - a) {
         handle underflow
    }
    return a + b;
}*/


#include <iostream>
#include <limits>

int main(int argc, char * argv[])
{
	std::cout << "size of char: " << sizeof(char) << std::endl;
	std::cout << "size of short: " << sizeof(short) << std::endl;
	std::cout << "size of int: " << sizeof(int) << std::endl;
	std::cout << "size of int: " << sizeof(int) << std::endl;
	std::cout << "size of long: " << sizeof(long) << std::endl;
	std::cout << "size of long long: " << sizeof(long long) << std::endl;

	std::cout << "size of float: " << sizeof(float) << std::endl;
	std::cout << "size of double: " << sizeof(double) << std::endl;

	std::cout << "size of pointer: " << sizeof(int *) << std::endl;

	const int min_int = std::numeric_limits<int>::min();
	const int max_int = std::numeric_limits<int>::max();
	std::cout << "min_int (-2^31) " << min_int << std::endl;
	std::cout << "max_int (2^31-1) " << max_int << std::endl;

	const long long min_long_long = std::numeric_limits<long long>::min();
	const long long max_long_long = std::numeric_limits<long long>::max();
	std::cout << "min_long_long (-2^63) " << min_long_long << std::endl;
	std::cout << "max_long_long (2^63-1) " << max_long_long << std::endl;

}

