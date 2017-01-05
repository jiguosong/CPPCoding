/*
 * GotW05_overridevrifun.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: songjiguo
 */
/*
Overload, override and hide:
  1) To overload a function f means to provide another function with the same name in the same scope but with different parameter types.
     When f is actually called, the compiler will try to pick the best match based on the actual parameters that are supplied.
  2) To override a virtual function f means to provide another function with the same name and the same parameter types in a derived class.
  3) To hide a function f that exists in an enclosing scope (base class, outer class, or namespace) means to provide another function with
     the same name in an inner scope (derived class, nested class, or namespace), which will hide the same function name in an enclosing scope.
*/

#include <iostream>
#include <complex>
#include <memory>

using namespace std;

// Guideline: Prefer to have a class contains only public virtual functions, or no public virtual functions (other than the destructor which is special).
//            A pure abstract base class should have only public virtual functions.
// Non-Virtual Interface pattern (NVI) ::  For any other base class, prefer making public member functions non-virtual, and virtual member functions non-public;
//                                         the former should have any default arguments and can be implemented in terms of the latter.
class base
{
public:
	virtual void f(int);
	virtual void f(double);
	virtual void g(int i = 10);
	// Guideline: Make base class destructors public and virtual, or protected and nonvirtual.
	virtual ~base(){};
};

void base::f(int) {
	cout << "base::f(int)" << endl;
}

void base::f(double) {
	cout << "base::f(double)" << endl;
}

void base::g(int i) {
	cout << i << endl;
}

class derived: public base
{
public:
	// Guideline: When providing a non-overridden function with the same name as an inherited function, be sure to bring the inherited functions into scope with a using-declaration if you don’t want to hide them.
	void f(std::complex<double>);
	// using base::f;

	// Guideline: Always write override when you intend to override a virtual function.
	// Guideline: Never change the default arguments of overridden inherited functions.
	// Guideline: or Avoid default arguments on virtual functions in general. (I like this)
	void g(int i = 20) override;      /* override */
};

void derived::f(complex<double>) {
	cout << "derived::f(complex)" << endl;
}

void derived::g(int i) {
	cout << "derived::g() " << i << endl;
}

int main() {
	base b;
	derived d;

	// Guideline: Don’t use explicit new, delete, and owning * pointers, except in rare cases encapsulated inside the implementation of a low-level data structure.
	//base* pb = new derived;
	auto pb = std::unique_ptr<base>{new derived};

	b.f(1.0);
	d.f(1.0);    // complex<double> provides an implicit conversion from double, since there is no using base::f
	pb->f(1.0);  // overload resolution is done on the static type (here base), not the dynamic type (here derived).
	             // You have a base pointer, you get the base interface.

	b.g();
	d.g();
	pb->g(); // default parameters are taken from the static type (here base) of the object, hence the default value of 10 is taken.
	         // However, the function happens to be virtual, and so the function actually called is based on the dynamic type (here derived) of the object.

	//delete pb;  // no need due to uniqe_ptr
}

