/*
 * GotW08_smartpointer.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: songjiguo
 */

/* Guideline: Prefer to use the standard smart pointers, unique_ptr by
 * default and shared_ptr if sharing is needed. They are the common
 * types that all C++ libraries can understand. Use other smart
 * pointer types only if necessary for interoperability with other
 * libraries, or when necessary for custom behavior you can’t achieve
 * with deleters and allocators on the standard pointers.*/

/* Guideline: Use make_unique to create an object that isn’t shared
 * (at least not yet), unless you need a custom deleter or are
 * adopting a raw pointer from elsewhere. */


/*Guideline: Don’t use explicit new, delete, and owning * pointers,
 * except in rare cases encapsulated inside the implementation of a
 * low-level data structure.*/

/*Guideline: To allocate an object, prefer to write make_unique by
 * default, and write make_shared when you know the object’s lifetime
 * is going to be managed by using shared_ptrs.*/

//// Example 2(b): Single allocation
//auto sp1 = make_shared<widget>();
//auto sp2 = sp1;
//
//Above is better than
//
//// Example 2(a): Separate allocation
//auto sp1 = shared_ptr<widget>{ new widget{} };
//auto sp2 = sp1;
//

// this is similar to the case :2
// when inserting 100 elements into a vector using a single range-insert
// call to v.insert( first, last ) instead of 100 calls to v.insert( value )

