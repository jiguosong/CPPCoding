/*




 */

#include "sortcharsbyfrequency.h"

#include <queue>
#include <unordered_map>

using std::priority_queue;
using std::unordered_map;

void sortcharsbyfrequency::dummy()
{
}

string sortcharsbyfrequency::SortCharactersbyFrequency(string &str)
{
	unordered_map<char, int> map;
	for(auto c:str) ++map[c];

	priority_queue<std::pair<int, char>> heap;
	for(auto it = map.begin(); it != map.end(); it++) {
		//heap.push(std::make_pair(it->second, it->first));
		heap.push({it->second, it->first});
	}

	string res = "";
	while(!heap.empty()) {
		char c = heap.top().second;
		int t = heap.top().first;
		while(t--) res.push_back(c);
		heap.pop();
	}

	return res;

}
