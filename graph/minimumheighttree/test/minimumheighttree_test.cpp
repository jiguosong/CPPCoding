/* googletest unit test for C++ */

#include "gtest/gtest.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
//
//#include <array>
//#include <vector>
//#include <forward_list>
//#include <list>
//#include <deque>
//
//#include <set>    // multiset is also defined here
//#include <map>    // multimap is also defined here
//#include <unordered_set>  // unordered_multiset is also defined here
//#include <unordered_map>  // unordered_multimap is also defined here

/*
 * stack          - use standard containers std::vector, std::deque and std::list
 * queue          - use standard containers std::deque and std::list
 * priority_queue - use standard containers std::vector and std::deque
 * */
//#include <stack>       // stack
//#include <queue>       // queue + priority_queue
//
//#include <algorithm>
//#include <random>
//#include <string>
//#include <memory>

using namespace std;

#include "../src/minimumheighttree.h"

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

template<class T>
bool CompareVectorVector(const vector<T> &v1, const vector<T> &v2)
{
	if (v1.size() != v2.size())
		return false;

	std::multiset<T> s1(v1.begin(), v1.end());
	std::multiset<T> s2(v2.begin(), v2.end());
	std::vector<T> v3;
	std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
			std::back_inserter(v3));
	return (v3.size() == v1.size());
}

TEST(minimumheighttree, normal1)
{
	minimumheighttree tc;

	int n = 4;
	vector<pair<int, int>> edges = { { 1, 0 }, { 1, 2 }, { 1, 3 } };
	vector<int> ans = tc.findMinHeightTrees(n, edges);
	vector<int> expected = {1};
	ASSERT_TRUE(CompareVectorVector(ans, expected));
}

TEST(minimumheighttree, normal2)
{
	minimumheighttree tc;

	int n = 6;
	vector<pair<int, int>> edges = { { 0, 3 }, { 1, 3 }, { 2, 3 }, { 4, 3 }, {
			5, 4 } };
	vector<int> ans = tc.findMinHeightTrees(n, edges);
	vector<int> expected = { 3, 4 };
	ASSERT_TRUE(CompareVectorVector(ans, expected));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
