/*
 * check_c11.cpp
 *
 *  Created on: Oct 31, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

// slow
void naiveswap(string &a, string & b)
{
	string temp = a;
	a=b;
	b=temp;
}

string getName ()
{
    return "Alex";
}

int main(){

	// test	c++ version
	#if __cplusplus==201402L
	std::cout << "C++14" << std::endl;
	#elif __cplusplus==201103L
	std::cout << "C++11" << std::endl;
	#else
	std::cout << "C++" << std::endl;
	#endif

	// lambda function test
	char s[] = "Hello World!";
	int uppercount = 0;
	for_each(s, s+sizeof(s), [&uppercount] (char c) {
		if(isupper(c)) 	++uppercount;
	});
	cout<< uppercount<<" uppercase letters in: "<< s<<endl;

	// uniform initlization in C++11
	class C
	{
		int a = 0;   // C++11 only
		int b = 0;   // C++11 only
	public:
		C(int i, int j): a(i), b(j){cout << "i " << i << " j " << j << endl;}
		C(const C &other) = delete;   // C++11 only
		C &operator+(const C &other) = delete;  // C++11 only
		C() = default;                // C++11 only
		C(int i): C(55,55) {cout << "delegate another constructor" << endl;}
	};
	C c {1,2};   // C++11 only
	C c2 {3};   // C++11 only
	int *a = new int[3] {1,2,3};  // C++11 only
	vector<string> v = {"andy", "kevin"};  // C++11 only, similar for map

	// rvalue reference is a way to determine if a reference variable refers to a temporary object or to a permanent object
	const string &xxx = getName();  // will be error without const -- getName() is lvalue
	cout << xxx;
	string &&yyy = getName();  // rvalue reference is ok now in C++11
	cout << yyy;




}
