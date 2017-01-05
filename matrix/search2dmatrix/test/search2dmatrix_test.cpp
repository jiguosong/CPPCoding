/* googletest unit test for C++ */

#include "gtest/gtest.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

#include <array>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>

#include <set>    // multiset is also defined here
#include <map>    // multimap is also defined here
#include <unordered_set>  // unordered_multiset is also defined here
#include <unordered_map>  // unordered_multimap is also defined here

/*
 * stack          - use standard containers std::vector, std::deque and std::list
 * queue          - use standard containers std::deque and std::list
 * priority_queue - use standard containers std::vector and std::deque
 * */
#include <stack>       // stack
#include <queue>       // queue + priority_queue

#include <algorithm>
#include <random>
#include <string>
#include <memory>

using namespace std;

#include "search2dmatrix.h"
#include "../Matrix.h"

/*
 Choose auto x when you want to work with copies.
 Choose auto &x when you want to work with original items and may modify them.
 Choose auto const &x when you want to work with original items and will not modify them
 */
template<class T>
void PrintVector(const vector<T> &vec)
{
	for (auto const &v : vec)
		cout << v << ' ';
	cout << endl;
}

template<class T>
void PrintVectorVector(const vector<vector<T>> &vec)
{
	for (auto const &v : vec)
		PrintVector(v);
}

TEST(search2dmatrix, normal1)
{
	search2dmatrix tc;

	vector<vector<int>> matrix = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30,
			34, 50 } };
	auto target = 3;
	ASSERT_TRUE(tc.searchMatrix(matrix, target));
}

TEST(search2dmatrix, randommatrix)
{
	search2dmatrix tc;

	Matrix<int> *x = new Matrix<int>(5, 5, 1, 20);
	vector<vector<int>> matrix = x->getRowSortedIncreasingMatrix();

	PrintVectorVector(matrix);
	auto target = 3;
	ASSERT_TRUE(tc.searchMatrix(matrix, target));
}

TEST(search2dmatrix, testtensortemplate)
{
	// First example
	//=================================

	// A matrix of 3 rows and 4 columns.
	typedef TensorIndex<3, 4> M;

	// Store the matrix in a std::vector
	std::vector<double> M_Storage(M::SIZE);

	// Fill it with ones
	for (int row = 0; row < M::LEN1; ++row)
		for (int col = 0; col < M::LEN2; ++col)
			M_Storage[M::indexOf(row, col)] = 1.0;

	// Second example
	//=================================
	// A 4 x 5 x 6 x 7 cube
	typedef TensorIndex<4, 5, 6, 7> T;

	// Use an array for storage
	double T_Storage[T::SIZE];

	// Fill it with ones
	for (int i = 0; i < T::LEN1; ++i)
		for (int j = 0; j < T::LEN2; ++j)
			for (int k = 0; k < T::LEN3; ++k)
				for (int l = 0; l < T::LEN4; ++l)
					T_Storage[T::indexOf(i, j, k, l)] = 1.0;

	PrintVector (M_Storage);

	for(int i = 0; i < T::SIZE; ++i) cout << T_Storage[i];
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
