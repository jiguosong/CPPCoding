/*
 * desctruction_test.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

/*
static_cast is used for cases where you basically want to reverse an implicit conversion,
with a few restrictions and additions. static_cast performs no runtime checks.
This should be used if you know that you refer to an object of a specific type,
and thus a check would be unnecessary.

dynamic_cast is used for cases where you don't know what the dynamic type of the object is.
You cannot use dynamic_cast if you downcast and the argument type is not polymorphic.
*/

#include <iostream>
using namespace std;

static int cnt = 0;

class Base {
    virtual void method() {cout << "from Base cnt " << cnt++ << endl;}
public:
    virtual ~Base() {method();}
    void baseMethod() {method();}
    Base(){cout << "Base Cons...." << endl;};
    void hello(){cout << "hello" << endl;};
};

class A : public Base {
    void method() {cout << "from A cnt " << cnt++ << endl;}
public:
    ~A() {method();}
};

// if you want to always create via new rather than as local, namespace-scope, global, or static
// Make sure your constructors are in the protected section if you expect Fred to have derived classes.
class Fred {
public:
  // The create() methods are the "named constructors":
  static Fred* create()                 { return new Fred();     }
  static Fred* create(int i)            { return new Fred(i);    }
  static Fred* create(const Fred& fred) { return new Fred(fred); }
  // ...
private:
  // The constructors themselves are private or protected:
  Fred();
  Fred(int i);
  Fred(const Fred& fred);
  // ...
};

class TBase
{
public:
    virtual void eval() const
    {
        std::cout<<"Base Const Eval\n";
    }
};

class Derived:public TBase
{
public:
	//If add the const for Derived::eval(), you should get virtual behavior.
	// this is not overriding the base class eval -- different signature
    void eval()
    {
        std::cout<<"Derived Non-Const Eval\n";
    }
};

int main(void) {
    Base* base = new A;
    base->baseMethod();
    delete base;

    // the following is the same as Base* p = new A;
    Base *p;
    void *tmp = operator new(sizeof(Base));
    try {
    	new(tmp) Base();
    	p = (Base *)tmp;
    } catch(...) {
    	operator delete(tmp);
    	throw;
    }

    // array of new objects
    A* q = new A[10];
    for(int i = 0; i < 10; i++) {
    	q[i].hello();
    }
    delete[] q;

    //Fred *abc = Fred::create();


    Derived d;
    TBase* pB=&d;

    pB->eval(); //This will call the Base eval()


    return 0;
}


