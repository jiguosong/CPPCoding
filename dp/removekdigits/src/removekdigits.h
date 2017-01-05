#ifndef removekdigits_H_
#define removekdigits_H_

#include <vector>
using std::vector;

#include <string>
using std::string;

class removekdigits {
public:
	string removeKdigits(string num, int k);

	template<typename T, typename N>
	T removeKdigits2(T num, N k);

};

#endif
