#ifndef finddifference_H_
#define finddifference_H_

#include <unordered_map>
#include <iostream>

#include <string>
#include <vector>
using std::vector;
using std::string;

template<class T, class K>
class finddifference {
public:
	K findoneletterdifference(T &s, T &r);
private:
};

template<class T, class K>
K finddifference<T,K>::findoneletterdifference(T &s, T &r)
{
	if(s.size() + 1 != r.size()) return ' ';

	std::unordered_map<K, int> map;

	for(K c : s) ++map[c];
	for(K c : r) {
		--map[c];
		if(map[c] < 0) return c;
	}

	return ' ';
}


#endif
