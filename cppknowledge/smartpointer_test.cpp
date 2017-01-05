/*
 * smartpointer.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: songjiguo
 */

// smart pointer goal: make less exception  -- > rule of almost zero

/*There are many examples both in Boost and the standard library. These generally vary according
to what happens on copying the pointer. There are four obvious solutions to copying:

   p1 = p2;  // ????
 	 	    ____
  *p1  --> |____|

  *p2

 0) stay away from raw pointers
    -- try not to use "malloc, free, delete, new [], delete []"
    -- try to only use "delete" when implement smart pointer
    -- for new [], use "std::vector<Class> v(n);"

 1) Make copying illegal
    -- copy constructor and assignment set as private
    -- or throw exception
    -- pro: easy to implement
    -- con: compile time or run time

 2) Copy the pointed-to object
    -- clone() or explicitly copy the pointed object
    -- pro: easy to think
    -- con: slow
 	 	    ____
  *p1  --> |____|
 	 	    ____        "copy"
  *p2  --> |____|

 3) Have the pointers share ownership of the object.
    -- shared ptr
    -- reference counting like
    -- pro: efficient
    -- con: shared state
 	 	    ____
  *p1  --> |____|
        /
  *p2  /

 4) Transfer ownership of the pointer to the new object
    -- uniqe_ptr (old auto ptr)
    -- how to deal *p1 then? p1 = nullptr ?
    -- pro: single copy
    -- con: ownership is transferred. uniqe_ptr is better.
            not working container

  *p1
    	    ____
  *p2  --> |____|


 Conclusion: if copy is expensive, try to use shared_ptr
             if copy is not concern, try to use copy style

 !!!!  rule of almost zero !!!! (not define any, except virtual destructor)


 Another way to understand:
   1) Create a new copy of the object pointed by p, and have q point to this copy
   2) Ownership transfer: Let both p and q point to the same object, but transfer the responsibility for cleaning up ("ownership") from p to q
   3) Reference counting: Maintain a count of the smart pointers that point to the same object, and delete the object when this count becomes zero. So the statement q = p causes the count of the object pointed by p to increase by one
   4) Reference linking: The same as reference counting, only instead of a count, maintain a circular doubly linked list of all smart pointers that point to the same object
   5) Copy on write: Use reference counting or linking as long as the pointed object is not modified. When it is about to be modified, copy it and modify the copy
      -- for example, string class use COW smart pointer
*/


#include <iostream>
#include <memory>
#include <cassert>
#include <utility>
#include <vector>

using namespace std;

class T {
public:
	void SomeFunc(){};

	T &operator=(const T &other){};

private:
	int a;
};


// implement a smart pointer-lie reference counting

class KevinPtr;

class Kevin {
public:
	Kevin() : count_(0) {};
	int getCount() {return count_;};
private:
	friend class KevinPtr;
	int count_;
};

class KevinPtr {
public:
	Kevin *operator-> () {return p_;};
	Kevin operator* () {return *p_;};

	KevinPtr(Kevin *p): p_(p) {++p_->count_;};
	~KevinPtr() {if(--p_->count_ == 0) delete p_;}
	KevinPtr(const KevinPtr &p): p_(p.p_) {++p_->count_;};
	KevinPtr& operator= (const KevinPtr &p) {
		Kevin* const old = p_;
		p_ = p.p_;
		++p_->count_;
		if(--old->count_ == 0) delete old;
		return *this;
	}

private:
	Kevin *p_;
};


class X
{
};

int main() {
	T* pt1 = new T;
	// right now, we own the allocated object

	// pass ownership to an auto_ptr
	std::unique_ptr<T> pt2( pt1 );

	// use the auto_ptr the same way
	// we'd use a simple pointer
	//pt2->SomeFunc(); // same as "pt1->SomeFunc();"

	// use get() to see the pointer value
	//assert( pt1 == pt2.get() );

	// use release() to take back ownership
	//T* pt3 = pt2.release();

	// delete the object ourselves, since now
	// no auto_ptr owns it any more
	//delete pt3;

	Kevin *old = new Kevin();         // by default, there is no smart pointer
	KevinPtr *p1 = new KevinPtr(old); // init to 0 and increase
	KevinPtr *p2 = new KevinPtr(old);

	cout << old->getCount() << endl;
	delete p1;
	cout << old->getCount() << endl;
	delete p2;


/*	The C++ Standard says that an STL element must be "copy-constructible"
	and "assignable." In other words, an element must be able to be assigned
	or copied and the two elements are logically independent.
	std::auto_ptr does not fulfill this requirement.*/
	// http://ootips.org/yonat/4dev/smart-pointers.html
	std::vector<std::auto_ptr<X> > vecX;
	// vecX.push_back(new X);  -? wrong

	std::auto_ptr<X> pX = vecX[0];  // vecX[0] is assigned NULL.

	return 0;
}



