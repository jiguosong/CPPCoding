/*
 * GotW02.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: songjiguo
 */

#include <string>
#include <list>
#include <algorithm>

using namespace std;

typedef string employee;

string find_addr(const list<employee> &emps, const string &name) {
	const auto i = std::find(begin(emps), end(emps), name);
	//return i != end(emps) ? i->addr : "";
    return "";
}

int main()
{}

