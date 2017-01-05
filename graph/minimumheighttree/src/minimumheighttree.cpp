/*For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

 Format
 The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

 You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

 Example 1:

 Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

 0
 |
 1
 / \
      2   3

 return [1]

 Example 2:

 Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

 0  1  2
 \ | /
 3
 |
 4
 |
 5

 return [3, 4]*/

#include "minimumheighttree.h"

#include <unordered_set>
#include <queue>

void minimumheighttree::dummy()
{
}

std::vector<int> minimumheighttree::findMinHeightTrees(int n,
		std::vector<std::pair<int, int> >& edges)
{
	std::vector<std::unordered_set<int>> graph(n);

	for (auto e : edges) {
		graph[e.first].insert(e.second);
		graph[e.second].insert(e.first);
	}

	std::queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (graph[i].size() == 1)
			q.push(i);
	}

	while (n > 2) {
		int size = q.size();
		n -= size;
		for (int i = 0; i < size; ++i) {
			int t = q.front();
			q.pop();
			for (auto a : graph[t]) {
				graph[a].erase(t);
				if (graph[a].size() == 1)   /// there are some issue here:: what if the graph is meshed??
					q.push(a);
			}
		}
	}

	std::vector<int> res;
	while(!q.empty()) {
		res.push_back(q.front());
		q.pop();
	}

	return res;
}
