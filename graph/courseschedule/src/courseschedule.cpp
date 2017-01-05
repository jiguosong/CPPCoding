/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

#include "courseschedule.h"
#include <queue>

void courseschedule::dummy()
{
}

bool courseschedule::canFinish(int numCourses,
		vector<vector<int>>& prerequisites)
{
	std::vector<std::vector<int> > graph(numCourses, std::vector<int>(0));
	std::vector<int> in_degree(numCourses, 0);

	for (auto a : prerequisites) {
		graph[a[1]].push_back(a[0]);
		++in_degree[a[0]];
	}

	std::queue<int> queue;

	for (int i = 0; i < numCourses; ++i) {
		if (in_degree[i] == 0)
			queue.push(i);
	}

	while (!queue.empty()) {
		int t = queue.front();
		queue.pop();
		for (auto a : graph[t]) {
			--in_degree[a];
			if (in_degree[a] == 0)
				queue.push(a);
		}
	}

	for (int i = 0; i < numCourses; ++i) {
		if(in_degree[i] != 0) return false;
	}

	return true;

}
