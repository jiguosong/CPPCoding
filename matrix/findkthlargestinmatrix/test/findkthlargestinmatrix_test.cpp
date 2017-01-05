/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <iomanip>

#include "../src/findkthlargestinmatrix.h"

using std::cout;
using std::endl;
using std::vector;

template<class T>
void PrintVector(const vector<T> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		cout << std::setw(2) << vec[i] << ' ';
	cout << endl;
}

template<class T>
void PrintVectorVector(const vector<vector<T>> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		PrintVector(vec[i]);
}

TEST(findkthlargestinmatrix, normal)
{
	findkthlargestinmatrix tc;

}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
