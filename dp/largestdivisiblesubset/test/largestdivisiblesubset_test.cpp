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

#include "largestdivisiblesubset.h"


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

TEST(largestdivisiblesubset, normal1)
{
	largestdivisiblesubset tc;

	vector<int> nums = {1,2,3};
	vector<int> res = tc.largestdivset(nums);

	vector<int> expected = {1,2};
	sort(expected.begin(), expected.end());
	sort(res.begin(), res.end());

	ASSERT_TRUE((res == expected));

}

TEST(largestdivisiblesubset, normal2)
{
	largestdivisiblesubset tc;

	vector<int> nums = {1,2,4,8};
	vector<int> res = tc.largestdivset(nums);

	vector<int> expected = {1,2,4,8};
	sort(expected.begin(), expected.end());
	sort(res.begin(), res.end());

	ASSERT_TRUE((res == expected));
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
