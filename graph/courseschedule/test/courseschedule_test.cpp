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

#include "../src/courseschedule.h"
#include "Graph.h"

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

TEST(courseschedule, normal1)
{
	courseschedule tc;

	int numCourses = 2;
	vector<vector<int>> prerequisite = {{1, 0}};
	ASSERT_TRUE(tc.canFinish(numCourses, prerequisite));

	/*
	 Graph g;
	 Vertex v2 { "2" };
	 Vertex v3 { "3" };
	 Vertex v5 { "5" };
	 Vertex v7 { "7" };
	 Vertex v8 { "8" };
	 Vertex v9 { "9" };
	 Vertex v10 { "10" };
	 Vertex v11 { "11" };

	 g.addEdge(&v7, &v11);
	 g.addEdge(&v7, &v8);
	 g.addEdge(&v5, &v11);
	 g.addEdge(&v3, &v8);
	 g.addEdge(&v3, &v10);
	 g.addEdge(&v8, &v9);
	 g.addEdge(&v11, &v9);
	 g.addEdge(&v9, &v2);

	 std::cout << "adjacency list:\n";
	 for (auto& pair : g.adjacencyList()) {
	 std::cout << pair.first->name() << ": ";
	 for (const Vertex* neighbour : pair.second)
	 std::cout << neighbour->name() << ", ";
	 std::cout << '\n';
	 }

	 std::cout << "indegrees:\n";
	 for (auto& pair : g.indegrees())
	 std::cout << pair.first->name() << ": " << pair.second << '\n';

	 std::cout << "topoSort:\n";
	 for (Vertex* v : g.topoSort())
	 std::cout << v->name() << ", ";
	 std::cout << '\n';

	 // add cycle
	 g.addEdge(&v9, &v3);
	 try {
	 g.topoSort();
	 } catch (const std::exception& e) {
	 std::cerr << e.what() << std::endl;
	 }
	 */
}

TEST(courseschedule, normal2)
{
	courseschedule tc;

	int numCourses = 2;
	vector<vector<int>> prerequisite = {{1, 0}, {0, 1}};
	ASSERT_FALSE(tc.canFinish(numCourses, prerequisite));

}


TEST(courseschedule, normal3)
{
	courseschedule tc;

	int numCourses = 5;
	vector<vector<int>> prerequisite = {{1, 0}, {0, 1}, {3,4}, {3, 1}, {4,2}, {1, 4}};
	ASSERT_FALSE(tc.canFinish(numCourses, prerequisite));

}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
