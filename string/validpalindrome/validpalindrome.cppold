/*
 * validpalindrome.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: songjiguo
 */
/*static __inline__ unsigned long long rdtsc(void){
  unsigned long long int x;
  __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
  return x;
}*/


using namespace std;
#include <iostream>

/*container lib*/
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

class validPalindromeStr{
private:
	bool isNum(char c);
	bool isAlpha(char &c);
public:
	bool isValidPalindromeStr(string s);
};

bool validPalindromeStr::isNum(char c) {
	if (c >= '0' && c <= '9') return true;
	return false;
}

bool validPalindromeStr::isAlpha(char &c) {
	if (c >= 'a' && c <= 'z') return true;
	if (c >= 'A' && c <= 'Z') {
		c = c - 'A' + 'a';
		return true;
	}
	return false;
}

bool validPalindromeStr::isValidPalindromeStr(string s){
	if (s.length() == 0) return true;

	int l = 0;
	int r = s.length()-1;

	while(l < r) {

		while (!isNum(s[l]) && !isAlpha(s[l])) l++;
		while (!isNum(s[r]) && !isAlpha(s[r])) r--;
		if (s[l] != s[r]) return false;
		l++;
		r--;
	}

	return true;
}


int main() {
	cout << "valid palindrome\n";
	validPalindromeStr test;

	bool res = test.isValidPalindromeStr("Red rum, sir, is murder");

	if(res) cout << "\nyes" << endl;
	else cout << "\nno" << endl;
}
