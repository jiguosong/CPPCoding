/*
 * contexpress.cpp
 *
 *  Created on: Dec 21, 2016
 *      Author: songjiguo
 */

/*expressions available at compile time are called constant expressions.*/

#include <iostream>

using namespace std;

template<class T, int N>
constexpr int array_size(const T (&a)[N])
{
    return N;
}

int main()
{
	int b[] = {1,2,3};
	std::cout << array_size(b) << std::endl;
	double c[array_size(b)];

	c[0] = 2.3;
	c[1] = 1.3;
	c[2] = -2.3;

	for(auto e:c) cout << e << endl;

	constexpr double p = 7.2;
	int a[(int)p];

}




