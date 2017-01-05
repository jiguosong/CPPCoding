/*
 * helloGotW.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: songjiguo
 */

/*
Guideline: Prefer to use initialization with { }, such as vector<int> v = { 1, 2, 3, 4 }; or auto v = vector<int>{ 1, 2, 3, 4 };,
because it’s more consistent, more correct, and avoids having to know about old-style pitfalls at all. In single-argument cases
where you prefer to see only the = sign, such as int i = 42; and auto x = anything; omitting the braces is fine.
Guideline: In rare cases, such as vector<int> v(10,20); or auto v = vector<int>(10,20);, use initialization with ( ) to explicitly
           call a constructor that is otherwise hidden by an initializer_list constructor.
Guideline: When you design a class, avoid providing a constructor that ambiguously overloads with an initializer_list constructor,
		   so that users won’t need to use ( ) to reach such a hidden constructor
*/


/*
 *  Compare C++ and Java declare array
 *
 *  Java:  1) int[] array = new int[n];  or int num[] = new int[5]; (less prefraable)
 *         2) int[] array = {1,2,3,4 ...};   or  int num[] = {1, 2, 3, 4, 5};  (less prefraable)
 *
	C++  (8 different ways)
	0 std::array<int, 3> arr0({1, 2, 3});
	1 std::array<int, 3> arr1({{1, 2, 3}});
	2 std::array<int, 3> arr2{1, 2, 3};
	3 std::array<int, 3> arr3{{1, 2, 3}};
	4 std::array<int, 3> arr4 = {1, 2, 3};
	5 std::array<int, 3> arr5 = {{1, 2, 3}};
	6 std::array<int, 3> arr6 = std::array<int, 3>({1, 2, 3});
	7 std::array<int, 3> arr7 = std::array<int, 3>({{1, 2, 3}});

	int MyNumbers[] = {1,2,3,4,5,6,7,8,9,10};
	int x[10];
	int* x = new int[10];



  C++ : myThreads[i] = std::thread(exec, i);
*/


class widget {
public:
	widget():X(0){};
	widget(int x):X(x){};
private:
	int X;
};


int main()
{
	// https://herbsutter.com/2013/05/09/gotw-1-solution/
	int x = 10;

	widget w;       // default ctor              // (a)
	widget w2();   // a function return widget   // (b)
	widget w3{};    // default ctor              // (c)
	widget w4(x);     // (d) a compatible type with the constructor argument, with implicit cast allowed    // (d)
	widget w5{x};     // (e) exactly the type with the constructor argument, with no implicit cast allowed OR if widget have an initializer-list constructor // (e)
	// Common Mistake: This is always initialization; it is never assignment, and so it never calls T::operator=(). Yes, I know there’s an “=” character in there, but don’t let that throw you — that’s just a syntax holdover from C, not an assignment operation.
	widget w6 = x;    // (f)   allow implicit cast
	widget w7 = {x};  // (g)   ???
	auto w8 = x;     // (h) copy initializes a w, with the same type as x (h)
	auto w9 = widget { x };  // (i) copy initialization, and w is going to be of type x // (i)

}

