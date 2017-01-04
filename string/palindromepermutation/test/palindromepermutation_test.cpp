/* googletest unit test for C++ */

#include "gtest/gtest.h"

#include <iostream>
#include <vector>
#include <string>
#include <random>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

/*
#include <array>
#include <forward_list>
#include <list>
#include <deque>
#include <set>    // multiset is also defined here
#include <map>    // multimap is also defined here
#include <unordered_set>  // unordered_multiset is also defined here
#include <unordered_map>  // unordered_multimap is also defined here
*/

/*
 * stack          - use standard containers std::vector, std::deque and std::list
 * queue          - use standard containers std::deque and std::list
 * priority_queue - use standard containers std::vector and std::deque
 * */
/*
#include <stack>       // stack
#include <queue>       // queue + priority_queue
#include <algorithm>
#include <random>
#include <string>
#include <memory>
#include <random>
*/

/*
// hackerrank header
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// UVA header examples
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
//#define INT_MAX 2147483647
//#define INT_MIN -2147483648
//#define pi acos(-1.0)
//#define E 2.71828182845904523536
*/

using namespace std;

#include "../src/palindromepermutation.h"

/*
 Choose auto x when you want to work with copies.
 Choose auto &x when you want to work with original items and may modify them.
 Choose auto const &x when you want to work with original items and will not modify them
 */
template<class T>
void PrintVector(const vector<T> &vec)
{
	for (auto const &v : vec)
		cout << setw(3) << v << ' ';
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

static int getRandom(int lower, int upper)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(lower, upper);
	return dist(gen);
}

// first way to generate random string of len
string getRandomString(int len)
{
	string str(len, ' ');
	for (int i = 0; i < len; ++i) {
		int randchar =
				getRandom(0, std::numeric_limits<int>::max()) % (26 + 26 + 10);
		if (randchar < 26) {
			str[i] = 'a' + randchar;
		} else if (randchar < 26 + 26) {
			str[i] = 'A' + randchar - 26;
		} else {
			str[i] = '0' + randchar - 26 - 26;
		}
	}

	return str;
}

// second way to generate random string of len
string gen_random(const int len)
{
	static const char alphanum[] = "0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";

	string str(len, ' ');
	for (int i = 0; i < len; ++i) {
		str[i] =
				alphanum[getRandom(0, std::numeric_limits<int>::max()) % (sizeof(alphanum) - 1)];
	}

	return str;
}

TEST(palindromepermutation, normal1)
{
	palindromepermutation tc;

	string s = "code";
	ASSERT_FALSE(tc.canPermutePalindrome(s));

	s = "aab";
	ASSERT_TRUE(tc.canPermutePalindrome(s));

	s = "carerac";
	ASSERT_TRUE(tc.canPermutePalindrome(s));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
