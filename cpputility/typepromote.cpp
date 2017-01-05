/*
 * lower_typepromotedtohighertype.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */


#include <iostream>

using namespace std;

/*
In C++, if the types of two operands differ from one another, then the operand with
the “lower type” will be promoted to the type of the “higher type” operand, using
the following type hierarchy (listed here from highest type to lowest type):
long double, double, float, unsigned long int, long int, unsigned int, int (lowest).

the result of the operation will be of the type of the operands

*/

int main() {

	cout << 25u-50 << endl;

}


