/*
 * dreaded_diamon.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: songjiguo
 */

/*
                             Base
                             /  \
                            /    \
                           /      \
                        Der1      Der2
                           \      /
                            \    /
                             \  /
                             Join
*/
//  solution : add virtual -- just below the top of the diamond, not at the join-class.
class Base {
public:
	// ...
protected:
	int data_;
};

class Der1: public virtual Base { /*...*/
};

class Der2: public virtual Base { /*...*/
};

class Join: public Der1, public Der2 {
public:
	void method() {
		data_ = 1;  // Bad: this is ambiguous; solution : add virtual as the solution
	}
};

/*The key is to realize that Base is inherited twice, which means any data members declared in Base,
such as data_ above, will appear twice within a Join object. This can create ambiguities:
which data_ did you want to change? For the same reason the conversion from Join* to Base*,
or from Join& to Base&, is ambiguous: which Base class subobject did you want?*/


int main() {
	Join* j = new Join();
	Base* b = j;   // Bad: this is ambiguous; solution : add virtual
}

