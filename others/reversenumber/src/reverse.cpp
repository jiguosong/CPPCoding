/*
 * reverse_int.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <limits>
#include <bitset>
#include <memory>

using namespace std;

class reverse {
public:
	virtual void run() = 0;
	virtual ~reverse(){};
};

class reverse_numer : public reverse {
public:
	void run() override
	{
		cout << endl;
		int ans = reverse(1000000009);
		cout << ans << endl;
		ans = reverse(12345);
		cout << ans;
	}

	static reverse_numer &instance() {
		static reverse_numer *p = new reverse_numer;
		return *p;
	}

	~reverse_numer(){};
private:
	reverse_numer(){};
	reverse_numer(const reverse_numer &other){};
	const reverse_numer &operator=(const reverse_numer &other);
	int reverse(int x);
};

int reverse_numer::reverse(int x) {  // signed int, can be negative
	int res = 0;

	while(x) {
		if(abs(x) > numeric_limits<int>::max()/10) return 0;
		res = res*10 + x%10;
		x = x/10;
	}

	return res;
}


class reverse_words : public reverse {
public:
	void run() override
	{
		cout << endl;
		string s = "   the sky   is blue   ";
		cout << s << endl;
		reverseWords(s);
		cout << s << endl;
	}

	static reverse_words &instance() {
		reverse_words *p = new reverse_words;
		return *p;
	}

	~reverse_words(){};
private:
	reverse_words(){};
	reverse_words(const reverse_words &other){};
	const reverse_words &operator=(const reverse_words &other);
	void reverseWords(string &s);
	void reverse_helper(string &s, int i, int j);
};

//For example, Given s = "the sky is blue", return "blue is sky the".
void reverse_words::reverseWords(string &s)
{
	if(s.size() == 0) return;

	int j = 0;
	int i = 0;
	bool need_space = false;
	while(1) {
		while(i < s.size() && s[i] == ' ') ++i;
		if(i == s.size()) break;
		if(need_space) s[j++] = ' ';
		int tmp = j;
		while(i < s.size() && s[i] != ' ') {
			s[j] = s[i];
			++j; ++i;
		}
		reverse_helper(s, tmp, j-1);
		need_space = true;
	}
	s.resize(j);
	reverse_helper(s, 0, j-1);
}

void reverse_words::reverse_helper(string &s, int i, int j)
{
	while(i < j) {
		char tmp = s[i];
		s[i++] = s[j];
		s[j--] = tmp;
	}
}

class reverse_bits : public reverse {
public:
	void run() override
	{
		cout << endl;
		int k = 123;
		cout << bitset<32> (k) << endl;
		int ans = reverseBits(k);
		cout << bitset<32> (ans) << endl;
	}

	static reverse_bits &instance() {
		reverse_bits *p = new reverse_bits;
		//unique_ptr<reverse_bits> p2 (p);
		return *p;
	}

	~reverse_bits(){};
private:
	reverse_bits(){};
	reverse_bits(const reverse_bits &other){};
	const reverse_bits &operator=(const reverse_bits &other);
	uint32_t reverseBits(uint32_t n);
};

uint32_t reverse_bits::reverseBits(uint32_t n)
{
	uint32_t res = 0;

	for(int i = 0; i < 32; ++i) {
		int k = n & 1;
		res = (res << 1) + k;
		n = n >> 1;
	}
	return res;
}


class reverse_solution_factory {
public:
	static reverse *solve(const string &name)
	{
		if(name == "number") {
			reverse &p = reverse_numer::instance();
			return &p;
		}

		if(name == "reverser words") {
			reverse &p = reverse_words::instance();
			return &p;
		}

		if(name == "reverser bits") {
			reverse &p = reverse_bits::instance();
			return &p;
		}

		return nullptr;
	}
};

int main() {
	reverse_solution_factory test;
	test.solve("number")->run();
	test.solve("reverser words")->run();
	test.solve("reverser bits")->run();

}
