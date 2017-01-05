/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "createmaxnumber.h"

using std::cout; 
using std::endl;
using std::vector;

/*
   Choose auto x when you want to work with copies.
   Choose auto &x when you want to work with original items and may modify them.
   Choose auto const &x when you want to work with original items and will not modify them 
*/
template<class T>
void PrintVector(const vector<T> &vec)
{
	for(auto const &v:vec) cout << v << ' ';
	cout << endl;
}

template<class T>
void PrintVectorVector(const vector<vector<T>> &vec)
{
	for(auto const &v:vec) PrintVector(v);
}

TEST(createmaxnumber, normal1)
{
	createmaxnumber tc;
	vector<int> a1 = {3, 4, 6, 5};
	vector<int> a2 = {9, 1, 2, 5, 8, 3};
	int k = 5;
	vector<int> ans = tc.maxNumber(a1, a2, k);

	for(int e:ans) cout << e << " ";

}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
