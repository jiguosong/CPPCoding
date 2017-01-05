/*
 * testoutput.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include<typeinfo>
using namespace std;

/*
you are using base class pointer to point to both base class object & derived class object. so when you point the pointer to base
class object & then increment the pointer then the pointer will move to next address according to the base class size, In case when
base class pointer points to the derived class object in that case when u increment the base class pointer to +1 it will again move
to next address according to base class size which will be less then derived class size. do it will point somewhere in between, & in
the second iteration the value of 'b' is considered as 'a' & printed out.

always be careful while using pointers, use derived class pointer & no error will come, the output will be as you expected.

base *obj = arrb;
der *obj1 = arrd;
*/

/*The problem is due to 'Early Binding' when (obj+i)->getA() is used. So, the compiler sees pointer to base and
is set to calling getA in base without knowing the object's type. To perform 'Runtime Binding' you need to use
the 'virtual' keyword in base for getA. The following should work normally.*/

class base {
public:
	int a;
	base() : a(0) {}
	virtual int getA() {
		return a;
	}
	virtual ~base(){};
};

class der: public base {
public:
	int b;
	der() : b(1) {}
	int getB() {
		return b;
	}

	virtual ~der(){};
};
void display(base *obj, int ele) {
	for (int i = 0; i < ele; i++) {
		cout << (obj + i)->getA() << endl;
	}
}

int main() {

	constexpr int a = {3};
	constexpr int i = {3};
	base arrb[i];
	display(arrb, 3);
	der arrd[i];
	display(arrd, 3);
	return 0;
}

