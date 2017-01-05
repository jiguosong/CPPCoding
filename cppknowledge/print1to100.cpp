/*
 * print1to100.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: songjiguo
 */

#include <iostream>

using namespace std;

// method 1    --- at compile time (meta programming style)
template<int N>
struct PrintN {
	static void print() {
		PrintN<N - 1>::print();
		cout << N << ' ';
	}
};

template<>
struct PrintN<1> {
	static void print() {
		cout << 1 << ' ';
	}
};

// method 2 (c++ style)
class A {
public:
	static int a;
	A() {
		cout << a++ << ' ';
	}
};

int A::a = 1;


// method 3  (c style)

static void printN(int n)
{
	if(n == 1) {
		cout << n << ' ';
		return;
	}
	printN(n-1);
	cout << n << ' ';
}

int main() {
	const int N = 20;
	PrintN<N>::print();
	cout << endl;
	A aaa[N];
	cout << endl;

	printN(N);
}

