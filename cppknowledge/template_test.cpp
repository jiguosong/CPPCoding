/*
 * template_test.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

/*
 Implement a template function IsDerivedFrom() that takes class C and class P as
 template parameters. It should return true when class C is derived from class P
 and false otherwise.
 */

/*
 When B is a base class of D, the call Test(static_cast<D*>(0)) resolves to Yes Test(B*).
 Otherwise, it resolves to No Test(...).

 If B is a base class of D, the value of sizeof(Test(static_cast<D*>(0))) is sizeof(Yes).
 Otherwise, it is equal to sizeof(No).

 Yes and No are defined such that sizeof(Yes) will never be equal to sizeof(No).

 If B is a base class of D, sizeof(Test(static_cast<D*>(0))) == sizeof(Yes) evaluates to
 true. Otherwise it evaluates to false.
 */

#include <iostream>
#include <type_traits>
using namespace std;

//  isDerivedFrom
template<typename D, typename B>
class IsDerivedFromHelper
{
	class No
	{
	};
	class Yes
	{
		No no[3];
	};

	static Yes Test(B*);
	static No Test(... );
public:
	enum
	{
		Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes)
	};

};

template<class C, class P>
bool IsDerivedFrom()
{
	return IsDerivedFromHelper<C, P>::Is;
}

// isSameClass
template<typename T, typename U>
struct is_same
{
	static const bool value = false;
};

/*
 template <typename T>
 struct is_same<T, T>
 {
 static const bool value = true;
 };


 template <class A, class B>
 bool IsSameClass()
 {
 return is_same<A, B>::value;
 }

 */

/*The job of the compiler is to do type inference, template instantiation,
 and type construction, which involve computation*/
/*Here is an example of a class template which computes the factorial of a natural number:*/
template<int n>
struct Factorial
{
	enum
	{
		RET = Factorial<n - 1>::RET * n
	};
};
//the following template specialization terminates the recursion
template<>
struct Factorial<0>
{
	enum
	{
		RET = 1
	};
};

#include <array>
#include <vector>
#include <string>
#include <type_traits>

// http://stackoverflow.com/questions/13260581/c-stdenable-if#13260623
// enable_if is primarily used to conditionally remove functions and classes from overload resolution based on type traits and to provide separate function overloads and specializations for different type traits.
template<typename T, size_t N>
typename std::enable_if<N <= 128, void>::type insertion_sort(
		std::array<T, N> &array)
{
	cout << "doing insertion sort......" << endl;
}

// https://oopscenities.net/2012/06/02/c11-enable_if/
template<typename T>
struct has_iterator
{
	template<typename U>
	static char test(typename U::iterator* x);

	template<typename U>
	static long test(U* x);

	static const bool value = sizeof(test<T>(0)) == 1;
};

template<typename T>
typename std::enable_if<!has_iterator<T>::value, void>::type show(const T& x)
{
	cout << x << endl;
}

template<typename T>
typename std::enable_if<has_iterator<T>::value, void>::type show(const T& x)
{
	for (auto& i : x)
		cout << i << endl;
}

// compile time check if a+b is 10
template<int a, int b>
class foo
{
	static_assert(a+b==10, "a+b is not 10");
};

int main()
{
	std::array<int, 1000> myarray;
	// insertion_sort(myarray);    --> this will fail due to enable_if < 128

	int a = 128;
	cout << "testsetsetset......" << endl;
	cout << has_iterator<int>::value << endl;
	std::vector<std::string> sss = { "today", "is", "Saturday" };
	cout << has_iterator<std::vector<std::string>>::value << endl;
	show(a);
	show(sss);

	foo<5, 5> f;
	//foo<5,6> g;  // fail!!!!

	class A
	{
	};
	class B: public A
	{
	};
	class C
	{
	};

	std::cout << std::boolalpha;
	std::cout << "a2b: " << std::is_base_of<A, B>::value << '\n';
	std::cout << "b2a: " << std::is_base_of<B, A>::value << '\n';
	std::cout << "c2b: " << std::is_base_of<C, B>::value << '\n';
	std::cout << "same type: " << std::is_base_of<C, C>::value << '\n';

	std::cout << "my derive from test:" << IsDerivedFrom<B, A>() << '\n';
	//std::cout << "my same class test:" << IsSameClass<B, A>() << '\n';

	cout << Factorial<7>::RET << endl; //prints 5040
}

