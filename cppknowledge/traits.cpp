/*
 * traits.cpp
 *
 *  Created on: Dec 28, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <type_traits>

//using namespace std;
//
//template<typename >
//struct is_pointer
//{
//};
//
//template<typename T>
//struct is_pointer<T*>
//{
//	enum
//	{
//		value = true
//	};
//};
//
//void f(const bool &b)
//{
//	std::cout << b << std::endl;
//}

class A
{
};

int main()
{
	//f(is_pointer<void*>::value);
	std::cout << std::boolalpha;
	std::cout << std::is_pointer < A > ::value << '\n';
	std::cout << std::is_pointer<A *>::value << '\n';
	std::cout << std::is_pointer<A &>::value << '\n';
	//std::cout << std::noboolalpha;
	std::cout << std::is_pointer<int>::value << '\n';
	std::cout << std::is_pointer<int *>::value << '\n';
	std::cout << std::is_pointer<int **>::value << '\n';
	std::cout << std::is_pointer<int[10]>::value << '\n';
	std::cout << std::is_pointer < std::nullptr_t > ::value << '\n';
}

