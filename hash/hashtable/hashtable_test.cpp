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
#include <random>

using namespace std;

#include "hashtable.h"

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

// Example of using hash function
// http://en.cppreference.com/w/cpp/utility/hash
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>

struct S
{
	std::string first_name;
	std::string last_name;
};

bool operator==(const S& lhs, const S& rhs)
{
	return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
}

// custom hash can be a standalone function object:
struct MyHash
{
	std::size_t operator()(S const& s) const
	{
		std::size_t h1 = std::hash<std::string> { }(s.first_name);
		std::size_t h2 = std::hash<std::string> { }(s.last_name);
		return h1 ^ (h2 << 1); // or use boost::hash_combine
	}
};

// custom specialization of std::hash can be injected in namespace std
namespace std
{
template<> struct hash<S>
{
	typedef S argument_type;
	typedef std::size_t result_type;
	result_type operator()(argument_type const& s) const
	{
		result_type const h1(std::hash<std::string> { }(s.first_name));
		result_type const h2(std::hash<std::string> { }(s.last_name));
		return h1 ^ (h2 << 1); // or use boost::hash_combine
	}
};
}

int hash(const std::string &key)
{
	unsigned int hash_val = 0;

	// method 1
	for (auto a : key) {
		hash_val = 37 * hash_val + a;
	}
	std::cout << "hash(" << key << ") = " << hash_val << '\n';

	// method 2
	std::size_t str_hash = std::hash<std::string> { }(key);
	std::cout << "hash(" << key << ") = " << str_hash << '\n';

	// method 3   -- combined hash
	S obj = { "Hubert", "Farnsworth" };
	// using the standalone function object
	std::cout << "hash(" << obj.first_name << ',' << obj.last_name << ") = "
			<< MyHash { }(obj)
			<< " (using MyHash)\n                           or "
			<< std::hash<S> { }(obj) << " (using std::hash) " << '\n';

	//method 4
	// custom hash makes it possible to use custom types in unordered containers
	// The example will use the injected std::hash specialization,
	// to use MyHash instead, pass it as a second template argument
	std::unordered_set<S> names = { obj, { "Bender", "Rodriguez" }, { "Leela",
			"Turanga" } };
	for (auto& s : names)
		std::cout << s.first_name << ' ' << s.last_name << '\n';

	return hash_val;
}

TEST(hashtable, normal1)
{
	HashTable<string> tc;
	string s = "sdfsdf";
	tc.insert(s);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
