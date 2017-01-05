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


#include "finddifference.h"


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

TEST(finddifference, normal1)
{
	finddifference<string, char> tc;

	string s = "abcde";
	string r = "abcdef";

	ASSERT_EQ('f', tc.findoneletterdifference(s, r));
}

TEST(finddifference, normal2)
{
	finddifference<string, char> tc;

	string s = "abcde";
	string r = s;

	// generate randome number between 0 and 100
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<uint32_t> dist(0, 100);
	int pos = dist(gen);
	std::sort(r.begin(), r.end());
	int k = 0;
	do {    // randomly choose one permutation
		if(++k > pos) break;
	} while (std::next_permutation(r.begin(), r.end()));

	// generate random position
	std::uniform_int_distribution<> dist2(0, r.size()-1);
	int pos2 = dist2(gen);

	/* random letter */
	std::uniform_int_distribution<> dist3(0, 25);
	int pos3 = dist3(gen);
	char rand_char = 'a'+pos3;
	r.insert(pos2, 1, rand_char);
	ASSERT_EQ(rand_char, tc.findoneletterdifference(s, r));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
