/*
 * floatingpoint.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: songjiguo
 */

/*

 Precision	Total Length (bits)	Sign (bits)	Exponent (bits)	Mantissa (bits)
  	Single 	32 	1 	8 	23
	Double 	64 	1 	11 	52
	Double-extended/quadruple	128 	1 	15 	112

The following table shows the smallest and largest allowable absolute values for each precision level:

Precision	Minimum Allowable Absolute Value	Maximum Allowable Absolute Value
	Single 	2 ** -126( ≈ 1.1754944E-38) 				2 ** +128( ≈ 3.4028235E+38)
	Double 	2 ** -1022( ≈ 2.2250738585072013E-308) 		2 ** +1024( ≈ 1.797693134862315E+308)
	Double-extended(quadruple) 	2 ** -16382(3.3621031431120935062626778173218E-4932) 	2 ** +16384(1.189731495357231765085759326628E+4932)

*/

#include <iostream>
#include <limits>
#include <bitset>

using namespace std;

typedef union {
	float f;
	struct {
		unsigned int matisa:23;    // significand
		unsigned int exponent:8;
		unsigned int sign:1;
	};
} double_cast;

int main()
{
	// how to get significand, exponent and sign
	double_cast tc;
	tc.f = -float(1)/float(3);
	cout << tc.f << endl;

	cout << "significand " <<  tc.matisa << endl;
	cout << "hex 0x" <<  std::hex << tc.matisa << endl;
	cout << "bits " <<  std::bitset<32>(tc.matisa) << endl;
	cout << endl;


	cout << "exponent " <<  std::bitset<8>(tc.exponent) << endl;
	cout << "hex 0x" <<  std::hex << tc.exponent << endl;
	cout << "bits " <<  std::bitset<32>(tc.exponent) << endl;
	cout << endl;

	cout << "sign " <<  std::bitset<8>(tc.sign) << endl;
	cout << "hex 0x" <<  std::hex << tc.sign << endl;
	cout << "bits " <<  std::bitset<32>(tc.sign) << endl;
	cout << endl;

	// how to control the precision:: To get the correct results, don't set precision greater than available for this numeric type
	double a; // = 0.3;
	double f1 = 1;
	double f2 = 3;
	a = f1/f2;
	std::cout.precision(std::numeric_limits<double>::digits10);  // see above precision digits
	std::cout << a << std::endl;
	double b = 0;
	for (char i = 1; i <= 50; i++) {
			  b = b + a;
	};
	std::cout.precision(std::numeric_limits<double>::digits10);
	std::cout << b << std::endl;
	cout << endl;

//Precision and range
/*Consider the fraction 1/3. The decimal representation of this number is 0.33333333333333… with 3’s going out to infinity. An infinite length number would require infinite memory to store, and we typically only have 4 or 8 bytes. Floating point numbers can only store a certain number of significant digits, and the rest are lost. The precision of a floating point number defines how many significant digits it can represent without information loss.
When outputting floating point numbers, cout has a default precision of 6 -- that is, it assumes all floating point variables are only significant to 6 digits, and hence it will truncate anything after that.
The following program shows cout truncating to 6 digits:*/

	double d1(5000.0);
	double d2(5e3); // another way to assign 5000

	double d3(0.05);
	double d4(5e-2); // another way to assign 0.05

    float f;
    f = 9.87654321f;
    std::cout << f << std::endl;
    f = 987.654321f;
    std::cout << f << std::endl;
    f = 987654.321f;
    std::cout << f << std::endl;
    f = 9876543.21f;
    std::cout << f << std::endl;
    f = 0.0000987654321f;
    std::cout << f << std::endl;

    // we set the precision to 16 digits, each of the above numbers is printed with 16 digits. But, as you can see, the numbers certainly aren’t precise to 16 digits!
    // We lost some precision!   // rounding error
    std::cout.precision(16);
	f = 3.33333333333333333333333333333333333333f;
	std::cout << f << std::endl;
	double d = 3.3333333333333333333333333333333333333;
	std::cout << d << std::endl;
	float f3(123456789.0f); // f has 10 significant digits
	std::cout.precision(9) ; // to show 9 digits in f
	std::cout << f3 << std::endl;

    return 0;

}
