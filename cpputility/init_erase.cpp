/*
 * init_erase.cpp
 *
 *  Created on: Dec 29, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <cassert>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <unordered_set>
#include <numeric>
#include <time.h>
#include <fstream>
#include <limits>
#include <iomanip>
#include <iterator>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536

using namespace std;

int main(int argc, char **argv)
{
	int myarray[] = { 1, 2, 8, 4, 8, 6, 7, 8, 9, 10 };
	//array<int, 10> myarray2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "initilizaing vector....." << endl;
	// initialize vector from array -- method 1
	vector<int> v = { begin(myarray), end(myarray) };
	for (auto e : v)
		cout << e << ' ';
	cout << endl;

	// initialize vector from array -- method 2
	vector<int> v2;
	v2.assign(myarray, myarray + sizeof(myarray) / sizeof(int)); // treat pointers as iterators
	for (auto e : v2)
		cout << e << ' ';
	cout << endl;

	// initialize vector from array -- method 3
	vector<int> v3(myarray, myarray + sizeof(myarray) / sizeof(int));
	for (auto e : v3)
		cout << e << ' ';
	cout << endl;

	// initialize vector from array -- method 4
	vector<int> v4(v3);
	for (auto e : v4)
		cout << e << ' ';
	cout << endl;

	/*
	 ERASE item from vector
	 */

	cout << "\nerasing.....all with same value (erase-remove idiom)" << endl;
	// erease-remove idiom -- remove all items with value 8
	v.erase(remove(v.begin(), v.end(), 8), v.end());
	// same as this
	//	for (vector<int>::iterator testit = v4.begin(); testit != v4.end();
	//			++testit) {
	//		if(*testit == 8) v4.erase(testit);
	//	}
	for (auto e : v)
		cout << e << ' ';
	cout << endl;

	cout << "\nerasing.....range" << endl;
	// erease n items in a range
	v2.erase(v2.begin(), v2.begin() + 4);
	for (auto e : v2)
		cout << e << ' ';
	cout << endl;

	cout << "\nerasing.....item at nth position from begin" << endl;
	// erease item at certain position
	v3.erase(v3.begin() + 4);
	for (auto e : v3)
		cout << e << ' ';
	cout << endl;

	cout << "\nerasing.....find and erase it" << endl;
	// find and remove one item with value 8
	vector<int>::iterator it = find(v4.begin(), v4.end(), 8);
	if (it != v4.end())
		v4.erase(it);
	// same as this
	//	for (vector<int>::iterator testit = v4.begin(); testit != v4.end();
	//			++testit) {
	//		if(*testit == 8) {
	//			v4.erase(testit);
	//			break;
	//		}
	//	}

	for (auto e : v4)
		cout << e << ' ';
	cout << endl;


}

