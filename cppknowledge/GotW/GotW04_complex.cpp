/*
 * complex.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: songjiguo
 */
/*
Guideline: Reuse code—especially standard library code—instead of handcrafting your own. It’s faster, easier, and safer.
*/

#include <ostream>
#include <iostream>

class complex {
public:
	complex():real(0), imag(0) {}
	complex(double r, double i):real(r), imag(i) {std::cout << "constructor" << std::endl;}

	// Guideline: Prefer passing a read-only parameter by const& if you are only going to read from it (not make a copy of it).
	// Guideline: If you supply a standalone version of an operator (e.g., operator+), always supply an assignment version of the same operator (e.g., operator+=)
	//            and prefer implementing the former in terms of the latter. Also, always preserve the natural relationship between op and op= (where op stands
    //            for any operator).
	// Guideline: Prefer writing a op= b instead of a = a op b (where op stands for any operator). It’s clearer, and it’s often more efficient.
	complex& operator+=(complex &other){
		std::cout << "+= operator" << std::endl;
		std::cout << "this.real " << real << std::endl;
		std::cout << "this.imag " << imag << std::endl;

		std::cout << "other.real " << other.real << std::endl;
		std::cout << "other.imag " << other.imag << std::endl;

		real += other.real;
		imag += other.imag;
		return *this;
	}

	// Guideline: When you return *this, the return type should usually be a reference.
	complex& operator++(){
		std::cout << "++ operator" << std::endl;
		++real;
		return *this;
	}

	// Guideline: For consistency, always implement postincrement in terms of preincrement, otherwise your users
	// will get surprising (and often unpleasant) results.
	complex operator++(int) {
		std::cout << "++ operator with int" << std::endl;
		auto tmp = *this;
		++*this;
		return tmp;
	}

	std::ostream& print(std::ostream& os) const {
		return os << "(" << real << ", " << imag << ")";
	}


private:
	double real;
	double imag;
};

// Guideline: Prefer passing a read-only parameter by value if you’re going to make a copy of the parameter anyway, because it enables move from rvalue arguments.
// Guideline: Prefer these guidelines for making an operator a member vs. nonmember function: unary operators are members; = () [] and -> must be members; the assignment operators (+= –= /= *= etc.) must be members; all other binary operators are nonmembers.
complex operator+(complex lhs, complex &rhs){
	lhs += rhs;
	return lhs;
}

// Guideline: Always return stream references from operator<< and operator>>.
std::ostream& operator<<(std::ostream &os, const complex &src) {
	return src.print(os);
}

int main()
{
	complex a;
	complex b{1.2, 3.4};
	complex c{22, 34};
	b += c;
	std::cout << b << std::endl;
	complex d=b++;
	std::cout << d << std::endl;
	b++;
}
