/*
 * testexception.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

/*
look at the smart pointer too!!!!

For constructor and destructor,
!!!it’s ok to throw in a constructor but never throw in a destructor

that destructors are only called for fully constructed objects.
So if an exception is thrown in the main body of the constructor,
the destructors for all the data members are called but the
destructor for the object being created is not.

*/

#include <iostream>

#include <exception>
#include <typeinfo>
#include <stdexcept>


#include <vector>
using std::vector;

class A {
public:
	A() {
	}
	~A() {
		throw 42;
	}
};

int main(int argc, const char * argv[])
{
	try {
		A a;
		throw 32;
	} catch (int a) {
		std::cout << a;
	}

/*
	try {
		throw ...; // throw something
	} catch (...) {
		std::exception_ptr p = std::current_exception();
		std::clog << (p ? p.__cxa_exception_type()->name() : "null") << std::endl;
	}
	return 1;

	//If you want to catch all STL exceptions, you can do

	try {
	...} catch (const std::exception &e) {
	...} // e.what() e.what(), which will return a const char*, which can tell you more about the exception itself.
*/

	std::vector<int> A(2);
	try {
		A.at(10) = 3;
	}  catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}

}

