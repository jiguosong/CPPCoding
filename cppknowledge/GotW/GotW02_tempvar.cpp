/*
 * GotW02.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: songjiguo
 */

#include <string>
#include <list>

using namespace std;

typedef string employee;

// Guideline: Prefer passing a read-only parameter by const& if you are only going to read from it (not make a copy of it).
string find_addr(const list<employee> &emps, const string &name) {
	// 1) Guideline: Prefer declaring variables using auto. Among other reasons to do so, it naturally guarantees zero extra temporaries due to implicit conversions.
	// For most containers, including list, calling end() returns a temporary object that must be constructed and destroyed, even though the value will not change.
	// 2) Guideline: Prefer precomputing values that won’t change, instead of recreating objects unnecessarily.
	// Note: compiler might do this for you
	// 3) Guideline: For consistency, always implement postincrement in terms of preincrement, otherwise your users will get surprising (and often unpleasant) results.
	// Guideline: Prefer preincrement. Only use postincrement if you’re going to use the original value.
    for( auto i = begin(emps); i != end(emps); ++i ) {
/*    	 if( i->name() == name ) {
			return i->addr;
    	  }*/
    }

    // Indeed, every string implementation I checked is smart enough not to perform an allocation here,
    // alternatives: return “”s; which is new in C++14
    // alternatives: return { };
    // no difference
    return "";
}


int main()
{}

